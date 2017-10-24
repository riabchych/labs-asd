#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double A = -4.0, B = 4.0, C = 0.5;

double calcAndPrint(double x, double &min, double &max) {
    cout << "X=" << setprecision(6) << x << setw(15) << setfill(' ');

    if (x <= -1)
        x = x - cbrt(abs(sin(sqrt(abs(x)))));
    else if (x > -1 && x < 0)
        x = sin(pow(log(abs(pow(x, 3) + 1)), 2));
    else
        x = pow(x + exp(x) * sqrt(x + 1), 1.0 / 4) + M_PI;

    // задаємо максимальне та мінімальне значення
    max = max > x ? max : x;
    min = min < x ? min : x;

    // виводимо результат обчислення
    cout << "F(X)=" << x << endl;
}

int main() {
    string loopName;
    double i = A, min = A, max = A;

    cout << "Будь ласка, введіть назву циклу ('do', 'while', 'for'):" << endl;
    cin >> loopName;

    if (loopName == "while") {
        while (i <= B) {
            calcAndPrint(i, min, max);
            i += C;
        }
    } else if (loopName == "do") {
        do
            calcAndPrint(i, min, max);
        while ((i += C) <= B);
    } else {
        for (i; i <= B; i += C)
            calcAndPrint(i, min, max);
    }

    // виведення в консоль мінімального та максимального значення
    cout << "Мінімальне = " << min << "\nМаксимальне = " << max << endl;
    
    return 0;
}
