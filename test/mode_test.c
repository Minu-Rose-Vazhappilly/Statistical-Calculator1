#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "mode.c" // Include the implementation file

// Test case for the calculateMode function
void testCalculateMode() {
    // Test case 1: Single mode
    int data1[] = {1, 2, 2, 3, 4};
    CU_ASSERT_EQUAL(calculateMode(data1, 5), 2); // Mode: 2

    // Test case 2: Multiple occurrences with a clear mode
    int data2[] = {5, 5, 6, 6, 6, 7};
    CU_ASSERT_EQUAL(calculateMode(data2, 6), 6); // Mode: 6

    // Test case 3: All elements are the same
    int data3[] = {8, 8, 8, 8};
    CU_ASSERT_EQUAL(calculateMode(data3, 4), 8); // Mode: 8

    // Test case 4: No mode (all numbers have the same frequency)
    int data4[] = {1, 2, 3, 4, 5};
    CU_ASSERT_EQUAL(calculateMode(data4, 5), 1); // Default mode: First number (1)

    // Test case 5: Negative numbers
    int data5[] = {-1, -2, -2, -3, -4};
    CU_ASSERT_EQUAL(calculateMode(data5, 5), -2); // Mode: -2
}

// Main function to run the tests
int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Mode Test Suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(pSuite, "test of calculateMode", testCalculateMode) == NULL) {
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
