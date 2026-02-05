#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubble_sort(int arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    int comp, swaps;
    bubble_sort(arr, n, comp, swaps);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n" << comp << " " << swaps;

    delete[] arr;
}