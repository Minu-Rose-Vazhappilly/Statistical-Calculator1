#include <math.h>
#include <stdio.h>

// Function to calculate the mean
float calculateMean(int numbers[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

// Function to calculate variance
float calculateVariance(int numbers[], int size) {
    float mean = calculateMean(numbers, size);
    float variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(numbers[i] - mean, 2); // Square of the difference from mean
    }
    return variance / size; // Variance is the mean of squared differences
}

// Function to calculate standard deviation
float calculateStandardDeviation(int numbers[], int size) {
    float variance = calculateVariance(numbers, size);
    return sqrt(variance); // Standard deviation is the square root of variance
}
