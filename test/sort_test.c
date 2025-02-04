#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "sort.c" // Include the implementation file

// Helper function to check if arrays are equal
int arraysEqual(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

// Test case for the sortArrayAscending function
void testSortArrayAscending() {
    // Test Case 1: Already sorted array
    int data1[] = {1, 2, 3, 4, 5};
    int expected1[] = {1, 2, 3, 4, 5};
    sortArrayAscending(data1, 5);
    CU_ASSERT_TRUE(arraysEqual(data1, expected1, 5)); // Expected: No change

    // Test Case 2: Reverse order array
    int data2[] = {5, 4, 3, 2, 1};
    int expected2[] = {1, 2, 3, 4, 5};
    sortArrayAscending(data2, 5);
    CU_ASSERT_TRUE(arraysEqual(data2, expected2, 5)); // Expected: Sorted in ascending order

    // Test Case 3: Random unsorted array
    int data3[] = {3, 1, 4, 5, 2};
    int expected3[] = {1, 2, 3, 4, 5};
    sortArrayAscending(data3, 5);
    CU_ASSERT_TRUE(arraysEqual(data3, expected3, 5)); // Expected: Sorted in ascending order

    // Test Case 4: Array with duplicate elements
    int data4[] = {4, 2, 2, 5, 3};
    int expected4[] = {2, 2, 3, 4, 5};
    sortArrayAscending(data4, 5);
    CU_ASSERT_TRUE(arraysEqual(data4, expected4, 5)); // Expected: Sorted in ascending order

    // Test Case 5: Single element array
    int data5[] = {42};
    int expected5[] = {42};
    sortArrayAscending(data5, 1);
    CU_ASSERT_TRUE(arraysEqual(data5, expected5, 1)); // Expected: No change
}

// Main function to run the tests
int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Sorting Test Suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(pSuite, "test of sortArrayAscending", testSortArrayAscending) == NULL) {
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
