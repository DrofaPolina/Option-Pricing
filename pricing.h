//
// Created by Полина on 25.02.2023.
//
#ifndef BSMMODEL_PRICING_H
#define BSMMODEL_PRICING_H
#include <vector>
using namespace std;
// density
double Npdf (const double x) {
    double sqrtPi = pow (2 * M_PI, 0.5);
    return (1.0 / sqrtPi) * exp (- pow(x, 2) * 0.5); }

// cumulative
double Ncdf (const double x) {
    return erfc(-x / sqrt(2)) / 2;
}

double d_j(const int j, const double S, const double K, const double r, const double v, const double T) {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

double call_price (const double S, const double K, const double r, const double sigma, const double T) {
    double d1 = (log (S / K) + (r + (pow (-1, 1 - 1)) * 0.5 * sigma * sigma) * T) / (sigma * (pow (T, 0.5)));
    double d2 = (log (S / K) + (r + (pow (-1, 2 - 1)) * 0.5 * sigma * sigma) * T) / (sigma * (pow (T, 0.5)));
    return S * Ncdf (d1) - K * exp (-r * T) * Ncdf (d2);
}

double put_price(const double S, const double K, const double r, const double v, const double T) {
    return -S*Ncdf(-d_j(1, S, K, r, v, T))+K*exp(-r*T) * Ncdf(-d_j(2, S, K, r, v, T));
}

#endif
