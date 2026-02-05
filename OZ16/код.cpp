#include <iostream>
#include <cmath>
using namespace std;

double f1(double x) {
    return x * x;
}

double f2(double x) {
    return sin(x);
}

double trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

int main() {
    double c, d;
    cin >> c >> d;
    const double PI = 3.14159265358979323846;
    double result = trapezoidal(f1, c, d, 20) + trapezoidal(f2, 0, PI, 100);
    cout << result;
}