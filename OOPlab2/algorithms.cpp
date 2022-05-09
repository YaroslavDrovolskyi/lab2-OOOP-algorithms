#include "algorithms.h"
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <exception>


algorithm::algorithm() = default;
algorithm::~algorithm() =default ;

sortingalgo::sortingalgo() { this->type = "sorting"; };
sortingalgo::~sortingalgo() = default;

std::string sortingalgo::gettype()
{
    return this->type;
}




std::string substringmatching::gettype()
{
    return this->type;
}


void mergesorting::merge(std::vector<float>& arr, int p, int mid, int r)
{


    std::vector<float>left(mid - p + 1);
    std::vector<float>right(r - mid);
    int leftsize = mid - p + 1;
    int rightsize = r - mid;

    for (int i = p; i <= mid; i++)
        left[i - p] = arr[i];

    for (int i = mid + 1; i <= r; i++)
        right[i - mid - 1] = arr[i];

    int leftindex = 0, rightindex = 0, arrindex = p;

    while (leftindex < leftsize && rightindex < rightsize)
    {
        if (left[leftindex] < right[rightindex])
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


void mergesorting::mergesort(std::vector<float>& arr, int p, int r)
{
    if (p < r)
    {
        int mid = (p + r) / 2;
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, p, mid, r);
    }
}

void mergesorting::sort()
{
    int p = 0;
    int len = this->vec.size();
    this->mergesort(this->vec, p, len - 1);


}

std::string mergesorting::getname()
{
    return this->name;
}

uint32_t mergesorting::gettime()
{
    return this->time;
}

uint32_t mergesorting::getmemory()
{
    return this->memory;
}

mergesorting::mergesorting(std::vector<float> v) :vec(v)
{
    this->name = "mergesort";
}

mergesorting::mergesorting()
{
    this->name = "mergesort";
}

mergesorting::~mergesorting() {};


std::vector<float> mergesorting::getvalues()
{
    return this->vec;
}

int quicksorting::partition(std::vector<float>& arr, int p, int r)
{

    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= arr[r])
        {
            i++;
            float temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    float temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}

void quicksorting::quicksort(std::vector<float>& arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}


std::string quicksorting::getname()
{
    return this->name;
}

uint32_t quicksorting::gettime()
{
    return this->time;
}

uint32_t quicksorting::getmemory()
{
    return this->memory;
}


void quicksorting::sort()
{
    int p = 0;
    int len = this->vec.size();
   // this->quicksort(this->vec, p, len - 1);
    this->quicksort(this->vec,p,len-1);

}

std::vector<float> quicksorting::getvalues()
{
    return this->vec;
}



std::string heapsorting::getname()
{
    return this->name;
}

uint32_t heapsorting::gettime()
{
    return this->time;
}

uint32_t heapsorting::getmemory()
{
    return this->memory;
}

void heapsorting::sort()
{

   // this->heapsort(this->vec);
    this->heapsort(this->vec);

}

std::vector<float> heapsorting::getvalues()
{
    return this->vec;
}

void heapsorting::maxheapify(std::vector<float>& arr, int i, int p)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max = i;
    if (left < p && arr[left] > arr[max])
    {
        max = left;
    }
    if (right < p && arr[right] > arr[max])
        max = right;

    if (max != i)
    {
        float temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        maxheapify(arr, max, p);
    }
}

void heapsorting::buildmaxheap(std::vector<float>& arr, int& p)
{
    int size = arr.size();
    for (int i = size / 2; i >= 0; i--)
    {
        maxheapify(arr, i, p);
    }
}

void heapsorting::heapsort(std::vector<float>& arr)
{
    int size = arr.size();
    int p = arr.size();
    buildmaxheap(arr, p);
    for (int i = size - 1; i >= 1; i--)
    {
        float temp = arr[0];
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
void countingsorting::countingsort(std::vector<uint32_t>& arr, uint32_t exp, uint32_t b)
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
    for (int i = 0; i < size; i++)
    {
        arr[i] = out[i];
    }


}
std::string countingsorting::getname()
{
    return this->name;
}

uint32_t countingsorting::gettime()
{
    return this->time;
}

uint32_t countingsorting::getmemory()
{
    return this->memory;
}

void countingsorting::sort()
{
   // this->countingsort(this->vec,this->expon, this->base);

   this->countingsort(this->vec,this->expon,this->base);
}

void countingsorting::setbase(uint32_t b)
{
    this->base = b;
}
void countingsorting::setexp(uint32_t exp)
{
    this->expon = exp;
}
//std::vector<uint32_t> countingsorting::getarray()
//{
//    return this->vec;
//}

 uint32_t countingsorting::findmax()
 {

         if(this->vec.size()==0)
             throw std::out_of_range("Size of vector is equal to zero");
     uint32_t maxval = this->vec[0];

     for(auto i=1; i<this->vec.size();i++)
         if(this->vec[i] > maxval)
             maxval =this->vec[i];
     return maxval;


 }

 std::vector<uint32_t> countingsorting::getvalues()
 {
     return this->vec;
 }

 void radixsorting::radixsort(std::vector<uint32_t>& arr, uint32_t b)
 {
     int max = getMax(arr);
     countingsorting* cs = new countingsorting(arr);
     cs->setbase(b);
     for (int exp = 1; max / exp > 0; exp *= b)
     {

         cs->setexp(exp);
         cs->sort();
     }
     this->vec = cs->getvalues();
     delete cs;
 }
std::string radixsorting::getname()
{
    return this->name;
}

uint32_t radixsorting::gettime()
{
    return this->time;
}

uint32_t radixsorting::getmemory()
{
    return this->memory;
}

void radixsorting::sort()
{
   // this->radixsort(this->vec, this->base);
    this->radixsort(this->vec,this->base);
}

void radixsorting::setbase(uint32_t b)
{
    this->base = b;
}

std::vector<uint32_t> radixsorting::getvalues()
{
    return this->vec;
}

std::string insertionsorting::getname()
{
    return this->name;
}

uint32_t insertionsorting::gettime()
{
    return this->time;
}

uint32_t insertionsorting::getmemory()
{
    return this->memory;
}

void insertionsorting::sort()
{
   // this->insertionsort(this->vec);
    this->insertionsort(this->vec);

}
void insertionsorting::insertionsort(std::vector<float>&arr)
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
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

std::vector<float> insertionsorting::getvalues()
{
    return this->vec;
}
void insertionsorting::setvalues(std::vector<float> v)
{
    this->vec = v;
}

std::string bucketsorting::getname()
{
    return this->name;
}

uint32_t bucketsorting::gettime()
{
    return this->time;
}

uint32_t bucketsorting::getmemory()
{
    return this->memory;
}

void bucketsorting::bucketsort(std::vector<float>& arr)
{
    int len = arr.size();
    std::vector<std::vector<float>> out(len, std::vector<float>());

    for (int i = 0; i < len; i++) {

        out[len * arr[i]].push_back(arr[i]);
    }

    insertionsorting* inss = new insertionsorting();
    for (int i = 0; i < len; i++)
    {
        inss->setvalues(out[i]);
        inss->sort();
        out[i] = inss->getvalues();
    }
delete inss;
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        int sublen = out[i].size();
        for (int j = 0; j < sublen; j++)
        {
            arr[k] = out[i][j];
            k++;
        }
    }
}

std::vector<float> bucketsorting::getvalues()
{
    return this->vec;
}

void bucketsorting::sort()
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

std::string horspool::getname()
{
    return this->name;
};
uint32_t horspool::gettime() {
    return this->time;
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
 int horspool::findfirstsubstr()
 {
    // return this->horspoolmatching(this->sample, this->line);
     return this->horspoolmatching(this->sample,this->line);
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
uint32_t boyermoor::gettime() {
    return this->time;
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
 int boyermoor::findfirstsubstr()
 {
     //return this->boyermoormatching(this->sample, this->line);
     return this->boyermoormatching(this->sample,this->line);
 };


