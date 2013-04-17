#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt:: WindowCloseButtonHint);
    setWindowTitle("About Ape");
    QSvgWidget* image = new QSvgWidget("../Ape/ape.svg", this);

    image->setGeometry(QRect(65, 10, 221, 221));
    image->setFixedWidth(221);
    ui->verticalLayout->insertWidget(0, image);
    image->show();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
