#include "factory.h"
#include "facadeinfo.h"
#include <QRegularExpression>

 algorithm* mergeSortCreator::getAlgorithm()
 {

    return this->mergesorting_;
 }


 bool algoCreator::areValidNumbers(const QVector<QString>&listofnumbers, const QRegularExpression& expr)
 {
     size_t len = listofnumbers.size();
     for(auto i=0; i<len; i++)
     {
         if(!listofnumbers[i].contains(expr))
             return false;
     }
     return true;
 }

    QString mergeSortCreator::getResult()
    {
        return this->res;
    }
  mergeSortCreator::mergeSortCreator(QString&& line, bool a(float,float) )
  {
      this->readLine(std::move(line));
       mergesorting_ = mergesorting<float, bool(float,float)>::GetInstance(this->vec,a);
  }

 void mergeSortCreator::readLine(QString&& line)
 {
        const QRegularExpression regexp("[^0-9.]");
        const QRegularExpression validNumberRegex("\\A[0-9]+\\.{0,1}[0-9]*$");

        const QVector<QString> listofnumbers =  line.split(regexp,Qt::SkipEmptyParts);



        if(!areValidNumbers(listofnumbers,validNumberRegex))        //process error
        {

        }
        else
        {
      size_t size = listofnumbers.size();
     for(auto i =0; i< size; i++)
     {
        this->vec.push_back(listofnumbers[i].toFloat());
     }
        }
 }
 void mergeSortCreator::runAlgo()
 {
     this->mergesorting_->run();
     this->convertToQString();
 }
 void mergeSortCreator::convertToQString()
 {
//     for(auto i : this->vec)
//     {
//         this->res.append(QString::number(i));
//     }

     size_t size = this->vec.size();
     auto res = this->mergesorting_->getvalues();
     for(auto i=0; i< size; i++)
     {
          this->res.append(QString::number(res[i]));
         if(i!= size-1)
              this->res.append(" ");
     }
 }
