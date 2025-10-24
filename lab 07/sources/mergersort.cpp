#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int leftSize = mid - start + 1;   // size of left elements
    int rightSize = end - mid;         // size of right elements

    int left[leftSize], right[rightSize];    // temp arrays

    // Copy data into temp arrays
    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];         // arr[start] to arr[mid]
    for (int j = 0; j < rightSize; j++)
        right[j] = arr[mid + 1 + j];      // arr[mid+1] arr[end]

    // Merge back into arr[start..end]
    int i = 0;        // index for left[]
    int j = 0;        // index for right[]
    int k = start;    // index for arr[]

    // While both arrays have elements, pick the smaller and place into arr[k]
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {  // <= preserves stability
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from left[] (if any)
    while (i < leftSize) {
        arr[k] = left[i];
        i++; k++;
    }

    // Copy any remaining elements from right[] (if any)
    while (j < rightSize) {
        arr[k] = right[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);     // Sort left half
        mergeSort(arr, mid + 1, end);   // Sort right half
        merge(arr, start, mid, end);    // Merge them
    }
}

int main() {
    int arr[] = {12, 1, 7, 4, 10, 5, 9, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

