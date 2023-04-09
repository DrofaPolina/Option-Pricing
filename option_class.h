//
// Created by Полина on 05.04.2023.
//

#ifndef BSMMODEL_OPTION_CLASS_H
#define BSMMODEL_OPTION_CLASS_H

class Option {
public:
    double S, K, r, T;
    int is_call = 1;
    // S - underlying asset price, K - strike, r - risk-free rate, T - years before exp

    Option(double _S, double _K, double _r, double _T, int _is_call = 1): S (_S), K (_K), r (_r), T (_T), is_call (_is_call) {}
    [[nodiscard]] double option_price(double sigma) const {  // bsm model
        if (is_call) { return call_price(S, K, r, sigma, T); }
        else { return put_price(S, K, r, sigma, T); }
    }

    [[nodiscard]] double binomialtree_price(double sigma) const {
        return binomialtree(S, K, r, sigma, T, is_call);
    }

    [[nodiscard]] double option_vega(double sigma) const {
        if (is_call) return call_vega(S, K, r, sigma, T);
        else return put_vega(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_delta(double sigma) const {
        if (is_call) return call_delta(S, K, r, sigma, T);
        else return put_delta(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_gamma(double sigma) const {
        if (is_call) return call_gamma(S, K, r, sigma, T);
        else return put_gamma(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_theta(double sigma) const {
        if (is_call) return call_theta(S, K, r, sigma, T);
        else return put_theta(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_rho(double sigma) const {
        if (is_call) return call_rho(S, K, r, sigma, T);
        else return put_rho(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_charm(double sigma) const {
        if (is_call) return call_charm(S, K, r, sigma, T);
        else return put_charm(S, K, r, sigma, T);
    }

    [[nodiscard]] double option_vanna(double sigma) const {
        if (is_call) return call_vanna(S, K, r, sigma, T);
        else return put_vanna(S, K, r, sigma, T);
    }
};


#endif //BSMMODEL_OPTION_CLASS_H
