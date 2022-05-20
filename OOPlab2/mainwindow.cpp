#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoslib.h"
#include <vector>
#include "QString"
#include "QRegularExpression"
#include <QMessageBox>
#include "facade.h"
#include <memory>

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
    QVector<QString> colnames = {"Name","Time","Memory","Result"};
    ui->resultTable->setColumnCount(4);
    ui->resultTable->setHorizontalHeaderLabels(colnames);

    this->facade = new Facade();

}

MainWindow::~MainWindow()
{
    delete ui;
}



 bool MainWindow::areValidNumbers(const QVector<QString>&listofnumbers, const QRegularExpression& expr)
 {
      size_t len = listofnumbers.size();
      for(auto i=0; i<len; i++)
      {
          if(!listofnumbers[i].contains(expr))
              return false;
      }
      return true;
 };

void MainWindow::on_btnrun_clicked()
{
//   const QRegularExpression regexp("[^0-9.]");
//   const QRegularExpression validNumberRegex("\\A[0-9]+\\.{0,1}[0-9]+$");
//   const QString inputline = ui->inputline->text();
//  // inputline = inputline.
//   const QVector<QString> listofnumbers =  inputline.split(regexp,Qt::SkipEmptyParts);
//   ui->inputline->clear();
//   QString l;
//for(auto i =0; i< listofnumbers.size(); i++)
//{
//    l.push_back(listofnumbers[i]);
//}
//ui->inputline->setText(l);
//   if(!areValidNumbers(listofnumbers,validNumberRegex))
//       ui->inputline->clear();

this->facade->setAlgorithm(this->algorithm_);
    this->facade->setTime(true);
    this->facade->runAlgo();
}


void MainWindow::on_algoselector_currentIndexChanged(int index)
{
    std::vector<float> exmpl = {1,23,4,5}; //delete
    switch (index) {
    case(0):
       this->algorithm_ = mergesorting<float,bool(float a, float b)>::GetInstance(exmpl,comparatorAscend<float>);

        break;
    case(1):

        break;
    case(2):

        break;
    case(3):

        break;
    case(4):

        break;
    case(5):

        break;
    case(6):

        break;
    case(7):

        break;

    }
}

