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
   virtual uint32_t getmemory() = 0;
   virtual ~algorithm();
};
template<typename Comparator>
class  sortingalgo:  public algorithm
{
public:

   sortingalgo() ;

   std::string gettype() override;

   virtual void sort() = 0;                 //delete, add run() to algorithm

   virtual ~sortingalgo();

protected:
    std::function<Comparator> comparator;
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
    virtual int findfirstsubstr()=0;               //delete, add run() to algorithm
    virtual ~substringmatching() {};
private:
    std::string type;
};


template<typename T,  typename Comparator>
 class  mergesorting :  public sortingalgo<Comparator>
{
public:
     mergesorting(std::vector<T> v, Comparator c);
    mergesorting(Comparator c);
    mergesorting()=delete;

    void sort() override;
    std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    ~mergesorting() ;
private:
    std::string name;
    uint32_t memory;
    std::vector<T> vec;
    void mergesort(std::vector<T>& arr, int p, int r);
    void merge(std::vector<T>& arr, int p, int mid, int r);
};
template<typename T,  typename Comparator>
 class  quicksorting : public sortingalgo<Comparator>
 {
 public:
     quicksorting(std::vector<T> v, Comparator c) :vec(v)
     {
         this->name = "quicksort";
          this->comparator = c;
     }
     quicksorting( Comparator c)
     {
         this->name = "quicksort";
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
std::vector<T> getvalues();
 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
      int partition(std::vector<T>& arr, int p, int r);

      void quicksort(std::vector<T>& arr, int p, int r);

 };
template<typename T,  typename Comparator>
  class  heapsorting :public sortingalgo<Comparator>
 {
 public:
     heapsorting(std::vector<T> v, Comparator c):vec(v)
     {
         this->name = "heapsort";
          this->comparator = c;
     }
     heapsorting( Comparator c)
     {
         this->name = "heapsort";
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();
 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
    void maxheapify(std::vector<T>& arr, int i, int p);

      void buildmaxheap(std::vector<T>& arr, int& p);

    void heapsort(std::vector<T>& arr);
 };
template<typename T,  typename Comparator>
  class  countingsorting :public sortingalgo<Comparator>
 {
 public:

     countingsorting(std::vector<T> v, Comparator c): vec(v)
     {
         this->name = "countingsort";
         this->base = findmax() + 1;
          this->comparator = c;
     }
     countingsorting( Comparator c)
     {
         this->name = "countingsort";
         this->base = findmax() + 1;
          this->comparator = c;
     }
     countingsorting(std::vector<T> v, std::function<Comparator> c): vec(v)
     {
         this->name = "countingsort";
         this->base = findmax() + 1;
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t base);
     void setexp(uint32_t exp);
     std::vector<T> getarray();
     std::vector<T> getvalues();

 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
     uint32_t expon=1;
     uint64_t base = UINT32_MAX +1;
     uint32_t findmax();
 void countingsort(std::vector<T>& arr, uint32_t exp, uint32_t b);
 };
template<typename T,  typename Comparator>
  class  radixsorting :public sortingalgo<Comparator>
 {
 public:
     radixsorting(std::vector<T> v, uint32_t b1, Comparator c) : vec(v),  base(b1)
     {
         this->name = "radixsort";
          this->comparator = c;
     }
     radixsorting(std::vector<T> v, Comparator c) : vec(v)
     {
         this->name = "radixsort";
          this->comparator = c;
     }
     radixsorting( Comparator c)
     {
         this->name = "radixsort";
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t b);
    std::vector<T> getvalues();
 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
     uint32_t base = 10;
 void radixsort(std::vector<T>& arr, uint32_t b);

 };
template<typename T,  typename Comparator>
  class  insertionsorting :public sortingalgo<Comparator>
 {
 public:
     insertionsorting(std::vector<T> v, Comparator c) :vec(v)
     {
         this->name = "insertionsort";
          this->comparator = c;
     }
     insertionsorting(std::vector<T> v, std::function<Comparator> c) :vec(v)
     {
         this->name = "insertionsort";
          this->comparator = c;
     }
     insertionsorting( Comparator c)
     {
         this->name = "insertionsort";
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
      void setvalues(std::vector<T> v);
        std::vector<T> getvalues();
 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
void insertionsort(std::vector<T>& arr);

 };
template<typename T,  typename Comparator>
  class  bucketsorting :public sortingalgo<Comparator>
 {
 public:
     bucketsorting(std::vector<T> v, Comparator c) :vec(v)
     {
         this->name = "bucketsort";
          this->comparator = c;
     }
     bucketsorting( Comparator c)
     {
         this->name = "bucketsort";
          this->comparator = c;
     }
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();
 private:
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
void bucketsort(std::vector<T>& arr);

 };

class horspool: public substringmatching
{
public:
    horspool(std::string l, std::string s):line(l),sample(s){};

     std::string getname() override;
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
     uint32_t memory;

int horspoolmatching(std::string& sample, std::string line);
};
class boyermoor: public substringmatching
{
public:
    boyermoor(std::string l, std::string s):line(l),sample(s){};
     std::string getname() override;
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
     uint32_t memory;
      std::vector<int> suffixes(std::string str);
      int boyermoormatching(std::string sample, std::string line);
};



























#include "algoslib.inl"
#endif // ALGOSLIB_H
