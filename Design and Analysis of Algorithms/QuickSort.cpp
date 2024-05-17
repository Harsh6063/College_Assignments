#include <iostream>
using namespace std;

int Partition(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void QuickSort(int *array, int p, int r) {
    if (p < r) {
        int m = Partition(array, p, r);
        QuickSort(array, p, m - 1);
        QuickSort(array, m + 1, r);
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size" << endl;
        return 1;
    }

    int* arr = new int[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
