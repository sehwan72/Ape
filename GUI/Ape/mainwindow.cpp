#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ape = new Ape();

    ui->setupUi(this);

    currentProcess = NULL;
    currentPID = 0;

    sortSetting = PID;
    sortReverse = false;

    myUIInit();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUI()));

    int animationDuration = 100;

    cmdFrame = new QPropertyAnimation(ui->commandFrame, "maximumHeight");
    cmdFrame->setDuration(animationDuration);

    cmdShortcut = new QShortcut(QKeySequence("Ctrl+Alt+Shift+T"), this);

    connect(this->ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showProcessContextMenu(const QPoint&)));
    connect(this->ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortTable(int)));
    connect(this->ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(doubleClicked(QTableWidgetItem *)));
    connect(cmdShortcut, SIGNAL(activated()), this, SLOT(toggleCmd()));
    connect(this->ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(handleMenuBar(QAction*)));

    updateUI();
    timer->start(500);



    filesInUseList.setWindowFlags(Qt::WindowMinimizeButtonHint | Qt:: WindowCloseButtonHint);    

    updateInfoTab();
    showSysInfo();

    ui->commandFrame->setFixedHeight(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleCmd() {
    if (ui->commandFrame->height() == 0) {
        cmdFrame->setStartValue(0);
        cmdFrame->setEndValue(50);
    } else {
        cmdFrame->setStartValue(50);
        cmdFrame->setEndValue(0);
    }
    cmdFrame->start();
}

void MainWindow::updateInfoTab() {
    ui->resInUse->clear();
    if (currentPID == 0) {
        ui->procNameLabel->setText("");
        ui->pidLabel->setText("");
        ui->ppidLabel->setText("");
        ui->usernameLabel->setText("");
        ui->uidLabel->setText("");
        ui->gidLabel->setText("");
        ui->cpuLabel->setText("");
        ui->ucpuLabel->setText("");
        ui->scpuLabel->setText("");
        ui->stateLabel->setText("");
        ui->ttyLabel->setText("");
        ui->ttypgLabel->setText("");
        ui->flagLabel->setText("");
        ui->niceLabel->setText("");
        ui->prtyLabel->setText("");
        ui->nothLabel->setText("");
        ui->vszLabel->setText("");
        ui->rssLabel->setText("");
        ui->pgLabel->setText("");
        ui->sidLabel->setText("");
        ui->coredumpButton->setDisabled(true);
        ui->sigkillButton->setDisabled(true);
        ui->sigintButton->setDisabled(true);
        ui->sigstopButton->setDisabled(true);
        ui->sigtermButton->setDisabled(true);
        ui->memmapButton->setDisabled(true);
        ui->sendsigButton->setDisabled(true);
    } else {
        stat_t *st = currentProcess->getStatPtr();
        status_t *stat = currentProcess->getStatusPtr();

        ui->procNameLabel->setText(st->name);
        ui->pidLabel->setText(itoa(st->pid));
        ui->ppidLabel->setText(itoa(st->ppid));
        ui->usernameLabel->setText(stat->username);
        ui->uidLabel->setText(itoa(stat->uid));
        ui->gidLabel->setText(itoa(stat->gid));
        ui->cpuLabel->setText(itoa(currentProcess->u_cpu + currentProcess->s_cpu));

        if (currentProcess->u_cpu + currentProcess->s_cpu > 50)
            ui->cpuLabel->setStyleSheet("QLabel {color: red}");
        else
            ui->cpuLabel->setStyleSheet("QLabel {color: black}");

        ui->ucpuLabel->setText(itoa(currentProcess->u_cpu));
        if (currentProcess->u_cpu > 50)
            ui->ucpuLabel->setStyleSheet("QLabel {color: red}");
        else
            ui->ucpuLabel->setStyleSheet("QLabel {color: black}");

        ui->scpuLabel->setText(itoa(currentProcess->s_cpu));
        if (currentProcess->s_cpu > 50)
            ui->scpuLabel->setStyleSheet("QLabel {color: red}");
        else
            ui->scpuLabel->setStyleSheet("QLabel {color: black}");


        switch (st->state) {
            case 'R':
                ui->stateLabel->setText("Running");
                break;
            case 'S':
                ui->stateLabel->setText("Sleeping");
                break;
            case 'D':
                ui->stateLabel->setText("Waiting on Disk");
                break;
            case 'Z':
                ui->stateLabel->setText("Zombie");
                break;
            case 'T':
                ui->stateLabel->setText("Traced");
                break;
            case 'W':
                ui->stateLabel->setText("Paging");
                break;
        }


        ui->ttyLabel->setText(itoa(st->tty_nr));
        ui->ttypgLabel->setText(itoa(st->tty_pgrp));
        ui->flagLabel->setText(itoa(st->flags));
        ui->niceLabel->setText(itoa(st->niceness));
        ui->prtyLabel->setText(itoa(st->priority));
        ui->nothLabel->setText(itoa(st->threads));
        ui->vszLabel->setText(itoa(st->vss));
        ui->rssLabel->setText(itoa(st->rss));
        ui->pgLabel->setText(itoa(st->pgrp));
        ui->sidLabel->setText(itoa(st->sid));
        ui->coredumpButton->setEnabled(true);
        ui->sigkillButton->setEnabled(true);
        ui->sigintButton->setEnabled(true);
        ui->sigstopButton->setEnabled(true);
        ui->sigtermButton->setEnabled(true);
        ui->memmapButton->setEnabled(true);
        ui->sendsigButton->setEnabled(true);

        std::vector<char *> listOfFiles;
        int r = currentProcess->getOpenFiles(&listOfFiles);
        if (r != 0)
            ui->resInUse->addItem(new QListWidgetItem("Permission Denied"));
        else {
            for (int i = 0; i < listOfFiles.size(); i++) {
                ui->resInUse->addItem(new QListWidgetItem(listOfFiles[i]));
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *evt) {
    Q_UNUSED(evt);
    filesInUseList.close();
    aboutApe.close();
}

void MainWindow::showSysInfo() {
    char sysStr[20000];
    time_t time = (time_t)this->ape->system->btime;
    struct tm *timeS = localtime(&time);


    ui->sysinfoLabel->setTextFormat(Qt::PlainText);
    sprintf(sysStr, "Version:\n%s\n\n"
            "System Start Time: %02d:%02d:%02d\n\n\n"
            "Page Size: %lukb\n\n\n"
            "Total CPU Usage: %lu\n\n\n"
            "Alive Processes: %d\n\n\n"
            "Running Processes: %lu\n\n\n"
            "Blocked Processes: %lu",
            this->ape->system->version,
            timeS->tm_hour,
            timeS->tm_min,
            timeS->tm_sec,
            this->ape->system->pageSize,
            this->ape->system->totalCPU,
            this->ape->processList.size(),
            this->ape->system->runningProcesses,
            this->ape->system->blockedProcesses
            );
    ui->sysinfoLabel->setText(sysStr);
}

void MainWindow::myUIInit()
{
    // Resize the Process Name tab to be wider
    QSize size = ui->tableWidget->horizontalHeaderItem(1)->sizeHint();
    size.setWidth(120);
    ui->tableWidget->horizontalHeaderItem(1)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(1);

    size.setWidth(80);
    ui->tableWidget->horizontalHeaderItem(2)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(2);

    ui->tableWidget->horizontalHeaderItem(3)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(3);


    size.setWidth(60);
    ui->tableWidget->horizontalHeaderItem(4)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(4);

    ui->tableWidget->horizontalHeaderItem(5)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(5);

    ui->tableWidget->horizontalHeaderItem(6)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(6);

    ui->tableWidget->horizontalHeaderItem(10)->setSizeHint(size);
    ui->tableWidget->resizeColumnToContents(10);

    this->ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    updateStatusBar();
}

void MainWindow::updateStatusBar(char* message) {
    if (currentPID == 0)
        ui->statusBar->showMessage(message);
    else {
        char msg[255];
        sprintf(msg, "Process: %s  PID:  %d  User: %s",
                currentProcess->getStatPtr()->name,
                currentProcess->getStatPtr()->pid,
                currentProcess->getStatusPtr()->username
                );
        ui->statusBar->showMessage(msg);
    }
}

void MainWindow::updateUI() {    
    updateInfoTab();
    showSysInfo();
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
    qi->setData(Qt::DisplayRole, (qulonglong)stat->vss / 1024);
    ui->tableWidget->setItem(currRow, i++, qi);

    //Set the rss column
    qi = new QTableWidgetItem();
    qi->setData(Qt::DisplayRole, (qulonglong)stat->rss / 1024);
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

    time_t time = (time_t)((stat->start_time / HZ));
    struct tm *t = gmtime(&time);
    char timeString[255];
    strftime(timeString, 255, "%T", t);

    qi->setData(Qt::DisplayRole, timeString);
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

void MainWindow::updateMemoryMap() {
    char memoryMap[1024 * 100];
    currentProcess->getMemoryMap(memoryMap, sizeof(char) * 1024 * 100);
    if (memoryMap[0] == NULL) {
        ui->memoryMapLabel->setText("Permission denied");
    } else {
        ui->memoryMapLabel->setText(memoryMap);
    }
}

void MainWindow::setCurrentProcess(Process* process) {
    currentProcess = process;
    currentPID = currentProcess->pid;
}

void MainWindow::resetCurrentProcess() {
    currentProcess = NULL;
    currentPID = 0;
    updateStatusBar();
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

    for (int i = 0; i < ape->processList.size(); i++) {
        if (ui->tableWidget->item(ui->tableWidget->itemAt(pos)->row(), 2)->data(Qt::DisplayRole) == (*(ape->processList[i]))->getStatPtr()->pid) {
            setCurrentProcess(*(ape->processList[i]));
            break;
        }
    }

    if (currentProcess->getStatusPtr()->uid != getuid()) {
        pcMenu.actions()[0]->setDisabled(true);
        pcMenu.actions()[3]->setDisabled(true);
        pcMenu.actions()[5]->setDisabled(true);
        pcMenu.actions()[6]->setDisabled(true);
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
                int r = currentProcess->sendSignal(9);
                if (r != 0) return;
                resetCurrentProcess();
            }
        } else if (action->text() == "Stop") {
            int r = currentProcess->sendSignal(19);

        } else if (action->text() == "Terminate") {
            int r = currentProcess->sendSignal(15);
            if (r == 0) resetCurrentProcess();

        } else if (action->text() == "Get General Information") {
            ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(0));
            ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
        } else if (action->text() == "Get Memory Map") {
            updateMemoryMap();
            ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(1));
            ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
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
        case 0:
            sortSetting = USER;
            sortReverse = !sortReverse;
            break;
        case 1:
            sortSetting = NAME;
            sortReverse = !sortReverse;
            break;
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
        case 5:
            sortSetting = UCPU;
            sortReverse = !sortReverse;
            break;
        case 6:
            sortSetting = SCPU;
            sortReverse = !sortReverse;
            break;
        case 7:
            sortSetting = VSZ;
            sortReverse = !sortReverse;
            break;
        case 8:
            sortSetting = RSS;
            sortReverse = !sortReverse;
            break;
        case 9:
            sortSetting = TTY;
            sortReverse = !sortReverse;
            break;
        case 10:
            sortSetting = STATE;
            sortReverse = !sortReverse;
            break;
        case 11:
            sortSetting = START;
            sortReverse = !sortReverse;
            break;
    }
}

void MainWindow::colorRows() {

    QColor *colors = new QColor[6];

    colors[0] = QColor(119, 184, 207);
    colors[1] = QColor(227, 119, 194);

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

    updateStatusBar();

    updateMemoryMap();
    updateInfoTab();

    ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(0));
    ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
}

void MainWindow::on_sigkillButton_clicked()
{
    int r = currentProcess->sendSignal(9);
    if (r != 0) return;
    resetCurrentProcess();
    updateInfoTab();
}

void MainWindow::on_memmapButton_clicked()
{
    ui->managementSubTab->setCurrentWidget(ui->managementSubTab->widget(1));
    ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(1));
}

void MainWindow::on_sigintButton_clicked()
{
    int r = currentProcess->sendSignal(2);
    if (r != 0) return;
    updateInfoTab();
}

void MainWindow::on_sigtermButton_clicked()
{
    int r = currentProcess->sendSignal(15);
    if (r == 0) resetCurrentProcess();
    updateInfoTab();
}

void MainWindow::on_sigstopButton_clicked()
{
    int r = currentProcess->sendSignal(19);
    if (r != 0) return;
    updateInfoTab();
}

void MainWindow::on_sendsigButton_clicked()
{
    int signal = ui->sigText->text().toInt();
    // 0 means toInt() failed
    if (signal > 0 && signal <= 31) {
        int r = currentProcess->sendSignal(signal);
        if (r == 0 && (signal == 3 || signal == 9 || signal == 15)) {
            resetCurrentProcess();
        }
    } else {
        QMessageBox invalidSig;
        invalidSig.setWindowTitle("Invalid Signal");
        invalidSig.setText("Invalid Signal!");
        invalidSig.exec();
    }
    ui->sigText->clear();
    updateInfoTab();
}

void MainWindow::on_coredumpButton_clicked()
{
    int r = currentProcess->sendSignal(11);
    if (r != 0) return;
    resetCurrentProcess();
    updateInfoTab();
}

void MainWindow::handleMenuBar(QAction* action) {
    if (action->text() == "About Ape") {
        aboutApe.show();
        return;
    }
}
