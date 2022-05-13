#pragma once

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <iostream>
#include <vector>

template <typename T>
void print(T* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T, typename Comparator>
class SortingAlgorithm {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) = 0;
    virtual void getName() const = 0;
};


template <typename T, typename Comparator>
class CombSort : public SortingAlgorithm<T, Comparator> {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) override;
    virtual void getName() const override;
};


template <typename T, typename Comparator>
class ShellSort : public SortingAlgorithm<T, Comparator> {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) override;
    virtual void getName() const override;
    void sortInsertion(T* arr, std::size_t size, Comparator comparator);
};

template <typename T, typename Comparator>
class OddEvenSort : public SortingAlgorithm<T, Comparator> {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) override;
};

template <typename T, typename Comparator>
class CocktailShakerSort : public SortingAlgorithm<T, Comparator> {
public:
    virtual void sort(T* arr, std::size_t size, Comparator comparator) override;
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
