#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void binary_insertion_sort(int arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int low = 0, high = i - 1;

        while (low <= high) {
            comp++;
            int mid = (low + high) / 2;
            if (key < arr[mid]) high = mid - 1;
            else low = mid + 1;
        }

        for (int j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
            swaps++;
        }
        arr[low] = key;
        swaps++;
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
    binary_insertion_sort(arr, n, comp, swaps);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n" << comp << " " << swaps;

    delete[] arr;
}