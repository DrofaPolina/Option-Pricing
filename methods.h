#ifndef BSMMODEL_METHODS_H
#define BSMMODEL_METHODS_H

#include <cmath>

template<typename T>
double BinsearchVol(double y_t, double left, double right, T opt, double tol) {
    double vol, p;
    vol = 0.5 * (left + right);
    p = opt.option_price(vol);

    while (fabs(p - y_t) > tol) {
        if (p < y_t) { left = vol; }
        if (p > y_t) { right = vol; }
        vol = 0.5 * (left + right);
        p = opt.option_price(vol);
    } return vol;
}
template<typename T>
double BinsearchBintree(double y_t, double left, double right, T opt, double tol) {
    double vol, p;
    vol = 0.5 * (left + right);
    p = opt.binomialtree_price(vol);
    while (fabs(p - y_t) > tol) {
        if (p < y_t) { left = vol; }
        if (p > y_t) { right = vol; }
        vol = 0.5 * (left + right);
        p = opt.binomialtree_price(vol);
    } return vol;
}

template<typename T>
double NewtonRaphson(double true_y, double v0, double tol, const T& Opt) {

    double v = v0, y = (Opt.option_price)(v0);
    while (fabs(y - true_y) > tol) {
        v += (true_y - y) / (Opt.option_vega)(v);
        y = (Opt.option_price)(v);
    } return v;
}


#endif