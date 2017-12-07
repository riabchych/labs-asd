#include <complex>
#include <iostream>

const double EPS = 2e-5;
const double X = 0.56;

int fact(int n) {
    return !n || n == 1 ? 1 : fact(n - 1) * n;
}

double calcSum() {
    double sum, term, ex = exp(X + 1);
    sum = term = X * X * log(1 + X) / (2 + ex);

    for (int i = 2; fabs(term) > EPS; i++) {
        term *= -X * log(i + X) * (fact(i) + ex) / log(i - 1 + X);
        sum += term /= fact(i + 1) + (ex *= 2.718281828);
    }

    return sum;
}

int main() {
    std::cout << "Сума ряду = " << calcSum() << std::endl;

    return 0;
}