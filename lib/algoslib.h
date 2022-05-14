#ifndef ALGOSLIB_H
#define ALGOSLIB_H

#include "algoslib_global.h"
#include <string>
#include <vector>
#include <memory>

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

    mergesorting()=delete;

    void sort() override;
    std::string getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    ~mergesorting() ;

    static inline mergesorting* GetInstance(std::vector<T> v, Comparator c);
    static inline mergesorting* GetInstance(Comparator c);

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
 class  quicksorting : public sortingalgo<Comparator>
 {
 public:

     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
std::vector<T> getvalues();

~quicksorting();

static inline quicksorting* GetInstance(std::vector<T> v, Comparator c);
static inline quicksorting* GetInstance(Comparator c);

quicksorting(quicksorting<T,Comparator> &other) = delete;
void operator=(const quicksorting<T,Comparator> &) = delete;
protected:
 static inline quicksorting<T,Comparator>* quicksorting_;

 private:

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

     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();
    ~heapsorting();

    static inline heapsorting* GetInstance(std::vector<T> v, Comparator c);
    static inline heapsorting* GetInstance(Comparator c);

    heapsorting(heapsorting<T,Comparator> &other) = delete;
    void operator=(const heapsorting<T,Comparator> &) = delete;
    protected:
     static inline heapsorting<T,Comparator>* heapsorting_;

 private:
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


     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t base);
     void setexp(uint32_t exp);
     std::vector<T> getarray();
     std::vector<T> getvalues();
     ~countingsorting();

     static inline countingsorting* GetInstance(std::vector<T> v, Comparator c);
     static inline countingsorting* GetInstance(Comparator c);
     static inline countingsorting* GetInstance(std::vector<T> v, std::function<Comparator> c);
     countingsorting(countingsorting<T,Comparator> &other) = delete;
     void operator=(const countingsorting<T,Comparator> &) = delete;
     protected:
      static inline countingsorting<T,Comparator>* countingsorting_;


 private:

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
     ~radixsorting();
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
     void setbase(uint32_t b);
    std::vector<T> getvalues();


    static inline radixsorting* GetInstance(std::vector<T> v, Comparator c);
    static inline radixsorting* GetInstance(Comparator c);
    static inline radixsorting* GetInstance(std::vector<T> v, uint32_t b1, Comparator c);

    radixsorting(radixsorting<T,Comparator> &other) = delete;
    void operator=(const radixsorting<T,Comparator> &) = delete;
    protected:
     static inline radixsorting<T,Comparator>* radixsorting_;

 private:
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
     ~insertionsorting();
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
      void setvalues(std::vector<T> v);
        std::vector<T> getvalues();

        static inline insertionsorting* GetInstance(std::vector<T> v, Comparator c);
        static inline insertionsorting* GetInstance(Comparator c);
        static inline insertionsorting* GetInstance(std::vector<T> v, std::function<Comparator> c);

        insertionsorting(insertionsorting<T,Comparator> &other) = delete;
        void operator=(const insertionsorting<T,Comparator> &) = delete;
        protected:
         static inline insertionsorting<T,Comparator>* insertionsorting_;

 private:
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
     std::string name;
     uint32_t memory;
     std::vector<T> vec;
void insertionsort(std::vector<T>& arr);

 };
template<typename T,  typename Comparator>
  class  bucketsorting :public sortingalgo<Comparator>
 {
 public:
    ~bucketsorting();
     void sort() override;
     std::string getname() override;
     uint32_t getmemory() override;
    std::vector<T> getvalues();

    static inline bucketsorting* GetInstance(std::vector<T> v, Comparator c);
    static inline bucketsorting* GetInstance(Comparator c);


    bucketsorting(bucketsorting<T,Comparator> &other) = delete;
    void operator=(const bucketsorting<T,Comparator> &) = delete;
    protected:
     static inline bucketsorting<T,Comparator>* bucketsorting_;

 private:
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
