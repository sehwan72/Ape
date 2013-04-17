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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionShow_Command_Bar;
    QAction *actionAbout_Ape;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *processTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *managementTab;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *managementSubTab;
    QWidget *generalTab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QFrame *line;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *procNameLabel;
    QLabel *pidLabel;
    QLabel *ppidLabel;
    QLabel *usernameLabel;
    QLabel *uidLabel;
    QLabel *cpuLabel;
    QLabel *ucpuLabel;
    QLabel *gidLabel;
    QLabel *scpuLabel;
    QLabel *stateLabel;
    QLabel *ttyLabel;
    QLabel *pgLabel;
    QLabel *sidLabel;
    QLabel *nothLabel;
    QLabel *vszLabel;
    QLabel *flagLabel;
    QLabel *niceLabel;
    QLabel *prtyLabel;
    QLabel *rssLabel;
    QLabel *ttypgLabel;
    QPushButton *sigkillButton;
    QPushButton *sigintButton;
    QPushButton *sigtermButton;
    QPushButton *sigstopButton;
    QPushButton *sendsigButton;
    QPushButton *coredumpButton;
    QPushButton *memmapButton;
    QListWidget *resInUse;
    QLabel *label_23;
    QLineEdit *sigText;
    QWidget *memoryMapTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *memoryMapLabel;
    QWidget *sysinfoTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *sysinfoLabel;
    QFrame *commandFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *commandLabel;
    QLineEdit *commandBox;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1033, 780);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1033, 780));
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        actionShow_Command_Bar = new QAction(MainWindow);
        actionShow_Command_Bar->setObjectName(QStringLiteral("actionShow_Command_Bar"));
        actionShow_Command_Bar->setCheckable(false);
        actionShow_Command_Bar->setShortcutContext(Qt::WindowShortcut);
        actionShow_Command_Bar->setIconVisibleInMenu(true);
        actionAbout_Ape = new QAction(MainWindow);
        actionAbout_Ape->setObjectName(QStringLiteral("actionAbout_Ape"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
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
        label = new QLabel(generalTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 101, 17));
        label_2 = new QLabel(generalTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 81, 17));
        label_3 = new QLabel(generalTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 131, 17));
        label_4 = new QLabel(generalTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 230, 81, 17));
        label_5 = new QLabel(generalTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 260, 71, 17));
        label_6 = new QLabel(generalTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 290, 91, 17));
        label_7 = new QLabel(generalTab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 320, 101, 17));
        label_8 = new QLabel(generalTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(500, 290, 111, 17));
        label_9 = new QLabel(generalTab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(500, 170, 67, 17));
        label_10 = new QLabel(generalTab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(500, 140, 71, 17));
        label_11 = new QLabel(generalTab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(500, 200, 141, 17));
        label_12 = new QLabel(generalTab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(500, 50, 31, 17));
        label_13 = new QLabel(generalTab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(500, 110, 41, 17));
        label_14 = new QLabel(generalTab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(500, 320, 81, 17));
        label_15 = new QLabel(generalTab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(500, 230, 161, 17));
        label_16 = new QLabel(generalTab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(500, 260, 171, 17));
        label_17 = new QLabel(generalTab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(500, 80, 131, 17));
        line = new QFrame(generalTab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 350, 961, 16));
        line->setBaseSize(QSize(0, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_18 = new QLabel(generalTab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 170, 61, 17));
        label_19 = new QLabel(generalTab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 200, 67, 17));
        label_20 = new QLabel(generalTab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 140, 71, 17));
        label_21 = new QLabel(generalTab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 10, 201, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_21->setFont(font);
        label_22 = new QLabel(generalTab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 370, 201, 17));
        label_22->setFont(font);
        procNameLabel = new QLabel(generalTab);
        procNameLabel->setObjectName(QStringLiteral("procNameLabel"));
        procNameLabel->setGeometry(QRect(160, 50, 250, 17));
        pidLabel = new QLabel(generalTab);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));
        pidLabel->setGeometry(QRect(160, 80, 250, 17));
        ppidLabel = new QLabel(generalTab);
        ppidLabel->setObjectName(QStringLiteral("ppidLabel"));
        ppidLabel->setGeometry(QRect(160, 110, 250, 17));
        usernameLabel = new QLabel(generalTab);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setGeometry(QRect(160, 140, 250, 17));
        uidLabel = new QLabel(generalTab);
        uidLabel->setObjectName(QStringLiteral("uidLabel"));
        uidLabel->setGeometry(QRect(160, 170, 250, 17));
        cpuLabel = new QLabel(generalTab);
        cpuLabel->setObjectName(QStringLiteral("cpuLabel"));
        cpuLabel->setGeometry(QRect(160, 230, 250, 17));
        ucpuLabel = new QLabel(generalTab);
        ucpuLabel->setObjectName(QStringLiteral("ucpuLabel"));
        ucpuLabel->setGeometry(QRect(160, 260, 250, 17));
        gidLabel = new QLabel(generalTab);
        gidLabel->setObjectName(QStringLiteral("gidLabel"));
        gidLabel->setGeometry(QRect(160, 200, 250, 17));
        scpuLabel = new QLabel(generalTab);
        scpuLabel->setObjectName(QStringLiteral("scpuLabel"));
        scpuLabel->setGeometry(QRect(160, 290, 250, 17));
        stateLabel = new QLabel(generalTab);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setGeometry(QRect(160, 320, 250, 17));
        ttyLabel = new QLabel(generalTab);
        ttyLabel->setObjectName(QStringLiteral("ttyLabel"));
        ttyLabel->setGeometry(QRect(700, 50, 250, 17));
        pgLabel = new QLabel(generalTab);
        pgLabel->setObjectName(QStringLiteral("pgLabel"));
        pgLabel->setGeometry(QRect(700, 290, 250, 17));
        sidLabel = new QLabel(generalTab);
        sidLabel->setObjectName(QStringLiteral("sidLabel"));
        sidLabel->setGeometry(QRect(700, 320, 250, 17));
        nothLabel = new QLabel(generalTab);
        nothLabel->setObjectName(QStringLiteral("nothLabel"));
        nothLabel->setGeometry(QRect(700, 200, 250, 17));
        vszLabel = new QLabel(generalTab);
        vszLabel->setObjectName(QStringLiteral("vszLabel"));
        vszLabel->setGeometry(QRect(700, 230, 250, 17));
        flagLabel = new QLabel(generalTab);
        flagLabel->setObjectName(QStringLiteral("flagLabel"));
        flagLabel->setGeometry(QRect(700, 110, 250, 17));
        niceLabel = new QLabel(generalTab);
        niceLabel->setObjectName(QStringLiteral("niceLabel"));
        niceLabel->setGeometry(QRect(700, 140, 250, 17));
        prtyLabel = new QLabel(generalTab);
        prtyLabel->setObjectName(QStringLiteral("prtyLabel"));
        prtyLabel->setGeometry(QRect(700, 170, 250, 17));
        rssLabel = new QLabel(generalTab);
        rssLabel->setObjectName(QStringLiteral("rssLabel"));
        rssLabel->setGeometry(QRect(700, 260, 250, 17));
        ttypgLabel = new QLabel(generalTab);
        ttypgLabel->setObjectName(QStringLiteral("ttypgLabel"));
        ttypgLabel->setGeometry(QRect(700, 80, 250, 17));
        sigkillButton = new QPushButton(generalTab);
        sigkillButton->setObjectName(QStringLiteral("sigkillButton"));
        sigkillButton->setGeometry(QRect(10, 400, 131, 27));
        sigintButton = new QPushButton(generalTab);
        sigintButton->setObjectName(QStringLiteral("sigintButton"));
        sigintButton->setGeometry(QRect(10, 440, 131, 27));
        sigtermButton = new QPushButton(generalTab);
        sigtermButton->setObjectName(QStringLiteral("sigtermButton"));
        sigtermButton->setGeometry(QRect(10, 480, 131, 27));
        sigstopButton = new QPushButton(generalTab);
        sigstopButton->setObjectName(QStringLiteral("sigstopButton"));
        sigstopButton->setGeometry(QRect(10, 520, 131, 27));
        sendsigButton = new QPushButton(generalTab);
        sendsigButton->setObjectName(QStringLiteral("sendsigButton"));
        sendsigButton->setGeometry(QRect(220, 400, 111, 27));
        coredumpButton = new QPushButton(generalTab);
        coredumpButton->setObjectName(QStringLiteral("coredumpButton"));
        coredumpButton->setGeometry(QRect(160, 520, 171, 27));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(212, 127, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        coredumpButton->setPalette(palette);
        memmapButton = new QPushButton(generalTab);
        memmapButton->setObjectName(QStringLiteral("memmapButton"));
        memmapButton->setGeometry(QRect(160, 440, 171, 27));
        resInUse = new QListWidget(generalTab);
        resInUse->setObjectName(QStringLiteral("resInUse"));
        resInUse->setGeometry(QRect(500, 400, 451, 141));
        label_23 = new QLabel(generalTab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(500, 370, 201, 17));
        label_23->setFont(font);
        sigText = new QLineEdit(generalTab);
        sigText->setObjectName(QStringLiteral("sigText"));
        sigText->setGeometry(QRect(160, 400, 51, 27));
        sigText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        managementSubTab->addTab(generalTab, QString());
        memoryMapTab = new QWidget();
        memoryMapTab->setObjectName(QStringLiteral("memoryMapTab"));
        verticalLayoutWidget_2 = new QWidget(memoryMapTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 971, 571));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        memoryMapLabel = new QTextBrowser(verticalLayoutWidget_2);
        memoryMapLabel->setObjectName(QStringLiteral("memoryMapLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Mono"));
        font1.setPointSize(12);
        memoryMapLabel->setFont(font1);

        verticalLayout_6->addWidget(memoryMapLabel);

        managementSubTab->addTab(memoryMapTab, QString());

        verticalLayout_3->addWidget(managementSubTab);

        tabWidget->addTab(managementTab, QString());
        sysinfoTab = new QWidget();
        sysinfoTab->setObjectName(QStringLiteral("sysinfoTab"));
        verticalLayoutWidget = new QWidget(sysinfoTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 991, 631));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        sysinfoLabel = new QLabel(verticalLayoutWidget);
        sysinfoLabel->setObjectName(QStringLiteral("sysinfoLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sysinfoLabel->sizePolicy().hasHeightForWidth());
        sysinfoLabel->setSizePolicy(sizePolicy3);
        sysinfoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        sysinfoLabel->setWordWrap(true);

        verticalLayout_5->addWidget(sysinfoLabel);

        tabWidget->addTab(sysinfoTab, QString());

        verticalLayout->addWidget(tabWidget);

        commandFrame = new QFrame(centralWidget);
        commandFrame->setObjectName(QStringLiteral("commandFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(commandFrame->sizePolicy().hasHeightForWidth());
        commandFrame->setSizePolicy(sizePolicy4);
        commandFrame->setLineWidth(0);
        verticalLayout_4 = new QVBoxLayout(commandFrame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        commandLabel = new QLabel(commandFrame);
        commandLabel->setObjectName(QStringLiteral("commandLabel"));

        verticalLayout_4->addWidget(commandLabel);

        commandBox = new QLineEdit(commandFrame);
        commandBox->setObjectName(QStringLiteral("commandBox"));

        verticalLayout_4->addWidget(commandBox);


        verticalLayout->addWidget(commandFrame);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font2;
        font2.setPointSize(10);
        statusBar->setFont(font2);
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1033, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuView->addAction(actionShow_Command_Bar);
        menuAbout->addAction(actionAbout_Ape);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        managementSubTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ape", 0));
        actionFile->setText(QApplication::translate("MainWindow", "File", 0));
        actionShow_Command_Bar->setText(QApplication::translate("MainWindow", "Show Command Bar", 0));
        actionShow_Command_Bar->setShortcut(QString());
        actionAbout_Ape->setText(QApplication::translate("MainWindow", "About Ape", 0));
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
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "UCPU", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "SCPU", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "VSZ (kb)", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "RSS (kb)", 0));
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
        label->setText(QApplication::translate("MainWindow", "Process Name:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Process ID:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Parent Process ID:", 0));
        label_4->setText(QApplication::translate("MainWindow", "CPU Usage:", 0));
        label_5->setText(QApplication::translate("MainWindow", "User CPU:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Kernel CPU:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Process State:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Process Group:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Priority:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Niceness:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Number of Threads:", 0));
        label_12->setText(QApplication::translate("MainWindow", "TTY:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Flags:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Session ID:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Virtual Memory Usage:", 0));
        label_16->setText(QApplication::translate("MainWindow", "Resident Memory Usage:", 0));
        label_17->setText(QApplication::translate("MainWindow", "TTY Process Group:", 0));
        label_18->setText(QApplication::translate("MainWindow", "User ID:", 0));
        label_19->setText(QApplication::translate("MainWindow", "Group ID:", 0));
        label_20->setText(QApplication::translate("MainWindow", "Username:", 0));
        label_21->setText(QApplication::translate("MainWindow", "Process Information", 0));
        label_22->setText(QApplication::translate("MainWindow", "Process Controls", 0));
        procNameLabel->setText(QApplication::translate("MainWindow", "PNAMEs", 0));
        pidLabel->setText(QApplication::translate("MainWindow", "PID", 0));
        ppidLabel->setText(QApplication::translate("MainWindow", "PPID", 0));
        usernameLabel->setText(QApplication::translate("MainWindow", "USRN", 0));
        uidLabel->setText(QApplication::translate("MainWindow", "UID", 0));
        cpuLabel->setText(QApplication::translate("MainWindow", "CPU", 0));
        ucpuLabel->setText(QApplication::translate("MainWindow", "UCPU", 0));
        gidLabel->setText(QApplication::translate("MainWindow", "GID", 0));
        scpuLabel->setText(QApplication::translate("MainWindow", "SCPU", 0));
        stateLabel->setText(QApplication::translate("MainWindow", "STATE", 0));
        ttyLabel->setText(QApplication::translate("MainWindow", "TTY", 0));
        pgLabel->setText(QApplication::translate("MainWindow", "PG", 0));
        sidLabel->setText(QApplication::translate("MainWindow", "SID", 0));
        nothLabel->setText(QApplication::translate("MainWindow", "NOTH", 0));
        vszLabel->setText(QApplication::translate("MainWindow", "VSZ", 0));
        flagLabel->setText(QApplication::translate("MainWindow", "FLAG", 0));
        niceLabel->setText(QApplication::translate("MainWindow", "NICE", 0));
        prtyLabel->setText(QApplication::translate("MainWindow", "PRTY", 0));
        rssLabel->setText(QApplication::translate("MainWindow", "RSS", 0));
        ttypgLabel->setText(QApplication::translate("MainWindow", "TTYPG", 0));
        sigkillButton->setText(QApplication::translate("MainWindow", "Send SIGKILL", 0));
        sigintButton->setText(QApplication::translate("MainWindow", "Send SIGINT", 0));
        sigtermButton->setText(QApplication::translate("MainWindow", "Send SIGTERM", 0));
        sigstopButton->setText(QApplication::translate("MainWindow", "Send SIGSTOP", 0));
        sendsigButton->setText(QApplication::translate("MainWindow", "Send Signal", 0));
        coredumpButton->setText(QApplication::translate("MainWindow", "Generate Core Dump", 0));
        memmapButton->setText(QApplication::translate("MainWindow", "View Memory Map", 0));
        label_23->setText(QApplication::translate("MainWindow", "Resources In Use", 0));
        managementSubTab->setTabText(managementSubTab->indexOf(generalTab), QApplication::translate("MainWindow", "General", 0));
        memoryMapLabel->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu Mono'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">No memory map to display</span></p></body></html>", 0));
        managementSubTab->setTabText(managementSubTab->indexOf(memoryMapTab), QApplication::translate("MainWindow", "Memory Map", 0));
        tabWidget->setTabText(tabWidget->indexOf(managementTab), QApplication::translate("MainWindow", "Management", 0));
        sysinfoLabel->setText(QApplication::translate("MainWindow", "System Information", 0));
        tabWidget->setTabText(tabWidget->indexOf(sysinfoTab), QApplication::translate("MainWindow", "System Information", 0));
        commandLabel->setText(QApplication::translate("MainWindow", "Command", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
