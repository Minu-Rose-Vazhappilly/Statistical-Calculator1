#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "sqrt.c" // Include the implementation file

// Test case for the calculateSquareRoot function
void testCalculateSquareRoot() {
    // Test with a positive number
    CU_ASSERT_DOUBLE_EQUAL(calculateSquareRoot(25.0), 5.0, 0.01); // Expected: 5.0

    // Test with zero
    CU_ASSERT_DOUBLE_EQUAL(calculateSquareRoot(0.0), 0.0, 0.01); // Expected: 0.0

    // Test with a decimal number
    CU_ASSERT_DOUBLE_EQUAL(calculateSquareRoot(2.25), 1.5, 0.01); // Expected: 1.5

    // Test with a negative number
    CU_ASSERT_EQUAL(calculateSquareRoot(-4.0), -1); // Expected: -1 (error code for negative input)

    // Test with a very small positive number
    CU_ASSERT_DOUBLE_EQUAL(calculateSquareRoot(0.0001), 0.01, 0.0001); // Expected: 0.01

    CU_ASSERT_DOUBLE_EQUAL(calculateSquareRoot(3.0), 1.732, 0.001); // Expected: 1.732

}

// Main function to run the tests
int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Square Root Test Suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(pSuite, "test of calculateSquareRoot", testCalculateSquareRoot) == NULL) {
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
