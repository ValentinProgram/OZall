#include <iostream>
using namespace std;

void print_tree_recursive(int i, int N) {
    if (i > N) {
        for (int j = 0; j < 2 * N - 1; j++) cout << " ";
        cout << "|";
        return;
    }
    for (int j = 0; j < N - i; j++) cout << " ";
    for (int j = 0; j < 2 * i - 1; j++) cout << "#";
    cout << endl;
    print_tree_recursive(i + 1, N);
}

void print_tree_iterative(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) cout << "#";
        cout << endl;
    }
    for (int j = 0; j < 2 * N - 1; j++) cout << " ";
    cout << "|";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cin >> N;

    cout << "Рекурсивный алгоритм:" << endl;
    print_tree_recursive(1, N);
    cout << endl << endl;

    cout << "Циклический алгоритм:" << endl;
    print_tree_iterative(N);
}