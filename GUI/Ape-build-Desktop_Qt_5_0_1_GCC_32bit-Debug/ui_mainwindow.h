/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *processTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *managementTab;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *managementSubTab;
    QWidget *generalTab;
    QWidget *memoryMapTab;
    QWidget *coreDumpTab;
    QWidget *sysinfoTab;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1121, 734);
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(true);
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMouseTracking(true);
        tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        processTab = new QWidget();
        processTab->setObjectName(QStringLiteral("processTab"));
        processTab->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(processTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(processTab);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMouseTracking(true);
        tableWidget->setFocusPolicy(Qt::ClickFocus);
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setAutoScroll(false);
        tableWidget->setAutoScrollMargin(0);
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(12);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setMinimumSectionSize(16);

        verticalLayout_2->addWidget(tableWidget);

        tabWidget->addTab(processTab, QString());
        managementTab = new QWidget();
        managementTab->setObjectName(QStringLiteral("managementTab"));
        managementTab->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(managementTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        managementSubTab = new QTabWidget(managementTab);
        managementSubTab->setObjectName(QStringLiteral("managementSubTab"));
        generalTab = new QWidget();
        generalTab->setObjectName(QStringLiteral("generalTab"));
        managementSubTab->addTab(generalTab, QString());
        memoryMapTab = new QWidget();
        memoryMapTab->setObjectName(QStringLiteral("memoryMapTab"));
        managementSubTab->addTab(memoryMapTab, QString());
        coreDumpTab = new QWidget();
        coreDumpTab->setObjectName(QStringLiteral("coreDumpTab"));
        managementSubTab->addTab(coreDumpTab, QString());

        verticalLayout_3->addWidget(managementSubTab);

        tabWidget->addTab(managementTab, QString());
        sysinfoTab = new QWidget();
        sysinfoTab->setObjectName(QStringLiteral("sysinfoTab"));
        tabWidget->addTab(sysinfoTab, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_4->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        managementSubTab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ape", 0));
        actionFile->setText(QApplication::translate("MainWindow", "File", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "User", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "PID", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "PPID", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "CPU", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "U_CPU", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "S_CPU", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "VSZ", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "RSS", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "TTY", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "STAT", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "START", 0));
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(processTab), QApplication::translate("MainWindow", "Processes", 0));
        managementSubTab->setTabText(managementSubTab->indexOf(generalTab), QApplication::translate("MainWindow", "General", 0));
        managementSubTab->setTabText(managementSubTab->indexOf(memoryMapTab), QApplication::translate("MainWindow", "Memory Map", 0));
        managementSubTab->setTabText(managementSubTab->indexOf(coreDumpTab), QApplication::translate("MainWindow", "Core Dump", 0));
        tabWidget->setTabText(tabWidget->indexOf(managementTab), QApplication::translate("MainWindow", "Management", 0));
        tabWidget->setTabText(tabWidget->indexOf(sysinfoTab), QApplication::translate("MainWindow", "System Information", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
