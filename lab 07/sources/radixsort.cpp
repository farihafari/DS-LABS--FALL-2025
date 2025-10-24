#include <iostream>
using namespace std;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort (used for each digit)
void countSort(int arr[], int n, int exp) {
    int output[100]; // output array
    int count[10] = {0}; // count of digits (0-9)

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so it contains actual positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (right to left to make it stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main radix sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n); // find maximum number

    // Apply counting sort for every digit (1, 10, 100, ...)
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

