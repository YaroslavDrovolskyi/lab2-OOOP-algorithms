#ifndef FACADE_H
#define FACADE_H
#include "algoslib.h"
#include <QString>
#include "facadeinfo.h"
#include "factory.h"





class Facade                            //"Builder" - builds result
{
public:
    Facade()=default;
    virtual void runAlgo();                //template method
    virtual void setTime(bool b);
    virtual void setNumberOfComparisons(bool b);
    virtual void saveResultData(QString str);
    virtual void saveTime(qint64 t);
     virtual void saveName();
    virtual void setAlgorithm(algorithm* alg);
    virtual void saveNumberOfComparisons();
    virtual abstrFacadeInfo* getInfo() const;
    virtual quint64 calculateTime();
    virtual void selectCreator(int index);
    virtual ~Facade()=default;

protected:
    abstrFacadeInfo* facadeInfo_ = nullptr;
    algoCreator* algoCreator_;
    algorithm* algorithm_;
    bool hasTime = false;
    bool hasNumberOfComparisons  =false;
   // QString line ="";



};

#endif // FACADE_H
