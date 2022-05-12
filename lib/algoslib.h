#ifndef ALGOSLIB_H
#define ALGOSLIB_H

#include "algoslib_global.h"
#include <string>
#include <vector>


 class  algorithm
{
public:
     algorithm() ;
    virtual std::string getname() = 0;
    virtual std::string gettype() = 0;
    virtual uint32_t gettime() = 0;
    virtual uint32_t getmemory() = 0;
    virtual ~algorithm();
};

 class  sortingalgo:  public algorithm
{
public:

    sortingalgo() ;

    std::string gettype() override;

    virtual void sort() = 0;

    virtual ~sortingalgo();


private:
    std::string type;
};

 class  substringmatching :public algorithm
{
public:
    substringmatching() { this->type = "substringmatching"; };
    std::string gettype() override;
    virtual std::string getline()=0;
    virtual std::string getsample()=0;
    virtual void setline(std::string l)=0;
    virtual void setsample(std::string s)=0;
    virtual int findfirstsubstr()=0;
    virtual ~substringmatching() {};
private:
    std::string type;
};



 class  mergesorting :  public sortingalgo
{
public:
     mergesorting(std::vector<float> v);
    mergesorting();
    void sort() override;
    std::string getname() override;
    uint32_t gettime() override;
    uint32_t getmemory() override;
    std::vector<float> getvalues();
    ~mergesorting() ;
private:
    std::string name;
    uint32_t time;
    uint32_t memory;
    std::vector<float> vec;
    void mergesort(std::vector<float>& arr, int p, int r);
    void merge(std::vector<float>& arr, int p, int mid, int r);
};

 class  quicksorting : public sortingalgo
 {
 public:
     quicksorting(std::vector<float> v) :vec(v)
     {
         this->name = "quicksort";
     }
     quicksorting()
     {
         this->name = "quicksort";
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
std::vector<float> getvalues();
 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<float> vec;
      int partition(std::vector<float>& arr, int p, int r);

      void quicksort(std::vector<float>& arr, int p, int r);

 };

  class  heapsorting :public sortingalgo
 {
 public:
     heapsorting(std::vector<float> v):vec(v)
     {
         this->name = "heapsort";
     }
     heapsorting()
     {
         this->name = "heapsort";
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
    std::vector<float> getvalues();
 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<float> vec;
    void maxheapify(std::vector<float>& arr, int i, int p);

      void buildmaxheap(std::vector<float>& arr, int& p);

    void heapsort(std::vector<float>& arr);
 };

  class  countingsorting :public sortingalgo
 {
 public:

     countingsorting(std::vector<uint32_t> v): vec(v)
     {
         this->name = "countingsort";
         this->base = findmax() + 1;
     }
     countingsorting()
     {
         this->name = "countingsort";
         this->base = findmax() + 1;
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
     void setbase(uint32_t base);
     void setexp(uint32_t exp);
     std::vector<uint32_t> getarray();
     std::vector<uint32_t> getvalues();

 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<uint32_t> vec;
     uint32_t expon=1;
     uint64_t base = UINT32_MAX +1;
     uint32_t findmax();
 void countingsort(std::vector<uint32_t>& arr, uint32_t exp, uint32_t b);
 };

  class  radixsorting :public sortingalgo
 {
 public:
     radixsorting(std::vector<uint32_t> v, uint32_t b1) : vec(v),  base(b1)
     {
         this->name = "radixsort";
     }
     radixsorting(std::vector<uint32_t> v) : vec(v)
     {
         this->name = "radixsort";
     }
     radixsorting()
     {
         this->name = "radixsort";
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
     void setbase(uint32_t b);
    std::vector<uint32_t> getvalues();
 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<uint32_t> vec;
     uint32_t base = 10;
 void radixsort(std::vector<uint32_t>& arr, uint32_t b);

 };

  class  insertionsorting :public sortingalgo
 {
 public:
     insertionsorting(std::vector<float> v) :vec(v)
     {
         this->name = "insertionsort";
     }
     insertionsorting()
     {
         this->name = "insertionsort";
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
      void setvalues(std::vector<float> v);
        std::vector<float> getvalues();
 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<float> vec;
void insertionsort(std::vector<float>& arr);

 };

  class  bucketsorting :public sortingalgo
 {
 public:
     bucketsorting(std::vector<float> v) :vec(v)
     {
         this->name = "bucketsort";
     }
     bucketsorting()
     {
         this->name = "bucketsort";
     }
     void sort() override;
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
    std::vector<float> getvalues();
 private:
     std::string name;
     uint32_t time;
     uint32_t memory;
     std::vector<float> vec;
void bucketsort(std::vector<float>& arr);

 };

class horspool: public substringmatching
{
public:
    horspool(std::string l, std::string s):line(l),sample(s){};

     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
      std::string getline()override;
      std::string getsample()override;
      void setline(std::string l)override;
      void setsample(std::string s)override;
      int findfirstsubstr() override;
private:
     std::string name;
     std::string line;
     std::string sample;
     uint32_t time;
     uint32_t memory;

int horspoolmatching(std::string& sample, std::string line);
};
class boyermoor: public substringmatching
{
public:
    boyermoor(std::string l, std::string s):line(l),sample(s){};
     std::string getname() override;
     uint32_t gettime() override;
     uint32_t getmemory() override;
      std::string getline()override;
      std::string getsample()override;
      void setline(std::string l)override;
      void setsample(std::string s)override;
      int findfirstsubstr() override;
private:
     std::string name;
     std::string line;
     std::string sample;
     uint32_t time;
     uint32_t memory;
      std::vector<int> suffixes(std::string str);
      int boyermoormatching(std::string sample, std::string line);
};







#endif // ALGOSLIB_H
