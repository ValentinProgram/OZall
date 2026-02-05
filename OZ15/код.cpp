#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void fill_matrix(double m[][10], int n) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) m[i][j] = (rand() % 200 - 100) / 10.0;
}

void print_matrix(double m[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << m[i][j] << " ";
        cout << endl;
    }
}

double matrix_norm(double m[][10], int n) {
    double max_val = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        if (fabs(m[i][j]) > max_val) max_val = fabs(m[i][j]);
    return max_val;
}

int find_min_norm_matrix(double m1[][10], double m2[][10], double m3[][10], int n) {
    double n1 = matrix_norm(m1, n), n2 = matrix_norm(m2, n), n3 = matrix_norm(m3, n);
    if (n1 <= n2 && n1 <= n3) return 1;
    if (n2 <= n1 && n2 <= n3) return 2;
    return 3;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n; cin >> n;
    if (n <= 2 || n >= 10) return 1;

    double m1[10][10], m2[10][10], m3[10][10];

    fill_matrix(m1, n);
    fill_matrix(m2, n);
    fill_matrix(m3, n);

    cout << "Матрица 1:" << endl;
    print_matrix(m1, n);
    cout << "Норма: " << matrix_norm(m1, n) << endl << endl;

    cout << "Матрица 2:" << endl;
    print_matrix(m2, n);
    cout << "Норма: " << matrix_norm(m2, n) << endl << endl;

    cout << "Матрица 3:" << endl;
    print_matrix(m3, n);
    cout << "Норма: " << matrix_norm(m3, n) << endl << endl;

    int min_idx = find_min_norm_matrix(m1, m2, m3, n);
    cout << "Матрица с наименьшей нормой: " << min_idx;
}