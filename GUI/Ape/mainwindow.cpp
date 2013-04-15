#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ape = new Ape();

    ui->setupUi(this);

    sortSetting = PID;
    sortReverse = true;

    myUIInit();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUI()));

    connect(this->ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showProcessContextMenu(const QPoint&)));
    connect(this->ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortTable(int)));
    connect(this->ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(doubleClicked(QTableWidgetItem *)));

    updateUI();
    timer->start(1000);

    currentProcess = NULL;
    currentPID = 0;

    filesInUseList.setWindowFlags(Qt::WindowMinimizeButtonHint | Qt:: WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *evt) {
    Q_UNUSED(evt);
    filesInUseList.close();
}

void MainWindow::myUIInit()
{
    // Resize the Process Name tab to be wider
    QSize size = ui->tableWidget->horizontalHeaderItem(1)->sizeHint();
    size.setWidth(120);
    ui->tableWidget->horizontalHeaderItem(1)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(1);

    this->ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

}

void MainWindow::updateUI() {
    if (currentProcess != NULL) {
        bool alive = false;
        for (int i = 0; i < ape->processList.size(); i++) {
            if ((*(ape->processList[i]))->pid == currentPID) {
                alive = true;
                break;
            }
        }
        if (!alive) {
            resetCurrentProcess();
        }
    }

    ape->update();
    ape->sort(sortSetting);    

    ui->tableWidget->setRowCount(ape->processList.size());
    for (int i = 0; i < ape->processList.size(); i++) {
        if (!sortReverse) {
            addLine((*(ape->processList[i])), i);
        } else {
            addLine((*(ape->processList[ape->processList.size() - 1 - i])), i);
        }
    }
    if (sortSetting == PPID) colorRows();
    ui->tableWidget->update();

    if (currentPID != 0) {
        //ui->plabel->setText(currentProcess->getStatPtr()->name);
    }
}

int MainWindow::addLine(Process *p, int currRow) {
    stat_t *stat = p->getStatPtr();

    int i = 0;

    QTableWidgetItem *qi = new QTableWidgetItem();

    //Set the user column
    qi->setData(Qt::DisplayRole, p->getStatusPtr()->username);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the process name column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, stat->name);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the process id column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, stat->pid);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the parent process id column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, stat->ppid);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the total cpu column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, p->u_cpu + p->s_cpu);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the u_cpu column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, p->u_cpu);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the s_cpu column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, p->s_cpu);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the vsz column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, (qulonglong)stat->vss);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the rss column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, (qulonglong)stat->rss);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the tty_nr column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, stat->tty_nr);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the state column
    qi = new QTableWidgetItem();
    std::string state(1, stat->state);
    qi->setData(Qt::DisplayRole, state.c_str());
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the process start time column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, (qulonglong)stat->start_time);
    ui->tableWidget->setItem(currRow, i++, qi);

    return currRow++;
}

const char* MainWindow::itoa(int val){
    if (val == 0) return "0";

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= 10)
        buf[i] = "0123456789abcdef"[val % 10];

    return &buf[i+1];
}

void MainWindow::clearTable() {
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        ui->tableWidget->removeRow(i);
    }
}

Process * MainWindow::getProcessAtRow(int row) {
    for (int i = 0; i < ape->processList.size(); i++) {
        if (ui->tableWidget->item(row, 2)->data(Qt::DisplayRole) == (*(ape->processList[i]))->getStatPtr()->pid) {
            return (*(ape->processList[i]));
        }
    }
}

void MainWindow::setCurrentProcess(Process* process) {
    currentProcess = process;
    currentPID = currentProcess->pid;
}

void MainWindow::resetCurrentProcess() {
    currentProcess = NULL;
    currentPID = 0;
}

void MainWindow::showProcessContextMenu(const QPoint &pos) {
    QPoint globalPos = ui->tableWidget->viewport()->mapToGlobal(pos);

    QMenu pcMenu;
    pcMenu.addAction("Kill");
    pcMenu.addAction("Stop");
    pcMenu.addAction("Terminate");
    pcMenu.addSeparator();
    pcMenu.addAction("Files In Use");
    pcMenu.addAction("Get General Information");
    pcMenu.addAction("Get Memory Map");
    pcMenu.addAction("Get Core Dump");

    for (int i = 0; i < ape->processList.size(); i++) {
        if (ui->tableWidget->item(ui->tableWidget->itemAt(pos)->row(), 2)->data(Qt::DisplayRole) == (*(ape->processList[i]))->getStatPtr()->pid) {
            setCurrentProcess(*(ape->processList[i]));
            break;
        }
    }

    QAction * action = pcMenu.exec(globalPos);
    if (action) {
        if (action->text() == "Kill")
        {
            char killString[100];
            sprintf(killString, "Are you sure you want to kill PID: %d ?", currentProcess->getStatPtr()->pid);

            QMessageBox killConfirm;
            killConfirm.setText(killString);
            killConfirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            killConfirm.setDefaultButton(QMessageBox::No);

            if (killConfirm.exec() == 0x00004000) {
                int result = currentProcess->sendSignal(9);
                resetCurrentProcess();
            }
        } else if (action->text() == "Stop") {

        } else if (action->text() == "Terminate") {

        } else if (action->text() == "Get General Information") {
            ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(0));
            ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
        } else if (action->text() == "Get General Information") {

        } else if (action->text() == "Get Memory Map") {

        } else if (action->text() == "Get Core Dump") {

        } else if (action->text() == "Files In Use") {
            showFilesInUse();
        }
    }
}

void MainWindow::showFilesInUse() {
    char title[100];
    sprintf(title, "Files in use by process %s (PID: %d)", currentProcess->getStatPtr()->name, currentPID);
    filesInUseList.setWindowTitle(title);

    std::vector<char *> listOfFiles;
    currentProcess->getOpenFiles(&listOfFiles);
    filesInUseList.setFilesList(listOfFiles);

    filesInUseList.show();
    filesInUseList.activateWindow();
}

void MainWindow::sortTable(int col) {
    switch (col) {
        case 2:
            sortSetting = PID;
            sortReverse = !sortReverse;
            break;
        case 3:
            sortSetting = PPID;
            sortReverse = false;
            updateUI();
            colorRows();
            break;
        case 4:
            sortSetting = CPU;
            sortReverse = !sortReverse;
            break;
    }
}

void MainWindow::colorRows() {

    QColor *colors = new QColor[6];
    int maxBright = 220;
    int minBright = 40;
    /*
    colors[0] = QColor(maxBright, minBright, minBright);      //Red
    colors[1] = QColor(minBright, maxBright, minBright);      //Green
    colors[2] = QColor(minBright, minBright, maxBright);      //Blue
    colors[3] = QColor(maxBright, maxBright, minBright);    //Yellow
    colors[4] = QColor(minBright, maxBright, maxBright);    //Cyan
    colors[5] = QColor(maxBright, minBright, maxBright);    //Magenta
    */

    colors[0] = QColor(119, 184, 207);
    colors[1] = QColor(227, 119, 194);
    //colors[0] = QColor(44, 160, 44);


    int ci = 27;                         // Color increment variable
    int nextColor = 0;
    float grayscale;
    int offset;

    // Do parents first
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i, 3)->data(Qt::DisplayRole).toInt() == 1) {
            // Is a child of init, color it a primary color
            for (int j = 1; j < ui->tableWidget->columnCount(); j++) {
                ui->tableWidget->item(i, j)->setBackground(QBrush(colors[nextColor]));

                offset = (colors[nextColor].red() == 31) ? 250 : 250;
                grayscale = offset - ((colors[nextColor].red() + colors[nextColor].blue() + colors[nextColor].green()) / 3);

                ui->tableWidget->item(i, j)->setTextColor(QColor((int)grayscale, (int)grayscale, (int)grayscale));
            }
            if (nextColor == 1) {
                nextColor = 0;
            } else {
               ++nextColor;
            }
        } else if (ui->tableWidget->item(i, 3)->data(Qt::DisplayRole).toInt() > 1) {
            //This process is a child of a process who's top level ancestor is init

            QColor parentColor = ui->tableWidget->item(getParentRow(i), 1)->background().color();
            parentColor.setAlpha(parentColor.alpha() - ci);
            for (int j = 1; j < ui->tableWidget->columnCount(); j++) {
                ui->tableWidget->item(i, j)->setBackground(QBrush(parentColor));

                offset = (parentColor.red() == 31) ? 250 : 250;
                grayscale = offset - (((parentColor.red() + parentColor.blue() + parentColor.green()) / 3)) * (1 - (parentColor.alpha() / 255));

                ui->tableWidget->item(i, j)->setTextColor(QColor((int)grayscale, (int)grayscale, (int)grayscale));
            }
        }
    }

    delete colors;
}

int MainWindow::getParentRow(int currRow) {
    int ppid = ui->tableWidget->item(currRow, 3)->data(Qt::DisplayRole).toInt();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i, 2)->data(Qt::DisplayRole).toInt() == ppid) {
            return i;
        }
    }
    return -1;
}

void MainWindow::doubleClicked(QTableWidgetItem *item) {
    for (int i = 0; i < ape->processList.size(); i++) {
        if (ui->tableWidget->item(item->row(), 2)->data(Qt::DisplayRole) == (*(ape->processList[i]))->getStatPtr()->pid) {
            setCurrentProcess(*(ape->processList[i]));
            break;
        }
    }

    //TODO: Add General Information Update Function Here

    ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(0));
    ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
}
