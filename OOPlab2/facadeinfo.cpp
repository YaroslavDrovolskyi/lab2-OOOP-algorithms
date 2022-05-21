#include "facadeinfo.h"
#include <QString>

template<typename T>
void concreteFacadeInfo<T>::setTime(qint64 t) {
    this->time = t;
};
template<typename T>
void concreteFacadeInfo<T>::setName(QString n){
    this->name = n;

};
template<typename T>
void concreteFacadeInfo<T>::setResult(QString s){
    this->result = s;
};


