#include <iostream>
#include "funcA.h"

int main() {
    FuncA func;
    double x;
    int n;

    std::cout << "Введіть значення x (|x| < 1): ";
    std::cin >> x;
    std::cout << "Введіть кількість елементів ряду: ";
    std::cin >> n;

    double result = func.calculate(x, n);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
