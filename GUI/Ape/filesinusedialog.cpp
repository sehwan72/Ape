#include "filesinusedialog.h"
#include "ui_filesinusedialog.h"

FilesInUseDialog::FilesInUseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilesInUseDialog)
{
    ui->setupUi(this);
}

FilesInUseDialog::~FilesInUseDialog()
{
    delete ui;
}

void FilesInUseDialog::setFilesList(const std::vector<char *> list) {
    ui->listWidget->clear();
    for (int i = 0; i < list.size(); i++) {
        ui->listWidget->addItem(new QListWidgetItem(list[i]));
    }
}
