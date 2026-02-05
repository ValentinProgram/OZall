#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selection_sort(int arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            swaps++;
        }
    }
}

int main() {
    srand(time(0));
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;

    int comp, swaps;
    selection_sort(arr, n, comp, swaps);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n" << comp << " " << swaps;
    delete[] arr;
}