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
#include <condition_variable>
#include <filesinusedialog.h>

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

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void updateUI();    
    void showProcessContextMenu(const QPoint&);
    void sortTable(int);
    void doubleClicked(QTableWidgetItem *);

};

#endif // MAINWINDOW_H
