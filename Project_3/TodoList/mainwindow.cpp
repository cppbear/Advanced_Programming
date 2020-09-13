#include "mainwindow.h"
#include "adddlg.h"
#include "aboutdlg.h"
#include "savedlg.h"
#include "ui_mainwindow.h"

//bool isOpen = false;
bool isModified = false;
bool isNew = true;
QString lastFilename = "";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TodoList");
    iniUI();
    mytimer = new QTimer();
    iniSignalSlots();
    mytimer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mytimer;
}

void MainWindow::iniUI()
{
    ui->tableWidget->setColumnCount(7);
    //ui->tableWidget->setRowCount(5);
    QStringList header;
    header << ""
           << "状态"
           << "标题"
           << "内容"
           << "时间"
           << "";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //ui->tableWidget->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidget->horizontalHeader()->resizeSection(1, 36);
    ui->tableWidget->horizontalHeader()->resizeSection(2, 170);
    ui->tableWidget->horizontalHeader()->resizeSection(3, 320);
    ui->tableWidget->horizontalHeader()->resizeSection(4, 150);
    ui->tableWidget->horizontalHeader()->resizeSection(5, 70);
    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setColumnHidden(6, true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->setSortIndicatorShown(true);
}

void MainWindow::iniSignalSlots()
{
    connect(ui->tableWidget->verticalHeader(), SIGNAL(sectionDoubleClicked(int)), this, SLOT(modify(int)));
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sort(int)));
    connect(mytimer, SIGNAL(timeout()), this, SLOT(timeResponse()));
    //connect(ui->tableWidget, SIGNAL())
}

void MainWindow::addList(int status, QStringList title_cont, QDateTimeEdit* timeedit)
{
    int rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowcount);
    QTableWidgetItem* checked = new QTableWidgetItem();
    if (status == 0)
    {
        checked->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem("0"));
    }
    else
    {
        checked->setCheckState(Qt::Checked);
        ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem("1"));
    }
    ui->tableWidget->setItem(rowcount, 1, checked);
    ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(title_cont[0]));
    ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(title_cont[1]));
    //QDateTimeEdit* datetime = new QDateTimeEdit(dlg->getDateTime());
    ui->tableWidget->setItem(rowcount, 4, new QTableWidgetItem(timeedit->dateTime().toString("yyyy/MM/dd hh:mm")));

    QPushButton* Delete = new QPushButton();
    Delete->setText("删除");
    Delete->setFixedSize(69, 29);
    QWidget* widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(Delete);
    widget->setLayout(layout);
    ui->tableWidget->setCellWidget(rowcount, 5, widget);
    connect(Delete, SIGNAL(clicked()), this, SLOT(deleteRow()));

    //QDateTimeEdit* datetime = new QDateTimeEdit(dlg->getDateTime());
    ui->tableWidget->setCellWidget(rowcount, 6, timeedit);
}

void MainWindow::on_actionAddlist_triggered()
{
    AddDlg* dlg = new AddDlg;
    dlg->setWindowTitle("添加日程");
    dlg->exec();
    if (dlg->getStatus())
    {
        QStringList res = dlg->getData();
        if (res[0] != "" || res[1] != "")
        {
            isModified = true;
            QDateTimeEdit* datetime = new QDateTimeEdit(dlg->getDateTime());
            addList(0, res, datetime);
        }
    }
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDlg* dlg = new AboutDlg;
    dlg->exec();
}

void MainWindow::modify(int index)
{
    isModified = true;
    QStringList content;
    content.push_back(ui->tableWidget->item(index, 2)->text());
    content.push_back(ui->tableWidget->item(index, 3)->text());
    QDateTimeEdit* datetime = (QDateTimeEdit*)(ui->tableWidget->cellWidget(index, 6));
    AddDlg* dlg = new AddDlg;
    dlg->set(content, datetime->dateTime());
    dlg->setWindowTitle("修改日程");
    dlg->exec();
    if (dlg->getStatus()) {
        QStringList res = dlg->getData();
        if (res[0] != "" || res[1] != "") {
            ui->tableWidget->item(index, 2)->setText(res[0]);
            ui->tableWidget->item(index, 3)->setText(res[1]);
            QDateTimeEdit* datetime = new QDateTimeEdit(dlg->getDateTime());
            ui->tableWidget->item(index, 4)->setText(datetime->dateTime().toString("yyyy/MM/dd hh:mm"));
            ui->tableWidget->setCellWidget(index, 6, datetime);
        }
    }
}

void MainWindow::deleteRow()
{
    QPushButton* btn = (QPushButton*)sender();
    int x = btn->frameGeometry().x();
    int y = btn->frameGeometry().y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
    int row = index.row();
    ui->tableWidget->removeRow(row);
}

void MainWindow::timeResponse()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QDateTimeEdit* obj = (QDateTimeEdit*)(ui->tableWidget->cellWidget(i, 6));
        QDateTime temp = obj->dateTime();
        QDateTime cur = QDateTime::currentDateTime();
        if (temp.date() == cur.date() &&
            temp.time().hour() == cur.time().hour() &&
            temp.time().minute() == cur.time().minute() &&
            cur.time().second() < 4 &&
            ui->tableWidget->item(i, 1)->checkState() == Qt::Unchecked)
        {
            QSound::play(":/sound/msg.wav");
            break;
        }
    }
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if (column == 1)
    {
        if (ui->tableWidget->item(row, column)->checkState() == Qt::Checked)
        {
            ui->tableWidget->item(row, 0)->setText("1");
        }
        else
        {
            ui->tableWidget->item(row, 0)->setText("0");
        }
    }
}

void MainWindow::sort(int index)
{
    if (index == 2 || index == 3 || index == 4)
        ui->tableWidget->sortByColumn(index);
    else if (index == 1)
    {
        ui->tableWidget->sortByColumn(0);
    }
}

QString MainWindow::on_actionImport_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr(""), tr("Text File (*.todo)"));
    if (fileName == "")
    {
        return "";
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("错误"), tr("打开文件失败"));
            return "";
        }
        else
        {
            if (!file.isReadable())
            {
                QMessageBox::warning(this, tr("错误"), tr("该文件不可读"));
            }
            else
            {
                QTextStream textStream(&file);
                QTextCodec* codec = QTextCodec::codecForName("UTF-8");
                textStream.setCodec(codec);
                while (!textStream.atEnd())
                {
                    int status;
                    QStringList res;
                    QDateTime time;
                    QString temp = textStream.readLine();
                    status = temp.toInt();
                    temp = textStream.readLine();
                    res.push_back(temp);
                    temp = textStream.readLine();
                    res.push_back(temp);
                    temp = textStream.readLine();
                    time = QDateTime::fromString(temp, "yyyy/MM/dd hh:mm");
                    QDateTimeEdit* edit = new QDateTimeEdit(time);
                    addList(status, res, edit);
                }
                file.close();
                //isOpen = true;
                if (lastFilename == "")
                    isNew = true;
                else
                    isNew = false;
                //isNew = false;
                isModified = true;
                //lastFilename = fileName;
            }
            return fileName;
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    if (isModified)
    {
        SaveDlg* dlg = new SaveDlg();
        dlg->exec();
        if (dlg->getCancel())
        {
            return;
        }
        else if (dlg->getSave())
        {
            //将原文件保存
            int ret = on_actionSave_triggered();
            if (ret != 0)
                return;
        }
    }
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QString name = on_actionImport_triggered();
    if (name != "")
    {
        lastFilename = name;
        isNew = false;
        isModified = false;
        QString title = lastFilename.section("/", -1);
        setWindowTitle(title);
    }
}

void MainWindow::on_actionNewFile_triggered()
{
    if (isModified)
    {
        SaveDlg* dlg = new SaveDlg();
        dlg->exec();
        if (dlg->getCancel())
        {
            return;
        }
        else if (dlg->getSave())
        {
            //将原文件保存
            int ret = on_actionSave_triggered();
            if (ret != 0)
                return;
        }
    }
    setWindowTitle("TodoList");
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    isNew = true;
    //isOpen = true;
}

int MainWindow::on_actionSaveAs_triggered()
{
    QFileDialog fileDialog;
    QString str = fileDialog.getSaveFileName(this, tr("另存为"), "/新建事项", tr("TodoList File(*.todo)"));
    if (str == "")
    {
        return 1;
    }
    QFile filename(str);
    if (!filename.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("错误"), tr("打开文件失败"), QMessageBox::Ok);
        return -1;
    }
    else
    {
        QTextStream textStream(&filename);
        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        textStream.setCodec(codec);
        QString str;
        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            if (ui->tableWidget->item(i, 1)->checkState() == Qt::Checked)
                str = "1";
            else
                str = "0";
            textStream << str << endl;
            textStream << ui->tableWidget->item(i, 2)->text() << endl
                       << ui->tableWidget->item(i, 3)->text() << endl
                       << ui->tableWidget->item(i, 4)->text() << endl;
        }
        //Last_FileContent = str;
    }
    //QMessageBox::information(this, "保存文件", "保存文件成功", QMessageBox::Ok);
    filename.close();
    isNew = false;
    lastFilename = str;
    isModified = false;
    QString title = lastFilename.section("/", -1);
    setWindowTitle(title);
    return 0;
}

int MainWindow::on_actionSave_triggered()
{
    if (isNew)
    {
        return on_actionSaveAs_triggered();
    }
    else
    {
        //if (isOpen)

        QFile file(lastFilename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("警告"), tr("打开文件失败"));
            return -1;
        }
        else
        {
            QTextStream textStream(&file);
            QTextCodec* codec = QTextCodec::codecForName("UTF-8");
            textStream.setCodec(codec);
            QString str;
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
            {
                if (ui->tableWidget->item(i, 1)->checkState() == Qt::Checked)
                    str = "1";
                else
                    str = "0";
                textStream << str << endl;
                textStream << ui->tableWidget->item(i, 2)->text() << endl
                           << ui->tableWidget->item(i, 3)->text() << endl
                           << ui->tableWidget->item(i, 4)->text() << endl;
            }
            file.close();
            isModified = false;
        }
        QString title = lastFilename.section("/", -1);
        setWindowTitle(title);
        return 0;
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (isModified)
    {
        SaveDlg* dlg = new SaveDlg();
        dlg->exec();
        if (dlg->getCancel())
        {
            event->ignore();
        }
        else if (dlg->getSave())
        {
            //将原文件保存
            int ret = on_actionSave_triggered();
            if (ret != 0)
                event->ignore();
        }
    }
    else
    {
        event->accept();
    }
}
