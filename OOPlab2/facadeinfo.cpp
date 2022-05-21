#include "facadeinfo.h"
#include <QString>


void concreteFacadeInfo::setTime(qint64 t) {
    this->time = t;
};

void concreteFacadeInfo::setName(QString n){
    this->name = n;

};

void concreteFacadeInfo::setResult(QString s){
    this->result = s;
};


