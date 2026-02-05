#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fill_vector(double v[], int k) {
    for (int i = 0; i < k; i++) v[i] = rand() % 100 / 10.0;
}

void fill_matrix(double m[][10], int k) {
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) m[i][j] = rand() % 100 / 10.0;
}

void print_vector(double v[], int k) {
    for (int i = 0; i < k; i++) cout << v[i] << " ";
    cout << endl;
}

void print_matrix(double m[][10], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) cout << m[i][j] << " ";
        cout << endl;
    }
}

double dot_product(double a[], double b[], int k) {
    double s = 0; for (int i = 0; i < k; i++) s += a[i] * b[i]; return s;
}

void matrix_vector_mult(double m[][10], double v[], double r[], int k) {
    for (int i = 0; i < k; i++) {
        r[i] = 0;
        for (int j = 0; j < k; j++) r[i] += m[i][j] * v[j];
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int k; cin >> k;
    if (k < 3 || k>9) return 1;

    double x[10], y[10], A[10][10], B[10][10], C[10][10], Ax[10], By[10], Cx[10];

    fill_vector(x, k); fill_vector(y, k);
    fill_matrix(A, k); fill_matrix(B, k); fill_matrix(C, k);

    cout << "Вектор x:" << endl;
    print_vector(x, k);
    cout << "Вектор y:" << endl;
    print_vector(y, k);
    cout << "Матрица A:" << endl;
    print_matrix(A, k);
    cout << "Матрица B:" << endl;
    print_matrix(B, k);
    cout << "Матрица C:" << endl;
    print_matrix(C, k);

    matrix_vector_mult(A, x, Ax, k);
    matrix_vector_mult(B, y, By, k);
    matrix_vector_mult(C, x, Cx, k);

    double result = dot_product(Ax, By, k) + dot_product(Cx, y, k) / dot_product(x, By, k);
    cout << "Результат: " << result << endl;
}