#include "funcA.h"
#include <cmath>

double FuncA::calculate(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (std::pow(x, 2 * i + 1)) / (2 * i + 1);
    }
    return sum;
}
