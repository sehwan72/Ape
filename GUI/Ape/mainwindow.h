#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/Ape.h"
#include "../../src/Process.h"
#include "../../src/Sys.h"
#include <QTimer>
#include <QMenu>
#include <QMessageBox>
#include <QTableWidget>
#include <QString>
#include <condition_variable>
#include <filesinusedialog.h>
#include <aboutdialog.h>
#include <math.h>
#include <time.h>
#include <asm/param.h>
#include <QPropertyAnimation>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int addLine(Process *, int);
    Ape *ape;
    void clearTable();

    
private:
    Ui::MainWindow *ui;    
    const char* itoa(int);
    QTimer *timer;
    SortBy sortSetting;
    bool sortReverse;
    void myUIInit();
    void colorRows();
    int getParentRow(int);
    Process *getProcessAtRow(int);
    Process *currentProcess;
    unsigned int currentPID;
    void setCurrentProcess(Process *);
    void resetCurrentProcess();
    void showFilesInUse();
    FilesInUseDialog filesInUseList;
    AboutDialog aboutApe;
    void showSysInfo();
    void updateInfoTab();
    void updateMemoryMap();
    QPropertyAnimation *cmdFrame;
    QShortcut *cmdShortcut;
    void updateStatusBar(char* message = "No process selected");

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void updateUI();    
    void showProcessContextMenu(const QPoint&);
    void sortTable(int);
    void doubleClicked(QTableWidgetItem *);
    void toggleCmd();
    void handleMenuBar(QAction*);

    void on_sigkillButton_clicked();
    void on_memmapButton_clicked();
    void on_sigintButton_clicked();
    void on_sigtermButton_clicked();
    void on_sigstopButton_clicked();
    void on_sendsigButton_clicked();
    void on_coredumpButton_clicked();
};

#endif // MAINWINDOW_H
