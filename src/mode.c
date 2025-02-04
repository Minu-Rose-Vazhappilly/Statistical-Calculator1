#include <stdio.h>

// Function to calculate the mode of an array
int calculateMode(int numbers[], int size) {
    int maxCount = 0;   // Maximum frequency of any number
    int mode = numbers[0]; // The mode (most frequent number)

    for (int i = 0; i < size; i++) {
        int count = 0;

        // Count occurrences of numbers[i]
        for (int j = 0; j < size; j++) {
            if (numbers[j] == numbers[i]) {
                count++;
            }
        }

        // Update mode if this number has a higher frequency
        if (count > maxCount) {
            maxCount = count;
            mode = numbers[i];
        }
    }

    return mode;
}
