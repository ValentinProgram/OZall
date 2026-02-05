#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int m[9][9], s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) m[i][j] = rand() % 101;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        if (i == 0 || i == 8 || j == 0 || j == 8) s1 += m[i][j];
        if (i == j || i + j == 8) s2 += m[i][j];
        if (abs(i - 4) + abs(j - 4) <= 4) s3 += m[i][j];
        if ((i <= 4 && (j <= i || j >= 8 - i)) || (i >= 4 && (j <= 8 - i || j >= i))) s4 += m[i][j];
    }
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
}