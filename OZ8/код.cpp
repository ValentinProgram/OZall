#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    double m[7][7], maxVal = -2, minVal = 2, skalyr = 0;
    int maxRow = 0, minCol = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++) {
            m[i][j] = -1 + 2.0 * rand() / RAND_MAX;
            if (m[i][j] > maxVal) maxVal = m[i][j], maxRow = i;
            if (m[i][j] < minVal) minVal = m[i][j], minCol = j;
        }
    for (int i = 0; i < 7; i++)
        skalyr += m[maxRow][i] * m[i][minCol];
    cout << skalyr << endl;
    return 0;
}