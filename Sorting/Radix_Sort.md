## Description
Radix Sort is the linear sorting algorithm that is used for integers. In Radix sort, there is digit by digit sorting is performed that is started from the least significant digit to the most significant digit. The process of radix sort works similar to the sorting of students names, according to the alphabetical order. It is a non-comparative sorting algorithm that sorts elements by grouping them into buckets based on their digits or characters.

## Code
``` CPP

#include <bits/stdc++.h>
using namespace std;
// Get the maximum element from the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Perform counting sort based on a particular digit
void countingSort(int arr[], int n, int exp) {
    const int radix = 10; // radix is the base of the number system (in this case, decimal system)
    int output[n]; // Output array to store the sorted elements
    int count[radix] = {0}; // Count array to store the count of digits at each position

    // Store the count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % radix]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Copy the output array to arr[] so that arr[] contains the sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

```
## Run Code
https://ide.geeksforgeeks.org/online-cpp-compiler/ce4d8c74-597d-4817-ae86-c99ee96e31f8



## Complexities

### Time complexity   : 
Best Case  : O(n * k)  
Worst Case : O(n * k)
Average Case : O(n * k) 

### Space complexity  : 
Best Case: O(n + k)
Average Case: O(n + k)
Worst Case: O(n + k)

"n" represents the number of elements to be sorted, and "k" represents the average number of digits or characters in the input elements.