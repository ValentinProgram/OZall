#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double N, D, eps, x = 0.5;
    cin >> N >> D >> eps;
    while (fabs(x * D - 1) >= eps) x = x * (2 - D * x);
    cout << N * x;
}