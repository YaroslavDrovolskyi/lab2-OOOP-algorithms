#include <QtTest>
#include "algorithms.h"
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

      void test_lib();

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



tests::tests()
{

}

tests::~tests()
{

}

void tests::test_mergesort()
{
    std::unique_ptr<mergesorting>ms (new mergesorting(this->floatnumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedfloat);

}

void tests::test_quicksort()
{
std::unique_ptr<quicksorting>ms (new quicksorting(this->floatnumbers));

    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_heapsort()
{
std::unique_ptr<heapsorting>ms (new heapsorting(this->floatnumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_countingsort()
{
std::unique_ptr<countingsorting>ms (new countingsorting(this->wholenumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedwhole);
}

void tests::test_radixsort()
{
std::unique_ptr<radixsorting>ms (new radixsorting(this->wholenumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedwhole);
}

void tests::test_insertionsort()
{
std::unique_ptr<insertionsorting>ms (new insertionsorting(this->floatnumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedfloat);
}

void tests::test_bucketsort()
{
std::unique_ptr<bucketsorting>ms (new bucketsorting(this->bucketnumbers));
    ms->sort();
    QCOMPARE(ms->getvalues(),this->expectedbucket);
}

void tests::test_horspool()
{
    std::unique_ptr<horspool>ms (new horspool(this->line,this->sample));
    int res = ms->findfirstsubstr();
    QVERIFY(res == this->expectedpos);
}

void tests::test_boyermoor()
{
    std::unique_ptr<boyermoor>ms (new boyermoor(this->line,this->sample));
    int res = ms->findfirstsubstr();
    QVERIFY(res == this->expectedpos);
}


QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
