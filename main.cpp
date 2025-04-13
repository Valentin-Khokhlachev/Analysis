#include <QCoreApplication>

#include <iostream>
#include <QDebug>

#include "interpolationLagrange.h"
#include "chronoTimer.h"

int main(int argc, char *argv[])
{
    using namespace chronoTimer;
    QCoreApplication a(argc, argv);

    interpolationLagrange LagrangeInterp;

    auto [result, time] = timedFunction([&LagrangeInterp]()->bool{return LagrangeInterp.interpolateTest();});
    qDebug() << time;

    return 0;
}
