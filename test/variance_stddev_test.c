#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "variance_stddev.c" // Include the implementation file

// Test case for variance and standard deviation
void testVarianceAndStandardDeviation() {
    // Test Case 1: Positive integers
    int data1[] = {2, 4, 6, 8, 10};
    CU_ASSERT_DOUBLE_EQUAL(calculateVariance(data1, 5), 8.0, 0.01); // Expected variance: 8.0
    CU_ASSERT_DOUBLE_EQUAL(calculateStandardDeviation(data1, 5), 2.828, 0.01); // Expected stddev: ~2.828

    // Test Case 2: Identical numbers
    int data2[] = {5, 5, 5, 5, 5};
    CU_ASSERT_DOUBLE_EQUAL(calculateVariance(data2, 5), 0.0, 0.01); // Expected variance: 0.0
    CU_ASSERT_DOUBLE_EQUAL(calculateStandardDeviation(data2, 5), 0.0, 0.01); // Expected stddev: 0.0

    // Test Case 3: Negative numbers
    int data3[] = {-3, -6, -9};
    CU_ASSERT_DOUBLE_EQUAL(calculateVariance(data3, 3), 6.0, 0.01); // Expected variance: 6.0
    CU_ASSERT_DOUBLE_EQUAL(calculateStandardDeviation(data3, 3), 2.449, 0.01); // Expected stddev: ~2.449

    // Test Case 4: Mixed numbers
    int data4[] = {1, -1, 3, -3};
    CU_ASSERT_DOUBLE_EQUAL(calculateVariance(data4, 4), 5.0, 0.01); // Expected variance: 5.0
    CU_ASSERT_DOUBLE_EQUAL(calculateStandardDeviation(data4, 4), 2.236, 0.01); // Expected stddev: ~2.236
}

// Main function to run the tests
int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Variance and Standard Deviation Test Suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(pSuite, "test of Variance and Standard Deviation", testVarianceAndStandardDeviation) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE); // Verbose mode for detailed output
    CU_basic_run_tests();

    // Clean up the registry and return
    CU_cleanup_registry();
    return CU_get_error();
}
