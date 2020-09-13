#ifndef SAVEDLG_H
#define SAVEDLG_H

#include <QDialog>

namespace Ui {
class SaveDlg;
}

class SaveDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDlg(QWidget *parent = nullptr);
    ~SaveDlg();
    bool getSave() { return save; }
    bool getCancel() { return cancel; }

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonNotSave_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::SaveDlg *ui;
    bool save;
    bool cancel;
};

#endif // SAVEDLG_H
