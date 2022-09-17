#pragma once

#include <cmath>
#include <vector>

class DoubleIntegral {

protected:
    double XUpLim;
    double XDownLim;
    double YUpLim;
    double YDownLim;
    double Xbeating;
    double Ybeating;
    double accuracy;
    double (*func)(double x, double y);

public:

    DoubleIntegral(double XDownLim, double XUpLim, double YDownLim, double YUpLim, double Xbeating, double Ybeating, double accuracy, double (*func)(double x, double y));

    double CountSimpsonCubature();
};