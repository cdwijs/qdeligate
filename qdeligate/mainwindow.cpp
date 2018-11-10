#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QDateTime>
#include "deligate.h"


static QStandardItemModel *model;
static QTableView *tableView;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    model = new QStandardItemModel(10, 4);
    QModelIndex index;
    QVariant variant;
    QDateTime datetime;
    datetime = datetime.currentDateTime();
    QTime time;
    time = time.currentTime();
    qint8 num8=13;
    qint16 num16=17;

    for (int row = 0; row < 10; ++row)
    {
        index = model->index(row, 0, QModelIndex());
        variant = datetime;
        datetime = datetime.addSecs(3);
        model->setData(index, variant);

        index = model->index(row, 1, QModelIndex());
        variant = time;
        time = time.addSecs(5);
        model->setData(index, variant);

        index = model->index(row, 2, QModelIndex());
        variant = num8;
        num8 += 7;
        model->setData(index, variant);

        index = model->index(row, 3, QModelIndex());
        variant = num16;
        num16 += 11;
        model->setData(index, variant);
    }


    tableView = new QTableView ;
    tableView->setModel(model);
    Deligate *deligate = new Deligate;
    tableView->setItemDelegate(deligate);
    tableView->show();
}

MainWindow::~MainWindow()
{
    //delete ui;
}
