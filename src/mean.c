#include <stdio.h>

// Function to calculate the mean of an array
float calculateMean(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return (float)sum / size;
}
