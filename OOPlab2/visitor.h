#ifndef VISITOR_H
#define VISITOR_H
#include <QtGlobal>
#include <QElapsedTimer>
#include "algoslib.h"
class visitor
{
public:
    visitor(algorithm* algo): algorithm_(algo){};
    void calculateTime();
        qint64 getTime();
private:
  qint64 time=0;
  QElapsedTimer timer;
  algorithm* algorithm_;
};

#endif // VISITOR_H
