#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QDateTime>


static QStandardItemModel *model;
static QTableView *tableView;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(4, 4);
    QModelIndex index;
    QVariant variant;
    QDateTime datetime;
    datetime = datetime.currentDateTime();
    QTime time;
    time = time.currentTime();
    qint8 num8=120;
    qint16 num16=120;

    for (int row = 0; row < 4; ++row)
    {
        index = model->index(row, 0, QModelIndex());
        variant = datetime;
        model->setData(index, variant);

        index = model->index(row, 1, QModelIndex());
        variant = time;
        model->setData(index, variant);

        index = model->index(row, 2, QModelIndex());
        variant = num8;
        model->setData(index, variant);

        index = model->index(row, 3, QModelIndex());
        variant = num16;
        model->setData(index, variant);
    }


    tableView = new QTableView ;
    tableView->setModel(model);
    tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
