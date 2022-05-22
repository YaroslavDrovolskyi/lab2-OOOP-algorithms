#include "visitor.h"
#include <QElapsedTimer>
#include <QtMath>

void visitor::calculateTime()
{
    this->timer.start();
    algorithm_->run();
    qint64 t= this->timer.nsecsElapsed();
    qint64 nsMax = qPow(qint64(10),6);
    qint64 msMax = qPow(qint64(10),9);
    QString type = " ns";
    if(t >= msMax )
    {
        t /=msMax;
        type = " s";
    }
    else
        if(t>=nsMax){
            t/=nsMax;
            type = "ms";
        }
    this->time = QString::number(t) + type;
}
QString visitor::getTime()
{
    return this->time;
};
