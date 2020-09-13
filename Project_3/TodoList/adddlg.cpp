#include "adddlg.h"
#include "ui_adddlg.h"

AddDlg::AddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDlg)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

AddDlg::~AddDlg()
{
    delete ui;
}

void AddDlg::on_pushButtonOK_clicked()
{
    success = true;
    QString title = ui->lineEdit->text();
    QString content = ui->plainTextEdit->toPlainText();
    QString time = ui->dateTimeEdit->text();
    //ui->dateTimeEdit->
    data.clear();
    data.push_back(title);
    data.push_back(content);
    //data.push_back(time);
    QDialog::accept();
}

void AddDlg::on_pushButtonCancel_clicked()
{
    success = false;
    QDialog::reject();
}

QDateTime AddDlg::getDateTime()
{
    return ui->dateTimeEdit->dateTime();
}

void AddDlg::set(QStringList str, QDateTime time)
{
    data = str;
    ui->lineEdit->setText(str[0]);
    ui->plainTextEdit->setPlainText(str[1]);
    ui->dateTimeEdit->setDateTime(time);
}

