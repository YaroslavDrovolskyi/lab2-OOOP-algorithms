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
    virtual QString getResult();
  // virtual concreteFacadeInfo
    virtual void runAlgo()=0;
    virtual void convertToQString()=0;
    virtual bool areValidNumbers(const QVector<QString>&listofnumbers, const QRegularExpression& expr);
    virtual ~algoCreator()=default;

protected:
   virtual bool readLine(QString&&)=0;
    QString res;
};


class mergeSortCreator : public algoCreator
{
public:
    mergeSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;
    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<float> vec;

    mergesorting<float,bool(float,float)>*mergesorting_;
};

class quickSortCreator : public algoCreator
{
public:
    quickSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<float> vec;

    quicksorting<float,bool(float,float)>*quicksorting_;
};


class heapSortCreator : public algoCreator
{
public:
    heapSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<float> vec;

    heapsorting<float,bool(float,float)>*heapsorting_;
};

class countingSortCreator : public algoCreator
{
public:
    countingSortCreator(QString&&, bool(uint32_t,uint32_t));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<uint32_t> vec;

    countingsorting<uint32_t,bool(uint32_t,uint32_t)>*countingsorting_;
};

class radixSortCreator : public algoCreator
{
public:
    radixSortCreator(QString&&, bool(uint32_t,uint32_t));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<uint32_t> vec;

    radixsorting<uint32_t,bool(uint32_t,uint32_t)>*radixsorting_;
};


class insertionSortCreator : public algoCreator
{
public:
    insertionSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<float> vec;

    insertionsorting<float,bool(float,float)>*insertionsorting_;
};

class bucketSortCreator : public algoCreator
{
public:
    bucketSortCreator(QString&&, bool(float,float));
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
    std::vector<float> vec;

    bucketsorting<float,bool(float,float)>*bucketsorting_;
};

class horspoolCreator : public algoCreator
{
public:
    horspoolCreator(QString&&);
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;
   int id;
   QString sample;
   QString line;

    horspool* horspool_;
};

class boyermoorCreator : public algoCreator
{
public:
    boyermoorCreator(QString&&);
    algorithm* getAlgorithm() override;

    void runAlgo() override;
private:
    void convertToQString() override;
    bool readLine(QString&&) override;

   QString sample;
   QString line;
    boyermoor* boyermoor_;
};

//class CombSortCreator : public algoCreator
//{
//public:
//    CombSortCreator(QString&&, bool(float,float));
//    algorithm* getAlgorithm() override;

//    void runAlgo() override;
//private:
//    void convertToQString() override;
//    bool readLine(QString&&) override;
//    std::vector<float> vec;

//    CombSort<float,bool(float,float)>*CombSort_;
//};

//class ShellSortCreator : public algoCreator
//{
//public:
//    ShellSortCreator(QString&&, bool(float,float));
//    algorithm* getAlgorithm() override;

//    void runAlgo() override;
//private:
//    void convertToQString() override;
//    bool readLine(QString&&) override;
//    std::vector<float> vec;

//    ShellSort<float,bool(float,float)>*ShellSort_;
//};

//class OddEvenSortCreator : public algoCreator
//{
//public:
//    OddEvenSortCreator(QString&&, bool(float,float));
//    algorithm* getAlgorithm() override;

//    void runAlgo() override;
//private:
//    void convertToQString() override;
//    bool readLine(QString&&) override;
//    std::vector<float> vec;

//    OddEvenSort<float,bool(float,float)>*OddEvenSort_;
//};

//class CocktailShakerSortCreator : public algoCreator
//{
//public:
//    CocktailShakerSortCreator(QString&&, bool(float,float));
//    algorithm* getAlgorithm() override;

//    void runAlgo() override;
//private:
//    void convertToQString() override;
//    bool readLine(QString&&) override;
//    std::vector<float> vec;

//    CocktailShakerSort<float,bool(float,float)>*CocktailShakerSort_;
//};

//class TimSortCreator : public algoCreator
//{
//public:
//    TimSortCreator(QString&&, bool(float,float));
//    algorithm* getAlgorithm() override;

//    void runAlgo() override;
//private:
//    void convertToQString() override;
//    bool readLine(QString&&) override;
//    std::vector<float> vec;

//    TimSort<float,bool(float,float)>*TimSort_;
//};
#endif // FACTORY_H
