#include <iostream>
#include <algorithm> // For max

// Merge two sorted arrays into one sorted array
int* Merge(int* a1, int* a2, int len1, int len2) {
    int i = 0;
    int j = 0;
    int k = 0;

    int* A = new int[len1 + len2]; // Dynamically allocate memory

    while (i < len1 && j < len2) {
        if (a1[i] <= a2[j]) {
            A[k] = a1[i];
            i++;
        } else {
            A[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        A[k] = a1[i];
        i++;
        k++;
    }

    while (j < len2) {
        A[k] = a2[j];
        j++;
        k++;
    }

    return A;
}

// Recursive Merge Sort
int* MergeSort(int arr[], int start, int end) {
    if (start >= end) {
        int* singleElementArray = new int[1];
        singleElementArray[0] = arr[start];
        return singleElementArray;
    }

    int mid = start + (end - start) / 2;

    int* sorted_array1 = MergeSort(arr, start, mid);
    int* sorted_array2 = MergeSort(arr, mid + 1, end);

    int* sortedArray = Merge(sorted_array1, sorted_array2, mid - start + 1, end - mid);

    delete[] sorted_array1;
    delete[] sorted_array2;

    return sortedArray;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr, size);

    int* sortedArray = MergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(sortedArray, size);

    delete[] sortedArray;
    delete[] arr;

    return 0;
}
