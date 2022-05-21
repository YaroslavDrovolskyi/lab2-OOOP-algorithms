//#pragma once

//#ifndef ALGOSLIB_INL
//#define ALGOSLIB_INL

#include "algoslib.h"
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <exception>
#include <functional>


algorithm::algorithm() = default;
algorithm::~algorithm() =default ;

template< typename Comparator>
sortingalgo<Comparator>::sortingalgo() { this->type = "sorting"; };
template< typename Comparator>
sortingalgo<Comparator>::~sortingalgo() = default;
template< typename Comparator>
std::string sortingalgo<Comparator>::gettype()
{
    return this->type;
}
template< typename Comparator>
uint32_t sortingalgo<Comparator>::getCounter()
{
    return this->counter;
}
template< typename Comparator>
void sortingalgo<Comparator>::setCounter(const uint32_t count)
{
    this->counter = count;
}

 substringmatching::substringmatching() { this->type = "substringmatching"; };


 uint32_t substringmatching::getCounter()
 {
     return this->counter;
 }

 void substringmatching::setCounter(const uint32_t count)
 {
     this->counter = count;
 }
std::string substringmatching::gettype()
{
    return this->type;
}

template<typename T,  typename Comparator>
void mergesorting<T,Comparator>::merge(std::vector<T>& arr, int p, int mid, int r)
{


    std::vector<T>left(mid - p + 1);
    std::vector<T>right(r - mid);
    int leftsize = mid - p + 1;
    int rightsize = r - mid;

    for (int i = p; i <= mid; i++)
        left[i - p] = arr[i];

    for (int i = mid + 1; i <= r; i++)
        right[i - mid - 1] = arr[i];

    int leftindex = 0, rightindex = 0, arrindex = p;

    while (leftindex < leftsize && rightindex < rightsize)
    {
        if (/*left[leftindex] < right[rightindex]*/ !this->comparator(left[leftindex],right[rightindex]))
        {
            arr[arrindex] = left[leftindex];
            leftindex++;
        }
        else
        {
            arr[arrindex] = right[rightindex];
            rightindex++;
        }
        arrindex++;
    }

    while (leftindex < leftsize)
    {
        arr[arrindex] = left[leftindex];
        leftindex++;
        arrindex++;
    }

    while (rightindex < rightsize)
    {
        arr[arrindex] = right[rightindex];
        rightindex++;
        arrindex++;
    }

}
template<typename T,  typename Comparator>
 mergesorting<T,Comparator>* mergesorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(mergesorting_ == nullptr)
    {
        mergesorting_ = new mergesorting<T,Comparator>(v,c);
    }
    return mergesorting_;
};
template<typename T,  typename Comparator>
 mergesorting<T,Comparator>* mergesorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(mergesorting_ == nullptr)
     {
         mergesorting_ = new mergesorting<T,Comparator>(c);
     }
     return mergesorting_;
 };

template<typename T,  typename Comparator>
void mergesorting<T,Comparator>::mergesort(std::vector<T>& arr, int p, int r)
{
    if (p < r)
    {
        int mid = (p + r) / 2;
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, p, mid, r);
    }
}
template<typename T,  typename Comparator>
void mergesorting<T,Comparator>::run()
{
    int p = 0;
    int len = this->vec.size();
    this->mergesort(this->vec, p, len - 1);


}
template<typename T,  typename Comparator>
std::string mergesorting<T,Comparator>::getname()
{
    return this->name;
}

template<typename T,  typename Comparator>
uint32_t mergesorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
mergesorting<T,Comparator>::mergesorting(std::vector<T> v,Comparator c) :vec(v)
{
    this->name = "mergesort";
    this->comparator = c;
}
template<typename T,  typename Comparator>
mergesorting<T,Comparator>::mergesorting(Comparator c)
{
    this->name = "mergesort";
    this->comparator = c;
}
template<typename T,  typename Comparator>
mergesorting<T,Comparator>::~mergesorting() {mergesorting_ = nullptr;};

template<typename T,  typename Comparator>
std::vector<T> mergesorting<T,Comparator>::getvalues()
{
    return this->vec;
}


template<typename T,  typename Comparator>
 quicksorting<T,Comparator>* quicksorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(quicksorting_ == nullptr)
    {
        quicksorting_ = new quicksorting<T,Comparator>(v,c);
    }
    return quicksorting_;
};
template<typename T,  typename Comparator>
 quicksorting<T,Comparator>* quicksorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(quicksorting_ == nullptr)
     {
         quicksorting_ = new quicksorting<T,Comparator>(c);
     }
     return quicksorting_;
 };
 template<typename T,  typename Comparator>
quicksorting<T,Comparator>::~quicksorting()
{
    quicksorting_ = nullptr;
}
template<typename T,  typename Comparator>
quicksorting<T,Comparator>::quicksorting(std::vector<T> v, Comparator c) :vec(v)
{
    this->name = "quicksort";
     this->comparator = c;
}
template<typename T,  typename Comparator>
quicksorting<T,Comparator>::quicksorting( Comparator c)
{
    this->name = "quicksort";
     this->comparator = c;
}


template<typename T,  typename Comparator>
int quicksorting<T,Comparator>::partition(std::vector<T>& arr, int p, int r)
{

    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (/*arr[j] <= arr[r]*/ !this->comparator(arr[j],arr[r]) )
        {
            i++;
            float temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    T temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}

template<typename T,  typename Comparator>
void quicksorting<T,Comparator>::quicksort(std::vector<T>& arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

template<typename T,  typename Comparator>
std::string quicksorting<T,Comparator>::getname()
{
    return this->name;
}


template<typename T,  typename Comparator>
uint32_t quicksorting<T,Comparator>::getmemory()
{
    return this->memory;
}

template<typename T,  typename Comparator>
void quicksorting<T,Comparator>::run()
{
    int p = 0;
    int len = this->vec.size();
   // this->quicksort(this->vec, p, len - 1);
    this->quicksort(this->vec,p,len-1);

}

template<typename T,  typename Comparator>
std::vector<T> quicksorting<T,Comparator>::getvalues()
{
    return this->vec;
}





template<typename T,  typename Comparator>
 heapsorting<T,Comparator>* heapsorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(heapsorting_ == nullptr)
    {
        heapsorting_ = new heapsorting<T,Comparator>(v,c);
    }
    return heapsorting_;
};
template<typename T,  typename Comparator>
 heapsorting<T,Comparator>* heapsorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(heapsorting_ == nullptr)
     {
         heapsorting_ = new heapsorting<T,Comparator>(c);
     }
     return heapsorting_;
 };
 template<typename T,  typename Comparator>
heapsorting<T,Comparator>::~heapsorting()
{
    heapsorting_ = nullptr;
}

template<typename T,  typename Comparator>
heapsorting<T,Comparator>::heapsorting(std::vector<T> v, Comparator c):vec(v)
{
    this->name = "heapsort";
     this->comparator = c;
}
template<typename T,  typename Comparator>
heapsorting<T,Comparator>::heapsorting( Comparator c)
{
    this->name = "heapsort";
     this->comparator = c;
}
template<typename T,  typename Comparator>
std::string heapsorting<T,Comparator>::getname()
{
    return this->name;
}

template<typename T,  typename Comparator>
uint32_t heapsorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
void heapsorting<T,Comparator>::run()
{

   // this->heapsort(this->vec);
    this->heapsort(this->vec);

}
template<typename T,  typename Comparator>
std::vector<T> heapsorting<T,Comparator>::getvalues()
{
    return this->vec;
}
template<typename T,  typename Comparator>
void heapsorting<T,Comparator>::maxheapify(std::vector<T>& arr, int i, int p)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max = i;
    if (left < p && /*arr[left] > arr[max]*/ this->comparator(arr[left],arr[max]) )
    {
        max = left;
    }
    if (right < p && /*arr[right] > arr[max]*/ this->comparator(arr[right],arr[max]))
        max = right;

    if (max != i)
    {
        T temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        maxheapify(arr, max, p);
    }
}
template<typename T,  typename Comparator>
void heapsorting<T,Comparator>::buildmaxheap(std::vector<T>& arr, int& p)
{
    int size = arr.size();
    for (int i = size / 2; i >= 0; i--)
    {
        maxheapify(arr, i, p);
    }
}
template<typename T,  typename Comparator>
void heapsorting<T,Comparator>::heapsort(std::vector<T>& arr)
{
    int size = arr.size();
    int p = arr.size();
    buildmaxheap(arr, p);
    for (int i = size - 1; i >= 1; i--)
    {
        T temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        p--;
        maxheapify(arr, 0, p);
    }
}

int getMax(std::vector<uint32_t>arr)
{
    int max = arr[0];
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<typename T,  typename Comparator>
 countingsorting<T,Comparator>::countingsorting(std::vector<T> v, Comparator c): vec(v)
{
    this->name = "countingsort";
    this->base = findmax() + 1;
     this->comparator = c;
}
 template<typename T,  typename Comparator>
  countingsorting<T,Comparator>::countingsorting( Comparator c)
{
    this->name = "countingsort";
    this->base = findmax() + 1;
     this->comparator = c;
}
  template<typename T,  typename Comparator>
   countingsorting<T,Comparator>::countingsorting(std::vector<T> v, std::function<Comparator> c): vec(v)
{
    this->name = "countingsort";
    this->base = findmax() + 1;
     this->comparator = c;
}

template<typename T,  typename Comparator>
 countingsorting<T,Comparator>* countingsorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(countingsorting_ == nullptr)
    {
        countingsorting_ = new countingsorting<T,Comparator>(v,c);
    }
    return countingsorting_;
};
template<typename T,  typename Comparator>
 countingsorting<T,Comparator>* countingsorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(countingsorting_ == nullptr)
     {
         countingsorting_ = new countingsorting<T,Comparator>(c);
     }
     return countingsorting_;
 };
 template<typename T,  typename Comparator>
countingsorting<T,Comparator>* countingsorting<T,Comparator>::GetInstance(std::vector<T> v, std::function<Comparator> c)
 {
    if(countingsorting_ == nullptr)
    {
        countingsorting_ = new countingsorting<T,Comparator>(v,c);
    }
    return countingsorting_;
 }

 template<typename T,  typename Comparator>
countingsorting<T,Comparator>::~countingsorting()
{
   countingsorting_ = nullptr;
}


template<typename T,  typename Comparator>
void countingsorting<T,Comparator>::countingsort(std::vector<T>& arr, uint32_t exp, uint32_t b)
{
    int size = arr.size();
    std::vector<int>count(b, 0);
    //int out[size]{0};
    std::vector<uint32_t>out(size, 0);
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % b]++;
    for (int i = 1; i < b; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        out[count[(arr[i] / exp) % b] - 1] = arr[i];
        count[(arr[i] / exp) % b]--;
    }


//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = out[i];
//    }

    if(!this->comparator(1,2))
    for (int i = 0; i < size; i++)
    {
        arr[i] = out[i];
    }
    else
        for (int i = 0; i < size; i++)
        {
            arr[i] = out[size - i -1];
        }


}
template<typename T,  typename Comparator>
std::string countingsorting<T,Comparator>::getname()
{
    return this->name;
}
template<typename T,  typename Comparator>
uint32_t countingsorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
void countingsorting<T,Comparator>::run()
{
   // this->countingsort(this->vec,this->expon, this->base);

   this->countingsort(this->vec,this->expon,this->base);
}
template<typename T,  typename Comparator>
void countingsorting<T,Comparator>::setbase(uint32_t b)
{
    this->base = b;
}
template<typename T,  typename Comparator>
void countingsorting<T,Comparator>::setexp(uint32_t exp)
{
    this->expon = exp;
}
//std::vector<uint32_t> countingsorting::getarray()
//{
//    return this->vec;
//}
template<typename T,  typename Comparator>
 uint32_t countingsorting<T,Comparator>::findmax()
 {

         if(this->vec.size()==0)
             throw std::out_of_range("Size of vector is equal to zero");
     uint32_t maxval = this->vec[0];

     for(auto i=1; i<this->vec.size();i++)
         if(this->vec[i] > maxval)
             maxval =this->vec[i];
     return maxval;


 }
template<typename T,  typename Comparator>
 std::vector<T> countingsorting<T,Comparator>::getvalues()
 {
     return this->vec;
 }
template<typename T,  typename Comparator>
 void radixsorting<T,Comparator>::radixsort(std::vector<T>& arr, uint32_t b)
 {
     int max = getMax(arr);
     countingsorting<T,Comparator>* cs =  countingsorting<T,Comparator>::GetInstance(arr,this->comparator);

     cs->setbase(b);
     for (int exp = 1; max / exp > 0; exp *= b)
     {

         cs->setexp(exp);
         cs->run();
     }
     this->vec = cs->getvalues();
     delete cs;
 }



 template<typename T,  typename Comparator>
  radixsorting<T,Comparator>* radixsorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
 {
     if(radixsorting_ == nullptr)
     {
         radixsorting_ = new radixsorting<T,Comparator>(v,c);
     }
     return radixsorting_;
 };
 template<typename T,  typename Comparator>
  radixsorting<T,Comparator>* radixsorting<T,Comparator>::GetInstance(Comparator c)
  {
      if(radixsorting_ == nullptr)
      {
          radixsorting_ = new radixsorting<T,Comparator>(c);
      }
      return radixsorting_;
  };
  template<typename T,  typename Comparator>
 radixsorting<T,Comparator>* radixsorting<T,Comparator>::GetInstance(std::vector<T> v, uint32_t b1, Comparator c)
  {
     if(radixsorting_ == nullptr)
     {
         radixsorting_ = new radixsorting<T,Comparator>(v,b1,c);
     }
     return radixsorting_;
  }
 template<typename T,  typename Comparator>
radixsorting<T,Comparator>::radixsorting(std::vector<T> v, uint32_t b1, Comparator c) : vec(v),  base(b1)
 {
     this->name = "radixsort";
      this->comparator = c;
 }
template<typename T,  typename Comparator>
radixsorting<T,Comparator>::radixsorting(std::vector<T> v, Comparator c) : vec(v)
 {
     this->name = "radixsort";
      this->comparator = c;
 }
template<typename T,  typename Comparator>
radixsorting<T,Comparator>::radixsorting( Comparator c)
 {
     this->name = "radixsort";
      this->comparator = c;
 }
  template<typename T,  typename Comparator>
 radixsorting<T,Comparator>::~radixsorting()
 {
    radixsorting_ = nullptr;
 }

 template<typename T,  typename Comparator>
std::string radixsorting<T,Comparator>::getname()
{
    return this->name;
}

template<typename T,  typename Comparator>
uint32_t radixsorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
void radixsorting<T,Comparator>::run()
{
   // this->radixsort(this->vec, this->base);
    this->radixsort(this->vec,this->base);
}
template<typename T,  typename Comparator>
void radixsorting<T,Comparator>::setbase(uint32_t b)
{
    this->base = b;
}
template<typename T,  typename Comparator>
std::vector<T> radixsorting<T,Comparator>::getvalues()
{
    return this->vec;
}



template<typename T,  typename Comparator>
 insertionsorting<T,Comparator>* insertionsorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(insertionsorting_ == nullptr)
    {
        insertionsorting_ = new insertionsorting<T,Comparator>(v,c);
    }
    return insertionsorting_;
};
template<typename T,  typename Comparator>
 insertionsorting<T,Comparator>* insertionsorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(insertionsorting_ == nullptr)
     {
         insertionsorting_ = new insertionsorting<T,Comparator>(c);
     }
     return insertionsorting_;
 };
 template<typename T,  typename Comparator>
insertionsorting<T,Comparator>* insertionsorting<T,Comparator>::GetInstance(std::vector<T> v, std::function<Comparator> c)
 {
    if(insertionsorting_ == nullptr)
    {
        insertionsorting_ = new insertionsorting<T,Comparator>(v,c);
    }
    return insertionsorting_;
 }
template<typename T,  typename Comparator>
insertionsorting<T,Comparator>::insertionsorting(std::vector<T> v, Comparator c) :vec(v)
{
    this->name = "insertionsort";
     this->comparator = c;
}
template<typename T,  typename Comparator>
insertionsorting<T,Comparator>::insertionsorting(std::vector<T> v, std::function<Comparator> c) :vec(v)
{
    this->name = "insertionsort";
     this->comparator = c;
}
template<typename T,  typename Comparator>
insertionsorting<T,Comparator>::insertionsorting( Comparator c)
{
    this->name = "insertionsort";
     this->comparator = c;
}
 template<typename T,  typename Comparator>
insertionsorting<T,Comparator>::~insertionsorting()
{
   insertionsorting_ = nullptr;
}


template<typename T,  typename Comparator>
std::string insertionsorting<T,Comparator>::getname()
{
    return this->name;
}


template<typename T,  typename Comparator>
uint32_t insertionsorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
void insertionsorting<T,Comparator>::run()
{
   // this->insertionsort(this->vec);
    this->insertionsort(this->vec);

}
template<typename T,  typename Comparator>
void insertionsorting<T,Comparator>::insertionsort(std::vector<T>&arr)
{
    if (!arr.size())
        return;
    int len = arr.size();
    int i, j;
    float k;
    for (i = 1; i < len; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && /*arr[j] > k*/ this->comparator(arr[j],k))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}
template<typename T,  typename Comparator>
std::vector<T> insertionsorting<T,Comparator>::getvalues()
{
    return this->vec;
}
template<typename T,  typename Comparator>
void insertionsorting<T,Comparator>::setvalues(std::vector<T> v)
{
    this->vec = v;
}
template<typename T,  typename Comparator>
std::string bucketsorting<T,Comparator>::getname()
{
    return this->name;
}

template<typename T,  typename Comparator>
uint32_t bucketsorting<T,Comparator>::getmemory()
{
    return this->memory;
}
template<typename T,  typename Comparator>
void bucketsorting<T,Comparator>::bucketsort(std::vector<T>& arr)
{
    int len = arr.size();         //add exception if len ==0

    std::vector<std::vector<T>> out(len, std::vector<T>());

    for (int i = 0; i < len; i++) {

        out[len * arr[i]].push_back(arr[i]);
    }

    insertionsorting<T,Comparator>* inss = insertionsorting<T,Comparator>::GetInstance(out[0],this->comparator);         //check
    for (int i = 0; i < len; i++)
    {
        inss->setvalues(out[i]);
        inss->run();
        out[i] = inss->getvalues();
    }
delete inss;
    int k = 0;
    if(!this->comparator(1,2)) //checking order of sorting
    for (int i = 0; i < len; i++)
    {
        int sublen = out[i].size();
        for (int j = 0; j < sublen; j++)
        {
            arr[k] = out[i][j];
            k++;
        }
    }
    else                   //check
        for (int i = len-1; i >=0; i--)
        {
            int sublen = out[i].size();
            for (int j = 0; j <sublen; j++)
            {
                arr[k] = out[i][j];
                k++;
            }
        }


}

template<typename T,  typename Comparator>
 bucketsorting<T,Comparator>* bucketsorting<T,Comparator>::GetInstance(std::vector<T> v, Comparator c)
{
    if(bucketsorting_ == nullptr)
    {
        bucketsorting_ = new bucketsorting<T,Comparator>(v,c);
    }
    return bucketsorting_;
};
template<typename T,  typename Comparator>
 bucketsorting<T,Comparator>* bucketsorting<T,Comparator>::GetInstance(Comparator c)
 {
     if(bucketsorting_ == nullptr)
     {
         bucketsorting_ = new bucketsorting<T,Comparator>(c);
     }
     return bucketsorting_;
 };

 template<typename T,  typename Comparator>
bucketsorting<T,Comparator>::bucketsorting(std::vector<T> v, Comparator c) :vec(v)
 {
     this->name = "bucketsort";
      this->comparator = c;
 }
 template<typename T,  typename Comparator>
bucketsorting<T,Comparator>::bucketsorting( Comparator c)
 {
     this->name = "bucketsort";
      this->comparator = c;
 }
 template<typename T,  typename Comparator>
bucketsorting<T,Comparator>::~bucketsorting()
{
    bucketsorting_ = nullptr;
}

template<typename T,  typename Comparator>
std::vector<T> bucketsorting<T,Comparator>::getvalues()
{
    return this->vec;
}
template<typename T,  typename Comparator>
void bucketsorting<T,Comparator>::run()
{
  //  this->bucketsort(this->vec);
    this->bucketsort(this->vec);
}



std::map<char, int> shifttable(std::string& str)
{
    int len = str.size();

    std::map<char, int> table;
    for (int i = 0; i < len; i++)
    {
        if (i != len - 1 || table.find(str[i]) == table.end())
            table.insert_or_assign(str[i], len - i - 1);


    }
    return table;
}


horspool* horspool::GetInstance(std::string l, std::string s)
{
    if(horspool_ == nullptr)
    {
        horspool_ = new horspool(l,s);
    }
    return horspool_;
};

std::string horspool::getname()
{
    return this->name;
};

uint32_t horspool::getmemory()
{
    return this->memory;
};
 std::string horspool::getline()
 {
     return this->line;
 };
 std::string horspool::getsample()
 {
     return this->sample;
 };
 void horspool:: setline(std::string l)
 {
     this->line=l;
 };
 void horspool::setsample(std::string s)
 {
     this->sample = s;
 };
 void horspool::run()
 {
    // return this->horspoolmatching(this->sample, this->line);
     this->id =  this->horspoolmatching(this->sample,this->line);
 };

 int horspool::horspoolmatching(std::string& sample, std::string line)
 {
     std::map<char, int> table = shifttable(sample);

     int samplesize = sample.size();
     int linesize = line.size();

     int i = samplesize - 1;
     while (i < linesize)
     {

         for (int j = 0; j < samplesize; j++)
         {
             if (sample[samplesize - j - 1] != line[i - j])
             {
                 if (table.find(line[i - j]) == table.end())
                     i += samplesize;
                 else i += table.find(line[i])->second;
                 break;
             }
             else if (j == samplesize - 1)
                 return i - samplesize + 1;


         }
     }
     return -1;
 }

 int horspool::getId(){return this->id;}


 boyermoor* boyermoor::GetInstance(std::string l, std::string s)
 {
     if(boyermoor_ == nullptr)
     {
         boyermoor_ = new boyermoor(l,s);
     }
     return boyermoor_;
 };

std::vector<int> boyermoor::suffixes(std::string str)
{
    int size = str.size();
    std::vector<int> suff(size);
    //suff[0] = size;
    for (int i = 1; i < size; i++)
    {
        int left = i - 1;
        int right = size - i;
        while (left >= 0 && left >= right)
            left--;

        for (int n = 0; n <= left; n++)
            if (str[left - n] != str[size - 1 - n])
            {
                left--;
                n = 0;
            }
            else if (n == left)
                suff[i] = size - 1 - left;
    }
    return suff;
}

int  boyermoor::boyermoormatching(std::string sample, std::string line)
{
    std::map<char, int> table = shifttable(sample);
    std::vector<int> suff = suffixes(sample);

    int samplesize = sample.size();
    int linesize = line.size();

    int i = samplesize - 1;
    while (i < linesize)
    {
        for (int j = 0; j < samplesize; j++)
        {
            int hor;
            int s;
            if (sample[samplesize - j - 1] != line[i - j])
            {
                s = suff[j];
                if (table.find(line[i - j]) == table.end())
                    hor = samplesize;
                else hor = table.find(line[i])->second;
                i += (hor < s) ? s : hor;
                break;
            }
            else if (j == samplesize - 1)
                return i - samplesize + 1;


        }
    }
    return -1;

}

std::string boyermoor::getname()
{
    return this->name;
};

uint32_t boyermoor::getmemory()
{
    return this->memory;
};
 std::string boyermoor::getline()
 {
     return this->line;
 };
 std::string boyermoor::getsample()
 {
     return this->sample;
 };
 void boyermoor:: setline(std::string l)
 {
     this->line=l;
 };
 void boyermoor::setsample(std::string s)
 {
     this->sample = s;
 };
 void boyermoor::run()
 {
     //return this->boyermoormatching(this->sample, this->line);
     this->id =  this->boyermoormatching(this->sample,this->line);
 };

 int boyermoor::getId(){return this->id;}


 template class sortingalgo<bool(float, float)>;
 template class sortingalgo<bool(int, int)>;
 template class sortingalgo<bool(double, double)>;
 template class sortingalgo<bool(uint32_t, uint32_t)>;

 template class mergesorting<float,bool(float, float)>;
 template class mergesorting<int,bool(int, int)>;
 template class mergesorting<double,bool(double, double)>;
 template class mergesorting<uint32_t,bool(uint32_t, uint32_t)>;

 template class quicksorting<float,bool(float, float)>;
 template class quicksorting<int,bool(int, int)>;
 template class quicksorting<double,bool(double, double)>;
 template class quicksorting<uint32_t,bool(uint32_t, uint32_t)>;

 template class heapsorting<float,bool(float, float)>;
 template class heapsorting<int,bool(int, int)>;
 template class heapsorting<double,bool(double, double)>;
 template class heapsorting<uint32_t,bool(uint32_t, uint32_t)>;


 template class countingsorting<uint32_t,bool(uint32_t, uint32_t)>;

 template class radixsorting<uint32_t,bool(uint32_t, uint32_t)>;

 template class insertionsorting<float,bool(float, float)>;
 template class insertionsorting<int,bool(int, int)>;
 template class insertionsorting<double,bool(double, double)>;
 template class insertionsorting<uint32_t,bool(uint32_t, uint32_t)>;

 template class bucketsorting<float,bool(float, float)>;
 template class bucketsorting<int,bool(int, int)>;
 template class bucketsorting<double,bool(double, double)>;
 template class bucketsorting<uint32_t,bool(uint32_t, uint32_t)>;
//#endif
