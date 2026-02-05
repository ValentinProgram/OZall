#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
    ifstream f("matrix.dat");
    double m[10][10];
    const double eps = 1e-6;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) f >> m[i][j];
    for (int i = 0; i < 10; i++) for (int j = i; j < 10; j++) {
        double s = 0;
        for (int k = 0; k < 10; k++) s += m[i][k] * m[j][k];
        if ((i == j && fabs(s - 1) > eps) || (i != j && fabs(s) > eps)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}