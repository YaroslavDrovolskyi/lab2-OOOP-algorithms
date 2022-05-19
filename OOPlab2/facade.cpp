#include "facade.h"
#include "visitor.h"






void concreteFacadeInfo::setTime(qint64 t) {
    this->time = t;
};
void concreteFacadeInfo::setName(QString n){
    this->name = n;

};
void concreteFacadeInfo::setResult(QString s){
    this->result = s;
};


 void abstrFacade::runAlgo()
 {
     this->facadeInfo_ = new concreteFacadeInfo();
    if(this->hasTime)
    {
        qint64 t = this->calculateTime();
        this->saveTime(t);
    }
    else
        this->algorithm_->run();

    if(QString::compare("sorting",QString::fromStdString(this->algorithm_->gettype()),Qt::CaseSensitivity::CaseSensitive))
        this->saveResultData("sorted");
    else if(QString::compare("substringmatching",QString::fromStdString(this->algorithm_->gettype()),Qt::CaseSensitivity::CaseSensitive))
    this->saveResultData("substring matching was performed");

 };
 void abstrFacade::setTime(bool b){
    this->hasTime = b;
 };
 void abstrFacade::setNumberOfComparisons(bool b){
     this->hasNumberOfComparisons = b;


 };
 void abstrFacade::saveResultData(QString str){
     this->facadeInfo_->setResult(str);

 };
 void abstrFacade::saveTime(qint64 t){
    this->facadeInfo_->setTime(t);
 };
 void abstrFacade::saveNumberOfComparisons(){

 };

 quint64 abstrFacade::calculateTime()
 {
     visitor visitor_(this->algorithm_);
     visitor_.calculateTime();


 }

 void abstrFacade::setAlgorithm(algorithm *alg)
 {
     this->algorithm_ = alg;
 }
