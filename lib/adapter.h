#ifndef ADAPTER_H
#define ADAPTER_H

#include "algoslib.h"

template<typename T, typename Comparator>
class ALGOSLIB_EXPORT AdapterForSortArrayAlgo : public sortingalgo<Comparator>
{
private:
    SortArrayAlgo<T, Comparator>* sort_algo;
public:
    AdapterForSortArrayAlgo(SortArrayAlgo<T, Comparator>* sort_algo);
    virtual void run() override;
    virtual std::string getname() override;
    virtual uint32_t getmemory() override;
    std::vector<T> getvalues();
    virtual ~AdapterForSortArrayAlgo() = default;
};

#endif // ADAPTER_H
