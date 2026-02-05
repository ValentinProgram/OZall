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

void insertion_sort(int arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else break;
        }
        arr[j + 1] = key;
        swaps++;
    }
}

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
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    cin >> n;

    int* original = new int[n];
    for (int i = 0; i < n; i++) {
        original[i] = rand() % 100;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) cout << original[i] << " ";
    cout << endl;

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    int* arr4 = new int[n];
    int* arr5 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = original[i];
        arr2[i] = original[i];
        arr3[i] = original[i];
        arr4[i] = original[i];
        arr5[i] = original[i];
    }

    int comp, swaps;

    selection_sort(arr1, n, comp, swaps);
    cout << "\nСортировка прямым выбором: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\nC(n): " << comp << " M(n): " << swaps;

    insertion_sort(arr2, n, comp, swaps);
    cout << "\nСортировка прямым включением: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\nC(n): " << comp << " M(n): " << swaps;

    binary_insertion_sort(arr3, n, comp, swaps);
    cout << "\nСортировка двоичным включением: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << "\nC(n): " << comp << " M(n): " << swaps;

    bubble_sort(arr4, n, comp, swaps);
    cout << "\nПузырьковая сортировка: ";
    for (int i = 0; i < n; i++) cout << arr4[i] << " ";
    cout << "\nC(n): " << comp << " M(n): " << swaps;

    cocktail_sort(arr5, n, comp, swaps);
    cout << "\nШейкерная сортировка: ";
    for (int i = 0; i < n; i++) cout << arr5[i] << " ";
    cout << "\nC(n): " << comp << " M(n): " << swaps;

    delete[] original;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
}