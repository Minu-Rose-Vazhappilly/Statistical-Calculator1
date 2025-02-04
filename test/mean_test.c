#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "mean.c" // Include the implementation file

// Test case for the calculateMean function
void testCalculateMean() {
    int data1[] = {2, 4, 6, 8, 10};
    CU_ASSERT_DOUBLE_EQUAL(calculateMean(data1, 5), 6.0, 0.01); // Expected mean is 6.0

    int data2[] = {1, 1, 1, 1, 1};
    CU_ASSERT_DOUBLE_EQUAL(calculateMean(data2, 5), 1.0, 0.01); // Expected mean is 1.0

    int data3[] = {-3, -6, -9};
    CU_ASSERT_DOUBLE_EQUAL(calculateMean(data3, 3), -6.0, 0.01); // Expected mean is -6.0
}

// Main function to run the tests
int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Mean Test Suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(pSuite, "test of calculateMean", testCalculateMean) == NULL) {
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
