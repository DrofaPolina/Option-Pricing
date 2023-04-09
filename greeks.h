//
// Created by Полина on 05.04.2023.
//

#ifndef BSMMODEL_GREEKS_H
#define BSMMODEL_GREEKS_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <algorithm>

//#include "pricing.h" // Npdf , Ncdf , d_j, call_price
using namespace std;

// European Vanilla Call & Put

double call_delta(const double S, const double K, const double r, const double v, const double T) {
    return Ncdf(d_j(1, S, K, r, v, T));
}


double call_gamma(const double S, const double K, const double r, const double v, const double T) {
    return Npdf(d_j(1, S, K, r, v, T)) / (S * v * sqrt(T));
}


double call_vega(const double S, const double K, const double r, const double v, const double T) {
    return S * Npdf(d_j(1, S, K, r, v, T)) * sqrt(T);
}


double call_theta(const double S, const double K, const double r, const double v, const double T) {
    return -(S * Npdf(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
           - r * K * exp(-r*T) * Ncdf(d_j(2, S, K, r, v, T)) ;
}


double call_rho(const double S, const double K, const double r, const double v, const double T) {
    return K * T * exp(-r*T) * Ncdf(d_j(2, S, K, r, v, T)) ;
}

double call_charm(double S, double K, double r, double sigma, double T) {
    double d1 = d_j(1, S, K, r, sigma, T);
    double d2 = d_j(2, S, K, r, sigma, T);
    double D = exp(- r * T);
    double t1 = - d2 / (2 * T);
    double t2 = - Ncdf(d1) * t1;
    double charm = - D * (t2 - r * Npdf(d1)) ;
    return charm;
}

double call_vanna(double S, double K, double r, double sigma, double T) {
    double d1 = d_j(1, S, K, r, sigma, T);
    double N_d1 = Npdf(d1);
    double vanna = sqrt(T) * N_d1 * (1 - d1);
    return vanna;
}


double put_delta(const double S, const double K, const double r, const double v, const double T) {
    return Ncdf(d_j(1, S, K, r, v, T)) - 1;
}


double put_gamma(const double S, const double K, const double r, const double v, const double T) {
    return call_gamma(S, K, r, v, T);
}

// Calculate the European vanilla put Vega
double put_vega(const double S, const double K, const double r, const double v, const double T) {
    return call_vega(S, K, r, v, T);
}

// Calculate the European vanilla put Theta
double put_theta(const double S, const double K, const double r, const double v, const double T) {

    return ( -(S * Npdf(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
           + r * K * exp(-r*T) * Ncdf(-d_j(2, S, K, r, v, T)) ) ; // / 365;
}

double put_rho(const double S, const double K, const double r, const double v, const double T) {
    return -T * K * exp(-r*T) * Ncdf(-d_j(2, S, K, r, v, T)) ; // / 100;
}

double put_charm(double S, double K, double r, double sigma, double T) {
    double d1 = d_j(1, S, K, r, sigma, T);
    double d2 = d_j(2, S, K, r, sigma, T);
    double D = exp(- r * T);
    double t1 = - d2 / (2 * T);
    double t2 = - Ncdf(d1) * t1;
    double charm = D * (t2 + r * Npdf( - d1)) ;
    return charm;
}

double put_vanna(double S, double K, double r, double sigma, double T) {
    double d1 = d_j(1, S, K, r, sigma, T);
    double N_d1 = Npdf(d1);
    double vanna = sqrt(T) * N_d1 * (1 - d1);
    return vanna;
}

#endif //BSMMODEL_GREEKS_H
