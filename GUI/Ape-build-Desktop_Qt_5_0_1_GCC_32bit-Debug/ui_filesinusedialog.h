/********************************************************************************
** Form generated from reading UI file 'filesinusedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESINUSEDIALOG_H
#define UI_FILESINUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilesInUseDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QDialog *FilesInUseDialog)
    {
        if (FilesInUseDialog->objectName().isEmpty())
            FilesInUseDialog->setObjectName(QStringLiteral("FilesInUseDialog"));
        FilesInUseDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(FilesInUseDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(FilesInUseDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FilesInUseDialog);

        QMetaObject::connectSlotsByName(FilesInUseDialog);
    } // setupUi

    void retranslateUi(QDialog *FilesInUseDialog)
    {
        FilesInUseDialog->setWindowTitle(QApplication::translate("FilesInUseDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class FilesInUseDialog: public Ui_FilesInUseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESINUSEDIALOG_H
