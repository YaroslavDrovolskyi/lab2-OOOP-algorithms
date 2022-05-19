#include "visitor.h"
#include <QElapsedTimer>


void visitor::calculateTime()
{
    this->timer.start();
    algorithm_->run();
    this->time = this->timer.elapsed();
}
qint64 visitor::getTime()
{
    return this->time;
};
