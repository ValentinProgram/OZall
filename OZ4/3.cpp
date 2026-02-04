#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x, y, y_old;

    cout << "Введите x: ";
    cin >> x;

    y = sin(x);
    y_old = x;

    while (abs(y - y_old) >= 0.0001) {
        y_old = y;
        y = sin(y);
    }

    cout << "Результат: " << y << endl;

    return 0;
}