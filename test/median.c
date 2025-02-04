#include <stdio.h>

// Function to sort an array (required for median calculation)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
float calculateMedian(int numbers[], int size) {
    // Sort the array
    sortArray(numbers, size);

    // Calculate median
    if (size % 2 == 0) {
        // If even, average the two middle elements
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        // If odd, return the middle element
        return numbers[size / 2];
    }
}
