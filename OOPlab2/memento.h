#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>
#include "QTableWidget"
#include "facadeinfo.h"

class Memento{

};

class ResultTableMemento : public Memento {
private:
    std::vector<concreteFacadeInfo> rows;
public:
    ResultTableMemento(const std::vector<concreteFacadeInfo>& rows);
    std::vector<concreteFacadeInfo> state();
};



class ResultTableOriginator{
private:
    QTableWidget* table;
public:
    ResultTableOriginator();
    ResultTableOriginator(QTableWidget* table);
    ResultTableMemento* save(); // save state // return new Memento
    void restore(ResultTableMemento* memento); // restore state

    void writeInRow(const concreteFacadeInfo& row_info, std::size_t index);
    concreteFacadeInfo readFromRow(std::size_t index);
};



class ResultTableHistory{
private:
    ResultTableOriginator* originator;
    std::vector<ResultTableMemento*> mementos;

public:
    ResultTableHistory();
    ResultTableHistory(ResultTableOriginator* originator);
    ~ResultTableHistory();
    void backup(); // add originator's state // this->mementos_.push_back(this->originator_->Save());
    void undo(); //
};

#endif // MEMENTO_H
