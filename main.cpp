#include <QCoreApplication>

#include <iostream>
#include <QDebug>

#include "interpolationLagrange.h"
#include "myTimer.h"

int main(int argc, char *argv[])
{
    using namespace Timer;
    QCoreApplication a(argc, argv);

    interpolationLagrange LagrangeInterp;

    time_var t_s = time_now();

    LagrangeInterp.interpolateTest();

    time_var t_f = time_now();
    qDebug() << "Time taken: " << time_taken(t_s, t_f);

    return 0;
}
