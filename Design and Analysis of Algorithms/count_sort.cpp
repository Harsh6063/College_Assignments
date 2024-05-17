#include <iostream>
#include <algorithm> // for std::min and std::max
using namespace std;

void count_sort(int arr[], int l) {
    if (l <= 0) return;

    // Find the minimum and maximum elements
    int min = arr[0], max = arr[0];
    for (int i = 1; i < l; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    // Range of elements
    int range = max - min + 1;

    // Allocate memory for count array and initialize it to 0
    int* count = new int[range]();
    int* sorted = new int[l];

    // Count the occurrences of each element
    for (int i = 0; i < l; i++) {
        count[arr[i] - min]++;
    }

    // Calculate the cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    for (int i = l - 1; i >= 0; i--) {
        int elm = arr[i];
        int pos = count[elm - min] - 1;
        sorted[pos] = elm;
        count[elm - min]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < l; i++) {
        arr[i] = sorted[i];
    }

    // Free dynamically allocated memory
    delete[] count;
    delete[] sorted;
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

    count_sort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
