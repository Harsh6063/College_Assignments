#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    int i, j, v;
    for(i = 1; i < n; i++) {
        v = arr[i];
        j = i;
        // Move elements of arr[0..i-1], that are greater than v, to one position ahead of their current position
        while(j > 0 && arr[j-1] > v) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
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

    InsertionSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
