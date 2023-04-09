#include <iostream>
#include "methods.h"
#include "pricing.h"
#include "bintree.h"
#include "greeks.h"
#include "option_class.h"
#include <iostream>
#include <cmath>

using namespace std;


int main () {
    double S = 75.576;  // Option price
    double r = 0.08;   // Risk-free rate (5%)
    double K = 75.0;  // Strike price

    double v = 0.22;
    double T = 0.0493;
    double B = 1.944;
    bool is_call = true;

    Option Opt (S, K, r, T, is_call);

    cout << "Binomial Tree Price from Volatility " << Opt.binomialtree_price(v) << endl;

    double price = Opt.option_price(v);
    double delta_v = Opt.option_delta(v);
    double gamma_v = Opt.option_gamma(v);
    double vega_v = Opt.option_vega(v);
    double theta_v = Opt.option_theta(v);
    double rho_v = Opt.option_rho(v);
    double charm_v = Opt.option_charm(v);
    double vanna_v = Opt.option_vanna(v);

    // Finally we output the parameters and prices
    cout << std::endl;
    cout << "Underlying:      " << S << std::endl;
    cout << "Strike:          " << K << std::endl;
    cout << "Risk-Free Rate:  " << r << std::endl;
    cout << "Maturity:        " << T << std::endl;
    cout << std::endl;

    double low = 0.1, high = 0.5, eps = 0.001, init_vol = 0.25;
    cout << "Binsearch Implied Volatility: " << BinsearchVol (B, low, high, Opt, eps) << endl;
    cout << "Newton-Raphson Implied Volatility: " << NewtonRaphson (B, init_vol, eps, Opt) << endl;
    string type;
    if (Opt.is_call) type = "Call";
    else type = "Put";
    cout << std::endl;
    std::cout << type << " Price:      " << price << std::endl;
    std::cout << type << " Delta:      " << delta_v << std::endl;
    std::cout << type << " Gamma:      " << gamma_v << std::endl;
    std::cout << type << " Vega:       " << vega_v << std::endl;
    std::cout << type << " Theta:      " << theta_v << std::endl;
    std::cout << type << " Rho:        " << rho_v << std::endl;
    std::cout << type << " Charm:      " << charm_v << std::endl;
    std::cout << type << " Vanna:        " << vanna_v << std::endl << std::endl;

    return 0;
}