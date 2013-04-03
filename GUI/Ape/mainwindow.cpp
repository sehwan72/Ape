#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ape = new Ape();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUI()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI() {
    clearTable();
    ape->update();
    for (int i = 0; i < ape->processList.size(); i++) {
        addLine((*(ape->processList[i])));
    }
}

int MainWindow::addLine(Process *p) {
    static int currRow = 0;
    ui->tableWidget->setRowCount(currRow + 1);

    stat_t *stat = p->getStatPtr();

    ui->tableWidget->setItem(currRow, 0, new QTableWidgetItem("sehwan"));
    ui->tableWidget->setItem(currRow, 1, new QTableWidgetItem(stat->name));
    ui->tableWidget->setItem(currRow, 2, new QTableWidgetItem(itoa(stat->pid)));
    ui->tableWidget->setItem(currRow, 3, new QTableWidgetItem(itoa(p->u_cpu)));
    ui->tableWidget->setItem(currRow, 4, new QTableWidgetItem(itoa(p->s_cpu)));
    ui->tableWidget->setItem(currRow, 5, new QTableWidgetItem(itoa(stat->vss)));
    ui->tableWidget->setItem(currRow, 6, new QTableWidgetItem(itoa(stat->rss)));
    ui->tableWidget->setItem(currRow, 7, new QTableWidgetItem(itoa(stat->tty_nr)));
    char *state = (char*)malloc(sizeof(char));
    state[0] = stat->state;
    state[1] = NULL;
    ui->tableWidget->setItem(currRow, 8, new QTableWidgetItem(state));
    delete state;
    ui->tableWidget->setItem(currRow, 9, new QTableWidgetItem(itoa(stat->start_time)));
    ui->tableWidget->update();

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
    for (int i = ui->tableWidget->rowCount() - 1; i >= 0; i++) {
        ui->tableWidget->removeRow(i);
    }
}
