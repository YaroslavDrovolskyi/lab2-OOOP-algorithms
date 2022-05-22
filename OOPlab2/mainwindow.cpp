#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoslib.h"
#include <vector>
#include "QString"
#include "QRegularExpression"
#include <QMessageBox>
#include "facade.h"
#include <memory>
#include "factory.h"
#include <set>

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

    facade = new Facade();

    results_table_originator = ResultTableOriginator(ui->resultTable);
    results_history = ResultTableHistory(&results_table_originator);


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

//facade->setAlgorithm(this->algorithm_);
//    facade->setTime(true);
//    facade->runAlgo();

//    algoCreator* ac = new mergeSortCreator(ui->inputline->text(),this->comparatorAscend<float>);
//    ac->runAlgo();

 //   ui->resultTable->setRowCount(100);
//    for (std::size_t i = 0; i < 10; i++){
//        ui->resultTable->insertRow(i);
//        this->results_table_originator.writeInRow(concreteFacadeInfo(QString::number(rand()%100) + " ms", "algo", "result", rand()%100), i);
//    }

    //12 45 12 7 34 7 23 78 45 233235 653 3231 4 12 12 12 3 12

    // "ilove bee drinkingbee beer"   "beer"
//    this->facade->runAlgo(0,this->ui->inputline->text());
//    this->facade->runAlgo(1,this->ui->inputline->text());
//    this->facade->runAlgo(2,this->ui->inputline->text());
    this->facade->runAlgo(7,this->ui->inputline->text());
    this->facade->runAlgo(8,this->ui->inputline->text());

}


void MainWindow::on_algoselector_currentIndexChanged(int index) //move to facade
{
    std::vector<float> exmpl = {1,23,4,5}; //delete

//


}


void MainWindow::on_removeRowBtn_clicked()
{

    auto selected_items = this->ui->resultTable->selectedItems();
    if (!selected_items.empty()){
        this->results_history.backup();
        ui->undoRemoveRow->setEnabled(true);
    }

    std::set<std::size_t> selected_rows;

    // insert rows indexes into set to make them unique
    for(const auto& i : selected_items){
        selected_rows.insert(i->row());
    }

    // get rows indexes and push them into vector, in order to have possibility to iterate from end to begin
    std::vector<std::size_t> rows_to_remove;
    for (const auto i : selected_rows){
        rows_to_remove.push_back(i);
    }

    // remove rows from end to begin
    for (qint64 i = rows_to_remove.size() - 1; i>=0; i--){
        ui->resultTable->removeRow(rows_to_remove[i]);
    }


}


void MainWindow::on_undoRemoveRow_clicked()
{
    this->results_history.undo();

    if (this->results_history.empty()){
        ui->undoRemoveRow->setEnabled(false);
    }

}

