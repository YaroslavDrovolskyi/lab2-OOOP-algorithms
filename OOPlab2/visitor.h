#ifndef VISITOR_H
#define VISITOR_H
#include <QtGlobal>
#include <QElapsedTimer>
#include "algoslib.h"
#include <QString>
#include "factory.h"

class visitor
{
public:
    visitor(std::shared_ptr<algoCreator> algo): algoCreator_(algo){};
    void calculateTime();
        QString getTime();
private:
  QString time;
  QElapsedTimer timer;
  //algorithm* algorithm_;
std::shared_ptr<algoCreator> algoCreator_;

};


#endif // VISITOR_H
