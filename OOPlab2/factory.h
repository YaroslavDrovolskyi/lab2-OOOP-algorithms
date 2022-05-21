#ifndef FACTORY_H
#define FACTORY_H
#include "algoslib.h"
#include <vector>
#include "facadeinfo.h"

class algoCreator
{
public:
    algoCreator()=default;
   virtual algorithm* getAlgorithm()=0;
    virtual QString getResult() =0;
  // virtual concreteFacadeInfo
    virtual void runAlgo()=0;
    virtual void convertToQString()=0;
    virtual bool areValidNumbers(const QVector<QString>&listofnumbers, const QRegularExpression& expr);
    virtual ~algoCreator()=default;

private:
   virtual void readLine(QString&&)=0;

};


class mergeSortCreator : public algoCreator
{
public:
    mergeSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;
    QString getResult() override;
    void runAlgo() override;
private:
    void convertToQString() override;
    void readLine(QString&&) override;
    std::vector<float> vec;
    QString res;
    mergesorting<float,bool(float,float)>*mergesorting_;
};



#endif // FACTORY_H
