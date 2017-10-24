#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    // Оголошуємо змінні з плаваючою комою
    double x, w;

    // Виводимо на экран запрошення для введення значення числа x
    cout << "Будь ласка, введіть значення x:" << endl;
    cin >> x;

    // Обчислюємо значення функції згідно умови
    if (x < -1)
        w = pow(x, 2) * ((M_PI - x) / (M_PI + x)) * pow(M_E, x + 1) * 1.1 * pow(10, -3);
    else if (x < 1)
        w = pow(tan(cbrt(abs(x * log(abs(x))))), 2);
    else
        w = log(x) + cbrt(x + sqrt(x + M_PI));

    // Виводимо результат
    cout << "Результат: w=" << setprecision(4) << w << endl;

    return 0;
}