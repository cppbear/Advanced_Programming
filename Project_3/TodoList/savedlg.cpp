#include "savedlg.h"
#include "ui_savedlg.h"

SaveDlg::SaveDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDlg)
{
    ui->setupUi(this);
    cancel = false;
    setWindowTitle("TodoList");
}

SaveDlg::~SaveDlg()
{
    delete ui;
}

void SaveDlg::on_pushButtonSave_clicked()
{
    save = true;
    QDialog::accept();
}

void SaveDlg::on_pushButtonNotSave_clicked()
{
    save = false;
    QDialog::reject();
}

void SaveDlg::on_pushButtonCancel_clicked()
{
    cancel = true;
    QDialog::reject();
}
