#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithms.h"
#include "rawalgorithms.h"
#include <vector>
//#include <check.h>
#include "QString"
#include "QRegularExpression"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 std::vector<float> floatnumbers{6,1,2};


check(floatnumbers);
qDebug()<<"success!";
}

MainWindow::~MainWindow()
{
    delete ui;
}




