
#ifndef ALGOSLIB_H
#define ALGOSLIB_H

#include "algoslib_global.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
class ALGOSLIB_EXPORT  algorithm
{
public:
    algorithm() ;
   virtual std::string getname() = 0;
   virtual std::string gettype() = 0;
   virtual uint32_t getmemory() = 0;
   virtual uint32_t getCounter() = 0;
    virtual void setCounter(const uint32_t count) = 0;
    virtual void run()=0;
   virtual ~algorithm();
};
template<typename Comparator>
class ALGOSLIB_EXPORT sortingalgo:  public algorithm
{
public:

   sortingalgo() ;

   std::string gettype() override;
    uint32_t getCounter() override;
     void setCounter(const uint32_t count) override;


   virtual ~sortingalgo();

protected:
    std::function<Comparator> comparator;
private:
   std::string type;
   uint32_t counter;
};

 class ALGOSLIB_EXPORT substringmatching :public algorithm
{
public:
    substringmatching();
    std::string gettype() override;
    virtual std::string getline()=0;
    virtual std::string getsample()=0;
    virtual void setline(std::string l)=0;
    virtual void setsample(std::string s)=0;
 //   virtual int findfirstsubstr()=0;
    virtual ~substringmatching() {};
    uint32_t getCounter() override;
     void setCounter(const uint32_t count) override;
private:
    std::string type;
    uint32_t counter;
};


template<typename T,  typename Comparator>
class ALGOSLIB_EXPORT mergesorting :  public sortingalgo<Comparator>
{
public:

    mergesorting()=delete;

    void run() override;
    std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    ~mergesorting() ;

    static  mergesorting* GetInstance(std::vector<T> v, Comparator c);
    static  mergesorting* GetInstance(Comparator c);

    mergesorting(mergesorting<T,Comparator> &other) = delete;
    void operator=(const mergesorting<T,Comparator> &) = delete;
 protected:
     static inline mergesorting<T,Comparator>* mergesorting_;
private:

    mergesorting(std::vector<T> v, Comparator c);
   mergesorting(Comparator c);
    std::string name;
    uint32_t memory;
    std::vector<T> vec;
    void mergesort(std::vector<T>& arr, int p, int r);
    void merge(std::vector<T>& arr, int p, int mid, int r);
};





template<typename T,  typename Comparator>
 class ALGOSLIB_EXPORT quicksorting : public sortingalgo<Comparator>
 {
 public:

     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
std::vector<T> getvalues();

~quicksorting();

static  quicksorting* GetInstance(std::vector<T> v, Comparator c);
static  quicksorting* GetInstance(Comparator c);

quicksorting(quicksorting<T,Comparator> &other) = delete;
void operator=(const quicksorting<T,Comparator> &) = delete;
protected:
 static inline quicksorting<T,Comparator>* quicksorting_;

 private:

 quicksorting(std::vector<T> v, Comparator c);
 quicksorting( Comparator c);

     std::string name;
     uint32_t memory;
     std::vector<T> vec;
      int partition(std::vector<T>& arr, int p, int r);

      void quicksort(std::vector<T>& arr, int p, int r);

 };





template<typename T,  typename Comparator>
  class ALGOSLIB_EXPORT heapsorting :public sortingalgo<Comparator>
 {
 public:

     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();
    ~heapsorting();

    static  heapsorting* GetInstance(std::vector<T> v, Comparator c);
    static  heapsorting* GetInstance(Comparator c);

    heapsorting(heapsorting<T,Comparator> &other) = delete;
    void operator=(const heapsorting<T,Comparator> &) = delete;
    protected:
     static inline heapsorting<T,Comparator>* heapsorting_;

 private:
     heapsorting(std::vector<T> v, Comparator c);
     heapsorting( Comparator c);

     std::string name;
     uint32_t memory;
     std::vector<T> vec;
    void maxheapify(std::vector<T>& arr, int i, int p);

      void buildmaxheap(std::vector<T>& arr, int& p);

    void heapsort(std::vector<T>& arr);
 };







template<typename T,  typename Comparator>
  class ALGOSLIB_EXPORT countingsorting :public sortingalgo<Comparator>
 {
 public:


     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t base);
     void setexp(uint32_t exp);
     std::vector<T> getarray();
     std::vector<T> getvalues();
     ~countingsorting();

     static  countingsorting* GetInstance(std::vector<T> v, Comparator c);
     static  countingsorting* GetInstance(Comparator c);
     static  countingsorting* GetInstance(std::vector<T> v, std::function<Comparator> c);
     countingsorting(countingsorting<T,Comparator> &other) = delete;
     void operator=(const countingsorting<T,Comparator> &) = delete;
     protected:
      static inline countingsorting<T,Comparator>* countingsorting_;


 private:

      countingsorting(std::vector<T> v, Comparator c);
      countingsorting( Comparator c);
      countingsorting(std::vector<T> v, std::function<Comparator> c);

     std::string name;
     uint32_t memory;
     std::vector<T> vec;
     uint32_t expon=1;
     uint64_t base = UINT32_MAX +1;
     uint32_t findmax();
 void countingsort(std::vector<T>& arr, uint32_t exp, uint32_t b);
 };


template<typename T,  typename Comparator>
  class ALGOSLIB_EXPORT  radixsorting :public sortingalgo<Comparator>
 {
 public:
     ~radixsorting();
     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t b);
    std::vector<T> getvalues();


    static  radixsorting* GetInstance(std::vector<T> v, Comparator c);
    static  radixsorting* GetInstance(Comparator c);
    static  radixsorting* GetInstance(std::vector<T> v, uint32_t b1, Comparator c);

    radixsorting(radixsorting<T,Comparator> &other) = delete;
    void operator=(const radixsorting<T,Comparator> &) = delete;
    protected:
     static inline radixsorting<T,Comparator>* radixsorting_;

 private:
     radixsorting(std::vector<T> v, uint32_t b1, Comparator c) ;
     radixsorting(std::vector<T> v, Comparator c);
     radixsorting( Comparator c);


     std::string name;
     uint32_t memory;
     std::vector<T> vec;
     uint32_t base = 10;
 void radixsort(std::vector<T>& arr, uint32_t b);

 };
template<typename T,  typename Comparator>
  class ALGOSLIB_EXPORT insertionsorting :public sortingalgo<Comparator>
 {
 public:
     ~insertionsorting();
     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
      void setvalues(std::vector<T> v);
        std::vector<T> getvalues();

        static  insertionsorting* GetInstance(std::vector<T> v, Comparator c);
        static  insertionsorting* GetInstance(Comparator c);
        static  insertionsorting* GetInstance(std::vector<T> v, std::function<Comparator> c);

        insertionsorting(insertionsorting<T,Comparator> &other) = delete;
        void operator=(const insertionsorting<T,Comparator> &) = delete;
        protected:
         static inline insertionsorting<T,Comparator>* insertionsorting_;

 private:
         insertionsorting(std::vector<T> v, Comparator c);
         insertionsorting(std::vector<T> v, std::function<Comparator> c) ;
         insertionsorting( Comparator c);
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
void insertionsort(std::vector<T>& arr);

 };
template<typename T,  typename Comparator>
  class ALGOSLIB_EXPORT bucketsorting :public sortingalgo<Comparator>
 {
 public:
    ~bucketsorting();
     void run() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();

    static  bucketsorting* GetInstance(std::vector<T> v, Comparator c);
    static  bucketsorting* GetInstance(Comparator c);


    bucketsorting(bucketsorting<T,Comparator> &other) = delete;
    void operator=(const bucketsorting<T,Comparator> &) = delete;
    protected:
     static inline bucketsorting<T,Comparator>* bucketsorting_;

 private:
     bucketsorting(std::vector<T> v, Comparator c);
     bucketsorting( Comparator c);
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
void bucketsort(std::vector<T>& arr);

 };

class ALGOSLIB_EXPORT horspool: public substringmatching
{
public:


     std::string getname() override;
     uint32_t getmemory() override;
      std::string getline()override;
      std::string getsample()override;
      void setline(std::string l)override;
      void setsample(std::string s)override;
      void run() override;
       int getId();

       static  horspool* GetInstance(std::string l, std::string s);


       horspool(horspool &other) = delete;
       void operator=(const horspool &) = delete;

       ~horspool()
       {
           this->horspool_ = nullptr;
       }
protected:
       static inline horspool* horspool_;
private:
        horspool(std::string l, std::string s):line(l),sample(s){};
     std::string name;
     std::string line;
     std::string sample;
     uint32_t memory;
    int id;
int horspoolmatching(std::string& sample, std::string line);
};
class ALGOSLIB_EXPORT boyermoor: public substringmatching
{
public:

     std::string getname() override;
     uint32_t getmemory() override;
      std::string getline()override;
      std::string getsample()override;
      void setline(std::string l)override;
      void setsample(std::string s)override;
      void run() override;
      int getId();

      static  boyermoor* GetInstance(std::string l, std::string s);
      boyermoor(horspool &other) = delete;
      void operator=(const boyermoor &) = delete;
      ~boyermoor()
      {
          this->boyermoor_ = nullptr;
      }
protected:
      static inline boyermoor* boyermoor_;
private:
     boyermoor(std::string l, std::string s):line(l),sample(s){};
     std::string name;
     std::string line;
     std::string sample;
     uint32_t memory;
     int id;
      std::vector<int> suffixes(std::string str);
      int boyermoormatching(std::string sample, std::string line);
};








template <typename T>
void print(T* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T, typename Comparator>
class ALGOSLIB_EXPORT CombSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~CombSort();

    static  CombSort* GetInstance(std::vector<T>& v, Comparator c);
    static  CombSort* GetInstance(Comparator c);

    CombSort() = delete;
    CombSort(CombSort<T,Comparator>& other) = delete;
    void operator=(const CombSort<T,Comparator> &) = delete;
protected:
    static inline CombSort<T,Comparator>* combsort_;

private:
    CombSort(std::vector<T>& arr, Comparator comparator);
    CombSort(Comparator comparator);
    void sort(T* arr, std::size_t size);
};


template <typename T, typename Comparator>
class ALGOSLIB_EXPORT ShellSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~ShellSort() override;

    static  ShellSort* GetInstance(std::vector<T>& v, Comparator c);
    static  ShellSort* GetInstance(Comparator c);

    ShellSort() = delete;
    ShellSort(ShellSort<T,Comparator>& other) = delete;
    void operator=(const ShellSort<T,Comparator> &) = delete;
protected:
    static inline ShellSort<T,Comparator>* shellsort_;

private:
    ShellSort(std::vector<T>& arr, Comparator comparator);
    ShellSort(Comparator comparator);
    void sort(T* arr, std::size_t size);
    void sortInsertion(T* arr, std::size_t size);
};

template <typename T, typename Comparator>
class ALGOSLIB_EXPORT OddEvenSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~OddEvenSort() override;

    static  OddEvenSort* GetInstance(std::vector<T>& v, Comparator c);
    static  OddEvenSort* GetInstance(Comparator c);

    OddEvenSort() = delete;
    OddEvenSort(OddEvenSort<T,Comparator>& other) = delete;
    void operator=(const OddEvenSort<T,Comparator> &) = delete;
protected:
    static inline OddEvenSort<T,Comparator>* oddevensort_;

private:
    OddEvenSort(std::vector<T>& arr, Comparator comparator);
    OddEvenSort(Comparator comparator);
    void sort(T* arr, std::size_t size);
};

template <typename T, typename Comparator>
class ALGOSLIB_EXPORT CocktailShakerSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~CocktailShakerSort() override;

    static  CocktailShakerSort* GetInstance(std::vector<T>& v, Comparator c);
    static  CocktailShakerSort* GetInstance(Comparator c);

    CocktailShakerSort() = delete;
    CocktailShakerSort(CocktailShakerSort<T,Comparator> &other) = delete;
    void operator=(const CocktailShakerSort<T,Comparator> &) = delete;
protected:
    static inline CocktailShakerSort<T,Comparator>* cocktailshackersort_;

private:
    CocktailShakerSort(std::vector<T>& arr, Comparator comparator);
    CocktailShakerSort(Comparator comparator);
    void sort(T* arr, std::size_t size);
};

template <typename T, typename Comparator>
class ALGOSLIB_EXPORT TimSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~TimSort() override;

    static  TimSort* GetInstance(std::vector<T>& v, Comparator c);
    static  TimSort* GetInstance(Comparator c);

    TimSort() = delete;
    TimSort(TimSort<T,Comparator> &other) = delete;
    void operator=(const TimSort<T,Comparator> &) = delete;
protected:
    static inline TimSort<T,Comparator>* timsort_;

private:
    TimSort(std::vector<T>& arr, Comparator comparator);
    TimSort(Comparator comparator);
    void sort(T* arr, std::size_t size);
    void insertionSort(T* arr, std::size_t start, std::size_t end);

    struct Run {
        std::size_t begin;
        std::size_t size;

        Run() : begin(0), size(0) {}
        Run(std::size_t begin, std::size_t size) : begin(begin), size(size) {}
    };

    std::size_t getMinRunSize(std::size_t array_size);

    void tryMerge(T* arr, std::vector<Run>& runs);
    void fullMerge(T* arr, std::vector<Run>& runs);
    void merge(T* arr, std::size_t left_begin, std::size_t left_end, std::size_t right_begin, std::size_t right_end);
};

























//#include "algoslib.cpp"
#endif // ALGOSLIB_H
