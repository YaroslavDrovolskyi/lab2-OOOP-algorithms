#pragma once

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H


#include <iostream>
#include <vector>
#include "algoslib.h"


template <typename T>
void print(T* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*
template <typename T, typename Comparator>
class SortingAlgorithm {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) = 0;
    virtual void getName() const = 0;
};
*/

/*
template<typename T,  typename Comparator>
class ALGOSLIB_EXPORT mergesorting :  public sortingalgo<Comparator>
{
public:

+    mergesorting()=delete;

+    void run() override;
+    std::string getname() override;
+    uint32_t getmemory() override;
+    std::vector<T> getvalues();
+    ~mergesorting() ;

+    static  mergesorting* GetInstance(std::vector<T> v, Comparator c);
+    static  mergesorting* GetInstance(Comparator c);

+    mergesorting(mergesorting<T,Comparator> &other) = delete;
+    void operator=(const mergesorting<T,Comparator> &) = delete;
 protected:
+     static inline mergesorting<T,Comparator>* mergesorting_;
private:

+    mergesorting(std::vector<T> v, Comparator c);
+    mergesorting(Comparator c);
+    std::string name;
+    uint32_t memory;
+    std::vector<T> vec;
+    void mergesort(std::vector<T>& arr, int p, int r);
+    void merge(std::vector<T>& arr, int p, int mid, int r);
};


*/
template <typename T, typename Comparator>
class ALGOSLIB_EXPORT CombSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual void getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~CombSort() override;

    static  CombSort* GetInstance(std::vector<T> v, Comparator c);
    static  CombSort* GetInstance(Comparator c);

    CombSort() = delete;
    CombSort(CombSort<T,Comparator> &other) = delete;
    void operator=(const CombSort<T,Comparator> &) = delete;
protected:
    static inline CombSort<T,Comparator>* combsort_;

private:
    CombSort(std::vector<T>& arr, Comparator comparator);
    CombSort(Comparator comparator);
    void sort(T* arr, std::size_t size, Comparator comparator);
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
    virtual void getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~ShellSort() override;

    static  ShellSort* GetInstance(std::vector<T> v, Comparator c);
    static  ShellSort* GetInstance(Comparator c);

    ShellSort() = delete;
    ShellSort(ShellSort<T,Comparator> &other) = delete;
    void operator=(const ShellSort<T,Comparator> &) = delete;
protected:
    static inline ShellSort<T,Comparator>* shellsort_;

private:
    ShellSort(std::vector<T>& arr, Comparator comparator);
    ShellSort(Comparator comparator);
    void sort(T* arr, std::size_t size, Comparator comparator);
    void sortInsertion(T* arr, std::size_t size, Comparator comparator);
};

template <typename T, typename Comparator>
class OddEvenSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual void getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~OddEvenSort() override;

    static  OddEvenSort* GetInstance(std::vector<T> v, Comparator c);
    static  OddEvenSort* GetInstance(Comparator c);

    OddEvenSort() = delete;
    OddEvenSort(OddEvenSort<T,Comparator> &other) = delete;
    void operator=(const OddEvenSort<T,Comparator> &) = delete;
protected:
    static inline OddEvenSort<T,Comparator>* oddevensort_;

private:
    OddEvenSort(std::vector<T>& arr, Comparator comparator);
    OddEvenSort(Comparator comparator);
    void sort(T* arr, std::size_t size, Comparator comparator);
};

template <typename T, typename Comparator>
class CocktailShakerSort : public sortingalgo<Comparator> {
private:
    std::string name;
    uint32_t memory;

    T* arr;
    std::size_t size;

public:
    virtual void run() override;
    virtual void getname() override;
    uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~CocktailShakerSort() override;

    static  CocktailShakerSort* GetInstance(std::vector<T> v, Comparator c);
    static  CocktailShakerSort* GetInstance(Comparator c);

    CocktailShakerSort() = delete;
    CocktailShakerSort(CocktailShakerSort<T,Comparator> &other) = delete;
    void operator=(const CocktailShakerSort<T,Comparator> &) = delete;
protected:
    static inline CocktailShakerSort<T,Comparator>* cocktailshackersort_;

private:
    CocktailShakerSort(std::vector<T>& arr, Comparator comparator);
    CocktailShakerSort(Comparator comparator);
    void sort(T* arr, std::size_t size, Comparator comparator);
};

template <typename T, typename Comparator>
class TimSort : public SortingAlgorithm<T, Comparator> {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) override;
    void insertionSort(T* arr, std::size_t start, std::size_t end, Comparator comparator);



private:
    struct Run {
        std::size_t begin;
        std::size_t size;

        Run() : begin(0), size(0) {}
        Run(std::size_t begin, std::size_t size) : begin(begin), size(size) {}
    };
    Comparator comparator;

    std::size_t getMinRunSize(std::size_t array_size);

    void tryMerge(T* arr, std::vector<Run>& runs);
    void fullMerge(T* arr, std::vector<Run>& runs);
    void merge(T* arr, std::size_t left_begin, std::size_t left_end, std::size_t right_begin, std::size_t right_end);
};




#include "SortingAlgorithms.inl"

#endif // SORTINGALGORITHMS_H
