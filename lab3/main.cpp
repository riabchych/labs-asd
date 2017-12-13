#include <complex>
#include <iostream>

const double EPS = 2e-5;
const double X = 0.56;

int fact(int n) {
    return !n || n == 1 ? 1 : fact(n - 1) * n;
}

double calcSum() {
    int i = 1;
    double sum = 0, ch;

    do
        sum += ch = pow(-1, i + 1) * pow(X, i + 1) * log(i + X)
                    / (fact(i + 1) + pow(M_E, i++ + X));
    while (fabs(ch) > EPS);

    return sum;
}

int main() {
    std::cout << "Сума ряду = " << calcSum() << std::endl;

    return 0;
}