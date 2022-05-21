#include "facade.h"
#include "visitor.h"
#include <QDebug>
#include "facadeinfo.h"





 void Facade::runAlgo()      //template method
 {
   //  this->facadeInfo_ = new concreteFacadeInfo();
    if(this->hasTime)
    {
        qint64 t = this->calculateTime();
        this->saveTime(t);
    }
    else
 //       this->algorithm_->run();
   std::string a = this->algorithm_->gettype();
    if(!QString::compare("sorting",QString::fromStdString(this->algorithm_->gettype()),Qt::CaseSensitivity::CaseSensitive))
        this->saveResultData("sorted");
    else if(QString::compare("substringmatching",QString::fromStdString(this->algorithm_->gettype()),Qt::CaseSensitivity::CaseSensitive))
    this->saveResultData("substring matching was performed");
    this->saveName();
 };





 void Facade::selectCreator(int index)
 {
     switch (index) {
     case(0):

      //  this-> = mergesorting<float,bool(float a, float b)>::GetInstance(exmpl,this->comparatorAscend<float>);

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



 void Facade::setTime(bool b){
    this->hasTime = b;
 };
 void Facade::setNumberOfComparisons(bool b){
     this->hasNumberOfComparisons = b;


 };

 abstrFacadeInfo* Facade::getInfo() const
 {
     return this->facadeInfo_;
 }

 void Facade::saveName()
 {
     this->facadeInfo_->setName(QString::fromStdString(this->algorithm_->getname()));
 };
 void Facade::saveResultData(QString str){
     this->facadeInfo_->setResult(str);

 };
 void Facade::saveTime(qint64 t){
    this->facadeInfo_->setTime(t);
 };
 void Facade::saveNumberOfComparisons(){

 };

 quint64 Facade::calculateTime()
 {
     visitor visitor_(this->algorithm_);
     visitor_.calculateTime();
    return visitor_.getTime();

 }

 void Facade::setAlgorithm(algorithm *alg)
 {
     this->algorithm_ = alg;
 }
