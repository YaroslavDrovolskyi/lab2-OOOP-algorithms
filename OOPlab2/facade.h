#ifndef FACADE_H
#define FACADE_H
#include "algoslib.h"
#include <QString>
#include "facadeinfo.h"
#include "factory.h"
#include <memory>
#include <functional>



class Facade                            //"Builder" - builds result
{
public:
    Facade()=default;
     void runAlgo(const int ind, QString line);                //template method
     void setTime(bool b);
     void setNumberOfComparisons(bool b);
     void setInputLine(QString& l);
     void saveResultData(QString str);
     void saveTime(QString& t);
      void saveName();
     void saveNumberOfComparisons();
      std::shared_ptr<abstrFacadeInfo> getInfo() const;
    void setIsAscend(bool b);
     void selectCreator(int index);
     ~Facade()=default;

protected:
     std::shared_ptr<abstrFacadeInfo>facadeInfo_ ;
     std::shared_ptr<algoCreator>algoCreator_;
 //  algorithm* algorithm_;
    bool hasTime = false;
    bool hasNumberOfComparisons  =false;
  static inline  uint32_t counter;

   // QString line ="";
private:

    bool isAscend = true;
    virtual QString calculateTime();
    template <typename T>
      static bool comparatorAscend(T a ,  T b);
       template <typename T>
        static  bool comparatorDescend(T a ,  T b);
          QString inputLine;


};

#endif // FACADE_H
