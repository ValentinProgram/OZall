#include <iostream>
using namespace std;

int fib_recursive(int n) {
    if (n <= 2) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n) {
    if (n <= 2) return 1;
    int a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    cout << "Рекурсивно: " << fib_recursive(n) << endl;
    cout << "Циклически: " << fib_iterative(n) << endl;
}