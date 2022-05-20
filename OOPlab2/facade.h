#ifndef FACADE_H
#define FACADE_H
#include "algoslib.h"
#include <QString>



class abstrFacadeInfo
{
public:

   virtual void setTime(qint64 t)=0;
   virtual void setName(QString n)=0;
   virtual void setResult(QString s)=0;
   virtual ~abstrFacadeInfo()=default;

};
class concreteFacadeInfo:public abstrFacadeInfo
{
public:
    concreteFacadeInfo() = default;
    void setTime(qint64 t) override;
    void setName(QString n)override;
    void setResult(QString s)override;
    private:
        qint64 time=0;
        QString name="";
        QString result="";
};



class Facade                            //"Builder" - builds result
{
public:
    Facade()=default;
    virtual void runAlgo();                //template method
    virtual void setTime(bool b);
    virtual void setNumberOfComparisons(bool b);
    virtual void saveResultData(QString str);
    virtual void saveTime(qint64 t);
    virtual void setAlgorithm(algorithm* alg);
    virtual void saveNumberOfComparisons();
    virtual quint64 calculateTime();

protected:
    abstrFacadeInfo* facadeInfo_ = nullptr;
    algorithm* algorithm_;
    bool hasTime = false;
    bool hasNumberOfComparisons  =false;
    QString line ="";


};

#endif // FACADE_H
