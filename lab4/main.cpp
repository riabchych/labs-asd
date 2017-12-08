#include <iostream>

using namespace std;

const int C_COUNT = 5;
const int R_COUNT = 6;

enum Method {
    Custom = 1, Auto = 2, Random = 3
};

struct Element {
    int value;
    int col;
    int row;
};

Element getElement(int value, int row, int col) {
    Element element{};
    element.value = value;
    element.col = col;
    element.row = row;
    return element;
}

void clean(int **arr) {
    for (int i = 0; i < C_COUNT; i++) {
        delete[] arr[i];
        arr[i] = nullptr;
    }

    delete[] arr;
}

int getRandomValue() {
    return rand() % 9 + 1;
}

int getSum(int a, int b) {
    return a + b;
}

int getInput(int a, int b) {
    int value;
    cout << "arr[" << a << "][" << b << "] = ";
    return cin >> value ? value : 0;
}

void fillArray(int **arr, Method method) {
    int (*pfunc)(int, int);

    if (method == Method::Auto) {
        pfunc = getSum;
    } else if (method == Method::Custom) {
        pfunc = getInput;
    } else {
        pfunc = reinterpret_cast<int (*)(int, int)>(getRandomValue);
    }

    for (int i = 0; i < C_COUNT; i++) {
        for (int j = 0; j < R_COUNT; j++) {
            arr[i][j] = (*pfunc)(i, j);
        }
    }
}

void printArray(int *const *arr) {
    cout << "Вигляд матриці " << C_COUNT << " * " << R_COUNT << endl;

    for (int i = 0; i < C_COUNT; i++) {
        for (int j = 0; j < R_COUNT; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}

void printMaxValue(int *const *arr) {
    Element maxElement{};

    for (int i = 0; i < R_COUNT; ++i) {
        maxElement = getElement(arr[0][i], 0, i);
        for (int j = 0; j < C_COUNT; ++j) {
            if (arr[j][i] > maxElement.value) {
                maxElement = getElement(arr[j][i], j, i);
            }
        }
        cout << "Максимальний елемент в "
             << i + 1
             << " стовпчику з індексом ["
             << maxElement.row + 1
             << "]["
             << maxElement.col + 1
             << "], який рівний: "
             << maxElement.value
             << endl;
    }
}

int main() {
    int type;
    auto **arr = new int *[C_COUNT];

    for (int i = 0; i < C_COUNT; i++) {
        arr[i] = new int[R_COUNT];
    }

    setlocale(LC_CTYPE, "Ukrainian");

    cout << "Оберіть спосіб заповнення масиву:\n"
         << "1:Ручний\n"
         << "2:Автоматичний\n"
         << "3:Випадкові числа\n";
    cin >> type;

    auto method = static_cast<Method>(type);

    fillArray(arr, method);
    printArray(arr);
    printMaxValue(arr);
    clean(arr);

    return 0;
}