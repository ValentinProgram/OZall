#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int m[10][15], rmin[10], rmax[10], cmin[15], cmax[15];
    for (int i = 0; i < 10; i++) for (int j = 0; j < 15; j++) m[i][j] = rand() % 100;
    for (int i = 0; i < 10; i++) {
        rmin[i] = rmax[i] = m[i][0];
        for (int j = 1; j < 15; j++) {
            if (m[i][j] < rmin[i]) rmin[i] = m[i][j];
            if (m[i][j] > rmax[i]) rmax[i] = m[i][j];
        }
    }
    for (int j = 0; j < 15; j++) {
        cmin[j] = cmax[j] = m[0][j];
        for (int i = 1; i < 10; i++) {
            if (m[i][j] < cmin[j]) cmin[j] = m[i][j];
            if (m[i][j] > cmax[j]) cmax[j] = m[i][j];
        }
    }
    for (int i = 0; i < 10; i++) for (int j = 0; j < 15; j++)
        if ((m[i][j] == rmin[i] && m[i][j] == cmax[j]) || (m[i][j] == rmax[i] && m[i][j] == cmin[j]))
            cout << i << " " << j << endl;
}