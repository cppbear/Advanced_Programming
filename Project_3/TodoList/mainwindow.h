#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDateTimeEdit>
#include <QTime>
#include <QPushButton>
#include <QTimer>
#include <QSound>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDevice>
#include <QTextStream>
#include <QTextEdit>
#include <QTextCodec>
#include <QtEvents>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAddlist_triggered();

    void on_actionAbout_triggered();

    void modify(int index);

    void deleteRow();

    void timeResponse();

    void sort(int index);

    void on_tableWidget_cellChanged(int row, int column);

    void on_actionOpen_triggered();

    void on_actionNewFile_triggered();

    int on_actionSave_triggered();

    QString on_actionImport_triggered();

    int on_actionSaveAs_triggered();

private:
    Ui::MainWindow *ui;
    QTimer* mytimer;

    void iniUI();
    void iniSignalSlots();
    void addList(int status, QStringList title_cont, QDateTimeEdit* timeedit);
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
