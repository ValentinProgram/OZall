#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int n, m, k;
    cin >> n >> m >> k;
    int A[100][100], B[100][100], C[100][100];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) A[i][j] = rand() % 21 - 10;
    for (int i = 0; i < m; i++) for (int j = 0; j < k; j++) B[i][j] = rand() % 21 - 10;
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) for (int p = 0, s = 0; p < m; p++) s += A[i][p] * B[p][j], C[i][j] = s;
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) cout << C[i][j] << " \n"[j == k - 1];
}