#ifndef FILESINUSEDIALOG_H
#define FILESINUSEDIALOG_H

#include <QDialog>

namespace Ui {
class FilesInUseDialog;
}

class FilesInUseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FilesInUseDialog(QWidget *parent = 0);
    void setFilesList(const std::vector<char *>);
    ~FilesInUseDialog();
    
private:
    Ui::FilesInUseDialog *ui;
};

#endif // FILESINUSEDIALOG_H
