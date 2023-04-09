//
// Created by Полина on 05.04.2023.
//

#ifndef BSMMODEL_BINTREE_H
#define BSMMODEL_BINTREE_H

double exercisevalue(double s, double t, double K, int is_call) {
    if (is_call) return max(0.0, s - K);
    return max(0.0, K - s); // is_call = 0
}

double binomialtree(const double S, const double K, const double r, const double sigma, const double T, const int is_call, int Depth = 200) {
    vector<double> binTree(Depth + 1);
    double deltaT = T / Depth;
    double U = exp(sigma * sqrt(T / Depth));
    double D = 1 / U;
    double p0, p1, currentSpot, exercise;

    // no dividents, otherwise modif p0
    p0 = (exp(r * deltaT) - D) / (U - D);
    p1 = 1 - p0;
    for(int i = 0; i <= Depth; i++) {
        currentSpot = S * pow(U, 2 * i - Depth);
        binTree[i] = exercisevalue(currentSpot, T, K, is_call);
    }
    double t = T;
    for(int j = Depth - 1; j >= 0; j--) {
        t -= T / Depth;
        for(int i = 0; i <= j; i++) {
            binTree[i] = exp(-r * (T / Depth)) * (p0 * binTree[i + 1] + p1 * binTree[i]);
            currentSpot = S * pow(U, 2 * i - j);
            exercise = exercisevalue(currentSpot, t, K, is_call); // default is_call = 1
            if (binTree[i] < exercise) binTree[i] = exercise;
        }
    }
    return binTree[0];
}

#endif //BSMMODEL_BINTREE_H
