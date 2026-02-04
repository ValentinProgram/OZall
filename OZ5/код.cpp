#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, eps;
    cin >> x >> eps;

    double s = 1;
    double t = 1;

    for (int n = 1; fabs(t) >= eps; n++) {
        t *= x / n;
        s += t;
    }

    cout << s;
}