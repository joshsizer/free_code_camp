/*
 * Created on Mon Apr 26 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * We could have put our function definitions in a
 * header file, but I decided against it because
 * of the nature of what I'm trying to do here:
 * one or two file programming exercises. Really
 * just one file, but I'm okay with an extra one
 * for tests. It's just easier for me right now to
 * put the tests in the main function. 
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// I think I could have imported stdbool, but
// I wanted to try it out myself.
#define true 1
#define false 0
typedef int bool;

/**
 * I also might add this Array to a library I
 * collect for C. I dunno. We'll C.
 * :)
 */
typedef struct Array
{
    int *array;
    size_t used;
    size_t size;
} Array;

/**
 * Initialize an Array to have a specified size.
 *
 * @param a a pointer to an array to initialize
 * @param init_size the initial size to allocate
 */
void init_array(Array *a, size_t init_size)
{
    a->array = malloc(init_size * sizeof(int));
    a->used = 0;
    a->size = init_size;
}

/**
 * Insert an element into an Array.
 *
 * @param a pointer to the array to add an element
 * @param element the element to add to the array
 */
void insert_array(Array *a, int element)
{
    if (a->used == a->size)
    {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

/**
 * Relinquish the storage associated with this
 * Array. Must still free the Array struct separately.
 * 
 * @param a pointer to the Array to free
 */
void free_array(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

/**
 * Print an Array to the console.
 * 
 * @param a pointer to the Array to print
 */
void print_array(Array *arr)
{
    for (int i = 0; i < arr->used; i++)
    {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

/**
 * Returns true if the given item is in the Array.
 * 
 * @param check the item to check for
 * @param arr a pointer to the array to check
 * 
 * @return true if check is an element in arr.
 */
bool is_in_array(const int check, const Array *arr)
{
    for (int i = 0; i < arr->used; i++)
    {
        if (arr->array[i] == check)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * Check if two arrays are equal.
 *
 * @param first pointer to the first Array
 * @param second pointer to the second Array
 *
 * @return true if the arrays contain the same
 * elements
 */
bool are_arrays_equal(Array *first, Array *second)
{
    if (first->used != second->used)
    {
        return false;
    }
    for (int i = 0; i < first->used; i++)
    {
        if (first->array[i] != second->array[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * Swap the values of x and y.
 * 
 * @param x pointer to int to swap with y
 * @param y pointer to int to swap with x
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Test function wrapper for are_arrays_equal.
 *
 * @param test_name the identifier for this test
 * @param first pointer to the first array to
 * compare
 * @param second pointer to the second array to
 * compare
 */
void test_equal(char *test_name, Array *first, Array *second)
{
    int passed = are_arrays_equal(first, second);

    printf("Test %s: ", test_name);
    if (passed)
    {
        printf("succeeded\n");
    }
    else
    {
        printf("failed\n");
    }
}

/**
 * Simple selection sort. Not super fast (O(n^2)).
 * But it will do the job for these small arrays.
 */
void sort_array(Array *arr)
{
    for (int i = 0; i < arr->used - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < arr->used; j++)
            if (arr->array[j] < arr->array[min_idx])
                min_idx = j;

        swap(&(arr->array[i]), &(arr->array[min_idx]));
    }
}

/**
  * Calculates the symmetric difference of two
  * sets.
  *
  * 
  * @param arg1 the first set 
  * @param arg2 the second set
  *
  * @return the symmetric difference of two sets
  */
Array *sym_pairwise(const Array *arg1, const Array *arg2)
{
    Array *result = malloc(sizeof(Array));

    // Worst case is our returned array contains
    // all elements from arg1 and arg2
    init_array(result, arg1->used + arg2->used);

    // Add each element in arg1 to next as long as
    // the element is not in arg2 and not already
    // in next.
    for (int i = 0; i < arg1->used; i++)
    {
        int element = arg1->array[i];
        if (!is_in_array(element, arg2) && !is_in_array(element, result))
        {
            insert_array(result, element);
        }
    }

    // Add each element in arg2 to next as long as
    // the element is not in arg1 and not already
    // in next.
    for (int i = 0; i < arg2->used; i++)
    {
        int element = arg2->array[i];
        if (!is_in_array(element, arg1) && !is_in_array(element, result))
        {
            insert_array(result, element);
        }
    }

    return result;
}

/**
 * Return the symmetric difference of two or more
 * sets. If only one set is input, the same set is
 * returned unmodified. If no set is input, null
 * is returned.
 *
 * 
 * @param args n different sets
 *
 * @return The symmetric difference of two or
 * more sets
 */
Array *sym(int num_args, ...)
{
    if (num_args < 1)
    {
        return NULL;
    }
    va_list valist;
    va_start(valist, num_args);

    // Simulate recursion with a stack. Grabbing
    // the arguments from valist is like grabbing
    // from a stack. Current is the first set to
    // compare.
    Array *current = va_arg(valist, Array *);
    if (num_args == 1)
    {
        return current;
    }
    num_args--;
    Array *to_compare;

    // Compare sets until our stack is empty
    while (num_args > 0)
    {
        // Get the set to compare to the current
        to_compare = va_arg(valist, Array *);

        // Calculate the symmetric difference
        // between these two particular elements.
        current = sym_pairwise(current, to_compare);
        num_args--;
    }

    va_end(valist);
    return current;
}

/**
 * Test the sym() function.
 */
int main()
{
    // sym([1, 2, 3], [5, 2, 1, 4])
    // [3, 4, 5]
    Array test1_input1;
    test1_input1.array = (int[]){1, 2, 3};
    test1_input1.size = test1_input1.used = 3;
    Array test1_input2;
    test1_input2.array = (int[]){5, 2, 1, 4};
    test1_input2.size = test1_input2.used = 4;
    Array test1_output;
    test1_output.array = (int[]){3, 4, 5};
    test1_output.size = test1_output.used = 3;
    Array *test1_result = sym(2, &test1_input1, &test1_input2);
    sort_array(test1_result);
    test_equal("1 sym([1, 2, 3], [5, 2, 1, 4])", &test1_output, test1_result);
    // free our malloc'd variables
    free_array(test1_result);
    free(test1_result);

    // sym([1, 2, 3, 3], [5, 2, 1, 4])
    // [3, 4, 5]
    Array test2_input1;
    test2_input1.array = (int[]){1, 2, 3, 3};
    test2_input1.size = test2_input1.used = 4;
    Array test2_input2;
    test2_input2.array = (int[]){5, 2, 1, 4};
    test2_input2.size = test2_input2.used = 4;
    Array test2_output;
    test2_output.array = (int[]){3, 4, 5};
    test2_output.size = test2_output.used = 3;
    Array *test2_result = sym(2, &test2_input1, &test2_input2);
    sort_array(test2_result);
    test_equal("2 sym([1, 2, 3, 3], [5, 2, 1, 4])", &test2_output, test2_result);
    // free our malloc'd variables
    free_array(test2_result);
    free(test2_result);

    // sym([1, 2, 3], [5, 2, 1, 4, 5])
    // [3, 4, 5]
    Array test3_input1;
    test3_input1.array = (int[]){1, 2, 3};
    test3_input1.size = test3_input1.used = 3;
    Array test3_input2;
    test3_input2.array = (int[]){5, 2, 1, 4, 5};
    test3_input2.size = test3_input2.used = 5;
    Array test3_output;
    test3_output.array = (int[]){3, 4, 5};
    test3_output.size = test3_output.used = 3;
    Array *test3_result = sym(2, &test3_input1, &test3_input2);
    sort_array(test3_result);
    test_equal("3 sym([1, 2, 3], [5, 2, 1, 4, 5])", &test3_output, test3_result);
    // free our malloc'd variables
    free_array(test3_result);
    free(test3_result);

    // sym([1, 2, 5], [2, 3, 5], [3, 4, 5])
    // [1, 4, 5]
    Array test4_input1;
    test4_input1.array = (int[]){1, 2, 5};
    test4_input1.size = test4_input1.used = 3;
    Array test4_input2;
    test4_input2.array = (int[]){2, 3, 5};
    test4_input2.size = test4_input2.used = 3;
    Array test4_input3;
    test4_input3.array = (int[]){3, 4, 5};
    test4_input3.size = test4_input3.used = 3;
    Array test4_output;
    test4_output.array = (int[]){1, 4, 5};
    test4_output.size = test4_output.used = 3;
    Array *test4_result = sym(3, &test4_input1, &test4_input2, &test4_input3);
    sort_array(test4_result);
    test_equal("4 sym([1, 2, 5], [2, 3, 5], [3, 4, 5])", &test4_output, test4_result);
    // free our malloc'd variables
    free_array(test4_result);
    free(test4_result);

    // sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5])
    // [1, 4, 5]
    Array test5_input1;
    test5_input1.array = (int[]){1, 1, 2, 5};
    test5_input1.size = test5_input1.used = 4;
    Array test5_input2;
    test5_input2.array = (int[]){2, 2, 3, 5};
    test5_input2.size = test5_input2.used = 4;
    Array test5_input3;
    test5_input3.array = (int[]){3, 4, 5, 5};
    test5_input3.size = test5_input3.used = 4;
    Array test5_output;
    test5_output.array = (int[]){1, 4, 5};
    test5_output.size = test5_output.used = 3;
    Array *test5_result = sym(3, &test5_input1, &test5_input2, &test5_input3);
    test_equal("5 sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5])", &test5_output, test5_result);
    // free our malloc'd variables
    free_array(test5_result);
    free(test5_result);

    // sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4,
    // 6, 6], [1, 2, 3])
    // [2, 3, 4, 6, 7]
    Array test6_input1;
    test6_input1.array = (int[]){3, 3, 3, 2, 5};
    test6_input1.size = test6_input1.used = 5;
    Array test6_input2;
    test6_input2.array = (int[]){2, 1, 5, 7};
    test6_input2.size = test6_input2.used = 4;
    Array test6_input3;
    test6_input3.array = (int[]){3, 4, 6, 6};
    test6_input3.size = test6_input3.used = 4;
    Array test6_input4;
    test6_input4.array = (int[]){1, 2, 3};
    test6_input4.size = test6_input4.used = 3;
    Array test6_output;
    test6_output.array = (int[]){2, 3, 4, 6, 7};
    test6_output.size = test6_output.used = 5;
    Array *test6_result = sym(4, &test6_input1, &test6_input2, &test6_input3, &test6_input4);
    sort_array(test6_result);
    test_equal("6 sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3])", &test6_output, test6_result);
    // free our malloc'd variables
    free_array(test6_result);
    free(test6_result);

    // sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6,
    // 6], [1, 2, 3], [5, 3, 9, 8], [1])
    // [1, 2, 4, 5, 6, 7, 8, 9]
    Array test7_input1;
    test7_input1.array = (int[]){3, 3, 3, 2, 5};
    test7_input1.size = test7_input1.used = 5;
    Array test7_input2;
    test7_input2.array = (int[]){2, 1, 5, 7};
    test7_input2.size = test7_input2.used = 4;
    Array test7_input3;
    test7_input3.array = (int[]){3, 4, 6, 6};
    test7_input3.size = test7_input3.used = 4;
    Array test7_input4;
    test7_input4.array = (int[]){1, 2, 3};
    test7_input4.size = test7_input4.used = 3;
    Array test7_input5;
    test7_input5.array = (int[]){5, 3, 9, 8};
    test7_input5.size = test7_input5.used = 4;
    Array test7_input6;
    test7_input6.array = (int[]){1};
    test7_input6.size = test7_input6.used = 1;
    Array test7_output;
    test7_output.array = (int[]){1, 2, 4, 5, 6, 7, 8, 9};
    test7_output.size = test7_output.used = 8;
    Array *test7_result = sym(6, &test7_input1, &test7_input2, &test7_input3, &test7_input4, &test7_input5, &test7_input6);
    sort_array(test7_result);
    test_equal("7 sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1])", &test7_output, test7_result);
    // free our malloc'd variables
    free_array(test7_result);
    free(test7_result);

    return 0;
}