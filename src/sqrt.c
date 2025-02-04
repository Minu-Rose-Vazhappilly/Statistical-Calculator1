#include <math.h>
#include <stdio.h>

// Function to calculate the square root of a number
float calculateSquareRoot(float number) {
    if (number < 0) {
        // Return -1 for negative inputs (as square roots of negatives are undefined for real numbers)
        return -1;
    }
    return sqrt(number); // Use the math library's sqrt function
}
