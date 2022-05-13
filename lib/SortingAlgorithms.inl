#pragma once

#ifndef SORTINGALGORITHMS_INL
#define SORTINGALGORITHMS_INL

#include <iostream>
#include <cassert>
#include "SortingAlgorithms.h"


template <typename T, typename Comparator>
void CombSort<T, Comparator>::sort(T* arr, std::size_t size, Comparator comparator) {
    assert(arr);
    if (size <= 1) {
        return;
    }

    const double shrink_factor = 1.247;
    std::size_t comparing_distance = size;
    bool is_sorted = false;

    while (!is_sorted) {
        comparing_distance /= shrink_factor;

        if (comparing_distance <= 1) {
            comparing_distance = 1;
            is_sorted = true; // it is flag for "buble sort"-pass to detect if array is sorted
        }

        // one pass over array
        for (std::size_t i = 0; i + comparing_distance < size; i++) {
            if (!comparator(arr[i], arr[i + comparing_distance])) { // if not in correct order
                std::swap(arr[i], arr[i + comparing_distance]);
                is_sorted = false;
            }
        }

    }
}
// Algorithm of combsort: https://en.wikipedia.org/wiki/Comb_sort



template <typename T, typename Comparator>
void ShellSort<T, Comparator>::sort(std::vector<T>vec, Comparator comparator) {

    const auto size = vec.size();
    T*arr = &vec[0];

    const std::size_t gaps_number = 8;
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

    for (std::size_t k = 0; k < gaps_number; k++) {
        int gap = gaps[k];

        for (std::size_t offset = 0; offset < gap; offset++) {
            for (std::size_t i = offset; i < size; i+= gap) {

                if (i != offset) { // if not 1st item of subarray
                    T temp = arr[i];

                    //choose place to insert
                    int j = i;
                    for (; j >= gap && !comparator(arr[j - gap], temp); j-=gap) {
                        arr[j] = arr[j - gap];
                    }
                    arr[j] = temp;
                }

            }
        }
    }
}
// Algorithm of shellsort: https://en.wikipedia.org/wiki/Shellsort

template <typename T, typename Comparator>
void ShellSort<T, Comparator>::sortInsertion(T* arr, std::size_t size, Comparator comparator) {
    const std::size_t gaps_number = 1;
    int gaps[] = { 1 };

    for (std::size_t k = 0; k < gaps_number; k++) {
        int gap = gaps[k];

        for (std::size_t offset = 0; offset < gap; offset++) {
            for (std::size_t i = offset; i < size; i += gap) {

                if (i != offset) { // if not 1st item of subarray
                    T temp = arr[i];

                    //choose place to insert
                    int j = i;
                    for (; j >= gap && !comparator(arr[j - gap], temp); j -= gap) {
                        arr[j] = arr[j - gap];
                    }
                    arr[j] = temp;
                }

            }
        }
    }
}



template <typename T, typename Comparator>
void OddEvenSort<T, Comparator>::sort(T* arr, std::size_t size, Comparator comparator) {
    bool is_sorted = false;

    while (!is_sorted) {
        is_sorted = true;

        // odd pass
        for (std::size_t i = 1; i < size - 1; i += 2) {
            if (!comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                is_sorted = false;
            }
        }

        // even pass
        for (std::size_t i = 0; i < size - 1; i += 2) {
            if (!comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                is_sorted = false;
            }
        }
    }
}
// Algorithm of odd-even sort: https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort




template <typename T, typename Comparator>
void CocktailShakerSort<T, Comparator>::sort(T* arr, std::size_t size, Comparator comparator) {
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (std::size_t i = 0; i < size - 1; i++) {
            if (!comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                is_sorted = false;
            }
        }

        if (is_sorted) {
            break;
        }

        is_sorted = true;
        for (int i = size - 2; i >= 0; i--) {
            if (!comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                is_sorted = false;
            }
        }
    }
}
// Algorithm of cocktail shaker sort: https://en.wikipedia.org/wiki/Cocktail_shaker_sort




template <typename T, typename Comparator>
void TimSort<T, Comparator>::sort(T* arr, std::size_t size, Comparator comparator) {
    if (size <= 1) {
        return;
    }

    assert(arr);
    this->comparator = comparator;
    if (size < 64) {
        insertionSort(arr, 0, size - 1, comparator);
        return;
    }
    std::size_t min_run_size = getMinRunSize(size);
    std::vector<Run> runs;// ((size - 1) / min_run_size + 1);

    // split array on runs
    for (std::size_t i = 0; i < size; i++) {

        std::size_t run_start = i;
        while (i < size - 1 && comparator(arr[i], arr[i + 1])) {
            i++;
        }

        std::size_t current_run_size = i - run_start + 1;
        if (current_run_size < min_run_size) {
            current_run_size = std::min(min_run_size, size - run_start);
            i = run_start + current_run_size - 1;
            insertionSort(arr, run_start, i, comparator);
        }

        runs.push_back(Run(run_start, current_run_size));

        if (current_run_size > min_run_size) { // for not to do many mergins when it isn't any sorted subarrays
            tryMerge(arr, runs);
        }


        // i - is last item included in current run, so we need to i++, because at new iteration we must see first item of new run
    }

    fullMerge(arr, runs);
}
/*
    Idea & example of TimSort: https://ru.wikipedia.org/wiki/Timsort, http://cppalgo.blogspot.com/2011/12/tim-sort.html
    https://neerc.ifmo.ru/wiki/index.php?title=Timsort, https://medium.com/@rylanbauermeister/understanding-timsort-191c758a42f3
    https://www.geeksforgeeks.org/timsort/ - there algorithm is simply divide into equal-size runs and merge them
    https://habr.com/ru/company/otus/blog/565640/, https://habr.com/ru/company/infopulse/blog/133303/
    https://www.javatpoint.com/tim-sort

*/
template <typename T, typename Comparator>
std::size_t TimSort<T, Comparator>::getMinRunSize(std::size_t n) {
    unsigned int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}


template <typename T, typename Comparator>
void TimSort<T, Comparator>::insertionSort(T* arr, std::size_t start, std::size_t end, Comparator comparator) {

    for (std::size_t i = start + 1; i <= end; i++) {
        T temp = arr[i];

        // choose place to insert
        int j = i;
        while (j > start && !comparator(arr[j - 1], temp)) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }


}

template <typename T, typename Comparator>
void TimSort<T, Comparator>::tryMerge(T* arr, std::vector<Run>& runs) {
    if (runs.size() < 3) {
        return;
    }

    Run* x = &runs[runs.size() - 1];
    Run* y = &runs[runs.size() - 2];
    Run* z = &runs[runs.size() - 3];

    while (runs.size() >= 3 && (z->size <= y->size + x->size || y->size <= x->size)) { // if some rule isn't true //// add= in rules

        // need to merge y with min size sibling (x or z)
        if (z->size <= y->size + x->size) {
            if (x->size < z->size) { // merge y and x
                merge(arr, y->begin, y->begin + y->size - 1, x->begin, x->begin + x->size - 1);
                y->size += x->size;
                runs.pop_back(); // remove x
            }
            else { // merge z and y
                merge(arr, z->begin, z->begin + z->size - 1, y->begin, y->begin + y->size - 1);
                z->size += y->size;
                runs.erase(runs.begin() + runs.size() - 2); // remove y
            }
        }
        else { // merge y and x
            merge(arr, y->begin, y->begin + y->size - 1, x->begin, x->begin + x->size - 1);
            y->size += x->size;
            runs.pop_back(); // remove x
        }

        if (runs.size() >= 3) {
            x = &runs[runs.size() - 1];
            y = &runs[runs.size() - 2];
            z = &runs[runs.size() - 3];
        }
    }
}

template <typename T, typename Comparator>
void TimSort<T, Comparator>::fullMerge(T* arr, std::vector<Run>& runs) {
    while (runs.size() > 1) {
        for (std::size_t i = 0; i < runs.size() - 1; i++) { ///// i+=2
            Run& x = runs[i + 1];
            Run& y = runs[i];

            merge(arr, y.begin, y.begin + y.size - 1, x.begin, x.begin + x.size - 1);
            y.size += x.size;
            runs.erase(runs.begin() + i + 1);
        }
    }
}
template <typename T, typename Comparator>
void TimSort<T, Comparator>::merge(T* arr, std::size_t left_begin, std::size_t left_end, std::size_t right_begin, std::size_t right_end) {
    assert(left_end + 1 == right_begin);

    // copy left subarray in the temporary array
    T* temp_array = new T[left_end - left_begin + 1];
    std::copy(arr + left_begin, arr + left_end + 1, temp_array);

    // perform merging two sorted arrays: temp_array[0..left_end - left_begin] and arr[right_begin..right_end] into arr[left_begin..right_end]
    std::size_t i = 0;
    std::size_t j = right_begin;
    std::size_t k = left_begin; // k is index where we need to put next item

    while (i < left_end - left_begin + 1 && j <= right_end) {
        // find min an put in output array
        if (comparator(temp_array[i], arr[j])) {
            arr[k] = temp_array[i];
            i++;
        }
        else {
            arr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i < left_end - left_begin + 1) { // left_begin
        arr[k] = temp_array[i];
        i++;
        k++;
    }

    while (j <= right_end) {
        arr[k] = arr[j];
        j++;
        k++;
    }

    delete[] temp_array;
}
#endif // SORTINGALGORITHMS_INL
