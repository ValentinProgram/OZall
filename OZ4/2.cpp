#include <iostream>
#include <cmath>
using namespace std;

double f(int k) {
    return k > 33 ? 0 : sqrt(3 * k + f(k + 1));
}

int main() {
    cout << f(1);
    return 0;
}