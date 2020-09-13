#ifndef ADDDLG_H
#define ADDDLG_H

#include <QDialog>

namespace Ui {
class AddDlg;
}

class AddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddDlg(QWidget *parent = nullptr);
    //explicit AddDlg(bool modi);
    ~AddDlg();
    QStringList getData() { return data; }
    bool getStatus() { return success; }
    QDateTime getDateTime();
    void set(QStringList str, QDateTime time);

private slots:
    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::AddDlg *ui;
    bool success = false;
    //bool modify = false;
    QStringList data;
};

#endif // ADDDLG_H
