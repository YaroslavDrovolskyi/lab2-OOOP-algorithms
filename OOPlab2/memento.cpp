#include "memento.h"


ResultTableMemento::ResultTableMemento(const std::vector<concreteFacadeInfo>& rows){
    this->rows = rows;
}


std::vector<concreteFacadeInfo> ResultTableMemento::state(){
    return this->rows;
}



ResultTableHistory::ResultTableHistory():
    originator(nullptr)
{

}

ResultTableHistory::ResultTableHistory(ResultTableOriginator* originator):
    originator(originator)
{

}

ResultTableHistory::~ResultTableHistory(){
    for (const auto& memento : this->mementos){
        delete memento; // because it were created with new in  Originator::save()
    }
}

void ResultTableHistory::backup(){
    ResultTableMemento* memento = this->originator->save();
    this->mementos.push_back(memento);
}

void ResultTableHistory::undo(){
    if (this->mementos.empty()){
        return;
    }

    ResultTableMemento* memento = this->mementos.back();
    this->mementos.pop_back();
    this->originator->restore(memento);
    delete memento; // because it were created with new in  Originator::save()
}



ResultTableOriginator::ResultTableOriginator() :
    table(nullptr)
{

}

ResultTableOriginator::ResultTableOriginator(QTableWidget* table):
    table(table)

{

}

ResultTableMemento* ResultTableOriginator::save(){
    std::vector<concreteFacadeInfo> rows_info;

    for (int i = 0; i < this->table->rowCount(); i++){
        concreteFacadeInfo row_info = readFromRow(i);
        rows_info.push_back(row_info);
    }

    return new ResultTableMemento(rows_info);
}


void ResultTableOriginator::restore(ResultTableMemento* memento){
    std::vector<concreteFacadeInfo> rows_info = memento->state();

    this->table->clearContents();
    table->setRowCount(rows_info.size());

    for (int i = 0; i < rows_info.size(); i++){
        writeInRow(rows_info[i], i);
    }
}


concreteFacadeInfo ResultTableOriginator::readFromRow(std::size_t index){
    concreteFacadeInfo row_info;

    QTableWidgetItem* item = table->item(index, 0);
    row_info.setName(item->text());

    item = table->item(index, 1);
    row_info.setTime(item->text().toLongLong());

    item = table->item(index, 2);
    row_info.setCounter(item->text().toLongLong());

    item = table->item(index, 3);
    row_info.setResult(item->text());

    return row_info;
}

void ResultTableOriginator::writeInRow(const concreteFacadeInfo& row_info, std::size_t index){
    QString name = row_info.getName();
    this->table->setItem(index, 0, new QTableWidgetItem(name));

    QString time = QString::number(row_info.getTime());
    this->table->setItem(index, 1, new QTableWidgetItem(time));

    QString counter = QString::number(row_info.getCounter());
    this->table->setItem(index, 2, new QTableWidgetItem(counter));

    QString result = row_info.getResult();
    this->table->setItem(index, 3, new QTableWidgetItem(result));
}
