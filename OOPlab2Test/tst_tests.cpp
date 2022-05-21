#include <QtTest>
//#include "algorithms.h"
#include "algoslib.h"
#include <vector>

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void test_mergesort();

    void test_quicksort();

    void test_heapsort();

    void test_countingsort();

    void test_radixsort();

     void test_insertionsort();

      void test_bucketsort();

      void test_horspool();

      void test_boyermoor();



private:
   const std::vector<float> floatnumbers{6,1,2,3,5,7,6,12,6,122,1,1,6};
   const std::vector<float> expectedfloat{1,1,1,2,3,5,6,6,6,6,7,12,122};

   const std::vector<uint32_t> wholenumbers{6,1,2,3,5,7,6,12,6,122,1,1,6};
   const std::vector<uint32_t> expectedwhole{1,1,1,2,3,5,6,6,6,6,7,12,122};


   const std::vector<float> bucketnumbers{0.06,0.001,0.2,0.003,0.5,0.7,0.6,0.12,0.6,0.00122,0.1,0.1,0.6};
   const std::vector<float> expectedbucket{0.001,0.00122,0.003,0.06,0.1,0.1,0.12,0.2,0.5,0.6,0.6,0.6,0.7};

   const std::string line ="ydytjdfjfgfjdf[ipoipjdfs";
   const std::string sample ="jdfs";
   const int expectedpos = 20;



};



template <typename T>
  bool comparator(T a ,  T b)
  {
      if(a >=b)
          return true;

      return false;
  }



tests::tests()
{

}

tests::~tests()
{

}

void tests::test_mergesort()
{


    //std::unique_ptr<mergesorting<float,bool(float a, float b)>>ms (new mergesorting<float,bool(float a, float b)>(this->floatnumbers,comparator<float>));
     //mergesorting<float,bool(float a, float b)>*ms = mergesorting<float,bool(float a, float b)>::GetInstance(this->floatnumbers,comparator<float>);
    std::unique_ptr<mergesorting<float,bool(float a, float b)>>ms ( mergesorting<float,bool(float a, float b)>::GetInstance(this->floatnumbers,comparator<float>));
    ms->run();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
//delete ms;
}

void tests::test_quicksort()
{
//std::unique_ptr<quicksorting<float,bool(float a, float b)>>ms (new quicksorting<float,bool(float a, float b)>(this->floatnumbers,comparator));
std::unique_ptr<quicksorting<float,bool(float a, float b)>>ms ( quicksorting<float,bool(float a, float b)>::GetInstance(this->floatnumbers,comparator<float>));
    ms->run();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_heapsort()
{
//std::unique_ptr<heapsorting<float,bool(float a, float b)>>ms (new heapsorting<float,bool(float a, float b)>(this->floatnumbers,comparator));
std::unique_ptr<heapsorting<float,bool(float a, float b)>>ms ( heapsorting<float,bool(float a, float b)>::GetInstance(this->floatnumbers,comparator<float>));
    ms->run();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_countingsort()
{
//std::unique_ptr<countingsorting<uint32_t,bool(uint32_t a, uint32_t b)>>ms (new countingsorting<uint32_t,bool(uint32_t a, uint32_t b)>(this->wholenumbers,comparator));
   std::unique_ptr<countingsorting<uint32_t,bool(uint32_t a, uint32_t b)>>ms ( countingsorting<uint32_t,bool(uint32_t a, uint32_t b)>::GetInstance(this->wholenumbers,comparator<uint32_t>));
    ms->run();
    QCOMPARE(ms->getvalues(),this->expectedwhole);
}

void tests::test_radixsort()
{
//std::unique_ptr<radixsorting<uint32_t,bool(uint32_t a, uint32_t b)>>ms (new radixsorting<uint32_t,bool(uint32_t a, uint32_t b)>(this->wholenumbers,comparator));
std::unique_ptr<radixsorting<uint32_t,bool(uint32_t a, uint32_t b)>>ms ( radixsorting<uint32_t,bool(uint32_t a, uint32_t b)>::GetInstance(this->wholenumbers,comparator<uint32_t>));
ms->run();
    QCOMPARE(ms->getvalues(),this->expectedwhole);
}

void tests::test_insertionsort()
{
//std::unique_ptr<insertionsorting<float,bool(float a, float b)>>ms (new insertionsorting<float,bool(float a, float b)>(this->floatnumbers,comparator));
std::unique_ptr<insertionsorting<float,bool(float a, float b)>>ms ( insertionsorting<float,bool(float a, float b)>::GetInstance(this->floatnumbers,comparator<float>));
ms->run();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_bucketsort()
{
//std::unique_ptr<bucketsorting<float,bool(float a, float b)>>ms (new bucketsorting<float,bool(float a, float b)>(this->bucketnumbers,comparator));
std::unique_ptr<bucketsorting<float,bool(float a, float b)>>ms ( bucketsorting<float,bool(float a, float b)>::GetInstance(this->bucketnumbers,comparator<float>));
    ms->run();
    QCOMPARE(ms->getvalues(),this->expectedbucket);
}

void tests::test_horspool()
{
    std::unique_ptr<horspool>ms ( horspool::GetInstance(this->line,this->sample));
    ms->run();
    int res = ms->getId();
    QVERIFY(res == this->expectedpos);
}

void tests::test_boyermoor()
{
    std::unique_ptr<boyermoor>ms ( boyermoor::GetInstance(this->line,this->sample));
    ms->run();
    int res = ms->getId();
    QVERIFY(res == this->expectedpos);
}


QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
