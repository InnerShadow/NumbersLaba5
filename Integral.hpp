#pragma once

#include <iostream>
#include <cmath>

class Integral {
protected:
    double downLim;
    double UpLim;
    double beating;
    double (*func)(double x);
    double accuracy;

public:

    Integral(double downLim, double UpLim, double beating, double accuracy, double (*func)(double x));

    double CountTrapezoid();

    double CountTrapezoidDiscrepancy(double CoeffitientR, double CoeffitientP);

    double CountSimpson();

    double CountSimpsonDiscrepancy(double CoeffitientR, double CoeffitientP);


};