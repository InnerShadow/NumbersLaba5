#include <iostream>
#include <cmath>

#define EPSILON 10e-5

#include "Integral.hpp"
#include "DoubleIntegral.hpp"

// #3
double func(double x){
    return pow((x + pow(x, 3)), 0.5);
}

// #32
double func(double x, double y){
    return 4 - pow(x, 2) - pow(y, 2);
}

int main(void){

    Integral integral(0.6, 1.724, 100000, EPSILON, func);

    std::cout << "Trapezoid count: "<< integral.CountTrapezoid() << std::endl;

    std::cout << "Trapezoid discrepancy: " << integral.CountTrapezoidDiscrepancy(0.5, 2) << std::endl;

    std::cout << "Simpson count: " << integral.CountSimpson() << std::endl;

    std::cout << "Simpson discrepancy: " << integral.CountSimpsonDiscrepancy(0.5, 4) << std::endl;

    std::cout << "Diffrence: " << std::abs(integral.CountSimpson() - integral.CountTrapezoid()) << std::endl;

    DoubleIntegral doubleIntegral(-1, 1, -1, 1, 2000, 2000, EPSILON, func);

    std::cout << "Simpson Cubature count: " << doubleIntegral.CountSimpsonCubature() << std::endl;

    return 0;
}