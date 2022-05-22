#ifndef VISITOR_H
#define VISITOR_H
#include <QtGlobal>
#include <QElapsedTimer>
#include "algoslib.h"
#include <QString>
class visitor
{
public:
    visitor(algorithm* algo): algorithm_(algo){};
    void calculateTime();
        QString getTime();
private:
  QString time;
  QElapsedTimer timer;
  algorithm* algorithm_;


};


#endif // VISITOR_H
