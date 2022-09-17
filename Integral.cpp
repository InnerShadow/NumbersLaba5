
#include "Integral.hpp"

Integral::Integral(double downLim, double UpLim, double beating, double accuracy, double (*func)(double )){
    this->downLim = downLim;
    this->UpLim = UpLim;
    this->beating = beating;
    this->func = func;
    this->accuracy = accuracy;
}

double Integral::CountTrapezoid(){

    double value = 0.f;
    double step = (UpLim - downLim) / beating;
    double prev_val = 0.f;
    do{
        prev_val = value;
        value = 0.f;
        value += func(downLim);
        value += func(UpLim);
        double sum = 0.f;
        for(double i = downLim + step; i < UpLim - step; i += step){
            sum += func(i);
        }
        sum *= 2;
        value += sum;
        value *= (step / 2);
        step /= 2;
    } while (std::abs(prev_val - value) > 3 * accuracy);
    return value;
}

double Integral::CountTrapezoidDiscrepancy(double CoeffitientR, double CoeffitientP){

    double value = 0.f;

    double I = CountTrapezoid();
    Integral integtal(downLim, UpLim, beating * pow(CoeffitientR, -1), accuracy, func);
    double Ir = integtal.CountTrapezoid();

    value = (I - Ir) / (pow(CoeffitientR, CoeffitientP) - 1);

    return value;
}

double Integral::CountSimpson(){
    double SimpsonBeating = beating * 2;
    double value = 0.f;
    double prev_val = 0.f;
    double step = (UpLim - downLim) / SimpsonBeating;

    do{
        prev_val = value;

        double sum1 = 0.f;
        for(double i = downLim + step; i < UpLim; i += 2 * step){
            sum1 += func(i);
        }
        sum1 *= 4;

        double sum41 = 0.f;
        for(double i = downLim + 2 * step; i < UpLim; i += 2 * step){
            sum41 += func(i);
        }
        sum41 *= 2;

        value = (step / 3) * (func(downLim) + func(UpLim) + sum1 + sum41);

        step /= 2;

    } while(std::abs(prev_val - value) > 15 * accuracy);

    return value;
}

double Integral::CountSimpsonDiscrepancy(double CoeffitientR, double CoeffitientP){
    double value = 0.f;

    double I = CountSimpson();
    Integral integtal(downLim, UpLim, beating * pow(CoeffitientR, -1), accuracy, func);
    double Ir = integtal.CountSimpson();

    value = (I - Ir) / (pow(CoeffitientR, CoeffitientP) - 1);

    return value;
}
