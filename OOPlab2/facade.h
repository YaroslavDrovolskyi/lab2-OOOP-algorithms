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
    virtual void saveNumberOfComparisons();
    virtual abstrFacadeInfo* getInfo() const;
    virtual quint64 calculateTime();
    virtual void selectCreator(int index);
    virtual ~Facade()=default;

protected:
    abstrFacadeInfo* facadeInfo_ = nullptr;
    algoCreator* algoCreator_;
 //  algorithm* algorithm_;
    bool hasTime = false;
    bool hasNumberOfComparisons  =false;
   // QString line ="";
private:
    template <typename T>
      static bool comparatorAscend(T a ,  T b);
       template <typename T>
        static  bool comparatorDescend(T a ,  T b);
          QString inputLine;


};

#endif // FACADE_H
