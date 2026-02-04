#include <iostream>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        if ((m && n % m == 0) || (n && m % n == 0)) break;
    }
}