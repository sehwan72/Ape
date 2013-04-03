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
#include <condition_variable>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int addLine(Process *);
    Ape *ape;
    void clearTable();

    
private:
    Ui::MainWindow *ui;    
    const char* itoa(int);

private slots:
    void updateUI();

};

#endif // MAINWINDOW_H
