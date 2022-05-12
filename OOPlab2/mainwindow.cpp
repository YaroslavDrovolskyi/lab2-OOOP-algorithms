#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoslib.h"
#include <vector>
#include "QString"
#include "QRegularExpression"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //selector initialization
    for(const auto &i: this->NamesOfAlgos)
    {
        ui->algoselector->addItem(i,0);
    }

    //add labels to table
    QVector<QString> colnames = {"Name","Time","Memory"};
    ui->resultTable->setColumnCount(3);
    ui->resultTable->setHorizontalHeaderLabels(colnames);



}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_btnrun_clicked()
{
    //const QRegularExpression regexp("[^0-9]");
}

