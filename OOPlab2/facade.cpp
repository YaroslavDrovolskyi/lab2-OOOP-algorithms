#include "facade.h"
#include "visitor.h"
#include <QDebug>
#include "facadeinfo.h"







 void Facade::runAlgo()      //template method
 {
     this->facadeInfo_ = new concreteFacadeInfo();
    if(this->hasTime)
    {
        qint64 t = this->calculateTime();
        this->saveTime(t);
    }
    else
        this->algoCreator_->runAlgo();

    this->saveResultData("substring matching was performed");
    this->saveName();
 };


 template <typename T>
    bool Facade::comparatorAscend(T a ,  T b)
   {
       if(a >=b)
           return true;

       return false;

   }

   template <typename T>
     bool Facade::comparatorDescend(T a ,  T b)
     {
         if(a <=b)
             return true;

         return false;

     }


 void Facade::selectCreator(int index)
 {
     switch (index) {
     case(0):


      this->algoCreator_ = new mergeSortCreator(std::move(this->inputLine),this->comparatorAscend<float>);
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
     this->facadeInfo_->setName(QString::fromStdString(this->algoCreator_->getAlgorithm()->getname()));
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
     visitor visitor_(this->algoCreator_->getAlgorithm());
     visitor_.calculateTime();
    return visitor_.getTime();

 }


