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

void initArray(Array *a, size_t init_size)
{
    a->array = malloc(init_size * sizeof(int));
    a->used = 0;
    a->size = init_size;
}

void insertArray(Array *a, int element)
{
    if (a->used == a->size)
    {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

/*
 * Calculates the symmetric difference of two
 * sets.
 *
 * Arguments: 
 *      arg1 -- the first set 
 *      arg2 -- the second set
 *
 * Returns: the symmetric difference of two sets
 */
Array *sym_pairwise(const Array *arg1, const Array *arg2)
{
    Array *result = malloc(sizeof(Array));

    for (int i = 0; i < arg1->used; i++)
    {
    }
    return arg1;
}

/**
 * Return the symmetric difference of two or more
 * sets. If only one set is input, the same set is
 * returned unmodified. If no set is input, null
 * is returned.
 *
 * Arguments: 
 *      args: n different sets
 *
 * Returns: The symmetric difference of two or
 * more sets
 */
Array *sym(int num_args, ...)
{
    va_list valist;
    va_start(valist, num_args);

    // Simulate recursion with a stack. Grabbing
    // the arguments from valist is like grabbing
    // from a stack. Current is the first set to
    // compare.
    Array *current = va_arg(valist, Array *);
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

int main()
{
    // sym([1, 2, 3], [5, 2, 1, 4])
    // [3, 4, 5]

    Array test1_input1;
    test1_input1.array = (int[]){1, 2, 3};
    Array test1_input2;
    test1_input2.array = (int[]){5, 2, 1, 4};
    printf("%d\n", test1_input2.array[3]);
    printf("%p\n", (int[]){1, 2, 3});

    // sym([1, 2, 3, 3], [5, 2, 1, 4])
    // [3, 4, 5]

    // sym([1, 2, 3], [5, 2, 1, 4, 5])
    // [3, 4, 5]

    // sym([1, 2, 5], [2, 3, 5], [3, 4, 5])
    // [1, 4, 5]
    Array test4_input1;
    Array test4_input2;
    Array test4_input3;
    Array test4_output;
    test4_input1.array = (int[]){1, 2, 5};
    test4_input1.size = test4_input1.used = 3;
    test4_input2.array = (int[]){2, 3, 5};
    test4_input2.size = test4_input2.used = 3;
    test4_input3.array = (int[]){3, 4, 5};
    test4_input3.size = test4_input3.used = 3;
    test4_output.array = (int[]){1, 4, 5};
    test4_output.size = test4_output.used = 3;
    printf("%d\n", test4_input1.array[2]);
    sym(3, &test4_input1, &test4_input2, &test4_input3);

    // sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5])
    // [1, 4, 5]

    // sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4,
    // 6, 6], [1, 2, 3])
    // [2, 3, 4, 6, 7]

    // sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6,
    // 6], [1, 2, 3], [5, 3, 9, 8], [1])
    // [1, 2, 4, 5, 6, 7, 8, 9]
    return 0;
}