#include <iostream>
using namespace std;
int main() {
    int n, m[10][10], s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];
    for (int j = 0; j < n; j++) s += m[0][j];
    for (int i = 0; i < n; i++) {
        int r = 0, c = 0;
        for (int j = 0; j < n; j++) {
            r += m[i][j];
            c += m[j][i];
        }
        if (r != s || c != s) {
            cout << "NO";
            return 0;
        }
    }
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += m[i][i];
        d2 += m[i][n - 1 - i];
    }
    cout << (d1 == s && d2 == s ? "YES" : "NO");
}