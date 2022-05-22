#ifndef FACADE_H
#define FACADE_H
#include "algoslib.h"
#include <QString>
#include "facadeinfo.h"
#include "factory.h"
#include <memory>




class Facade                            //"Builder" - builds result
{
public:
    Facade()=default;
    virtual void runAlgo(const int ind, QString line);                //template method
    virtual void setTime(bool b);
    virtual void setNumberOfComparisons(bool b);
    virtual void setInputLine(QString& l);
    virtual void saveResultData(QString str);
    virtual void saveTime(QString& t);
     virtual void saveName();
    virtual void saveNumberOfComparisons();
    virtual  std::shared_ptr<abstrFacadeInfo> getInfo() const;

    virtual void selectCreator(int index);
    virtual ~Facade()=default;

protected:
     std::shared_ptr<abstrFacadeInfo>facadeInfo_ ;
     std::shared_ptr<algoCreator>algoCreator_;
 //  algorithm* algorithm_;
    bool hasTime = false;
    bool hasNumberOfComparisons  =false;
  static inline  uint32_t counter;
   // QString line ="";
private:
    virtual QString calculateTime();
    template <typename T>
      static bool comparatorAscend(T a ,  T b);
       template <typename T>
        static  bool comparatorDescend(T a ,  T b);
          QString inputLine;


};

#endif // FACADE_H
