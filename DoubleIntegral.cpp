
#include "DoubleIntegral.hpp"

DoubleIntegral::DoubleIntegral(double XDownLim, double XUpLim, double YDownLim, double YUpLim, double Xbeating, double Ybeating, double accuracy, double (*func)(double , double)){
    this->XUpLim = XUpLim;
    this->XDownLim = XDownLim;
    this->YUpLim = YUpLim;
    this->YDownLim = YDownLim;
    this->Xbeating = Xbeating;
    this->Ybeating = Ybeating;
    this->accuracy = accuracy;
    this->func = func;
}

double DoubleIntegral::CountSimpsonCubature(){
    double value = 0.f;
    double prev_val = 0.f;

    double XStep = (XUpLim - XDownLim) / (2 * Xbeating);
    double YStep = (YUpLim - YDownLim) / (2 * Ybeating);

    // do{
    prev_val = value;
    std::vector<double> sums(9);
    for(double i = XDownLim; i < XUpLim; i += 2 * XStep){
        for(double j = YDownLim; j < YUpLim; j += 2 * YStep){
            sums.at(0) += func(i, j);
            sums.at(1) += 4 * func(i + XStep, j);
            sums.at(2) += func(i + 2 * XStep, j);
            sums.at(3) += 4 * func(i, j + YStep);
            sums.at(4) += 16 * func(i + XStep, j + YStep);
            sums.at(5) += 4 * func(i + 2 * XStep, j + YStep);
            sums.at(6) += func(i, j + 2 * YStep);
            sums.at(7) += 4 * func(i + XStep, j + 2 * YStep);
            sums.at(8) += func(i + 2 * XStep, j + 2 * YStep);
        }
    }

    double sum = 0.f;
    for(auto i : sums){
        sum += i;
    }

    value = (XStep * YStep / 9) * sum;

    // } while(std::abs(prev_val - value) > accuracy);
    return value;
}