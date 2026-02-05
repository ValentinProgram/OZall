#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void cocktail_sort(int arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;
    bool swapped = true;
    int start = 0, end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            comp++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        end--;

        for (int i = end; i > start; i--) {
            comp++;
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swaps++;
                swapped = true;
            }
        }
        start++;
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
    cocktail_sort(arr, n, comp, swaps);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n" << comp << " " << swaps;

    delete[] arr;
}