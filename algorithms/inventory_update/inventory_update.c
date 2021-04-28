/*
 * Created on Tue Apr 27 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

// I think I could have imported stdbool, but
// I wanted to try it out myself.
#define true 1
#define false 0
typedef int bool;

typedef struct InventoryItem
{
    int qty;
    char *name;
} InventoryItem;

/**
 * I might add this Array to a library I
 * collect for C. I dunno. We'll C.
 * :)
 */
typedef struct Array
{
    InventoryItem *array;
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
    a->array = malloc(init_size * sizeof(InventoryItem));
    a->used = 0;
    a->size = init_size;
}

/**
 * Insert an element into an Array.
 *
 * @param a pointer to the array to add an element
 * @param element the element to add to the array
 */
void insert_array(Array *a, InventoryItem *element)
{
    if (a->used == a->size)
    {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = *element;
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
    if (arr->used == 0)
    {
        printf("[]\n");
        return;
    }
    printf("[");
    int i = 0;
    for (i = 0; i < arr->used - 1; i++)
    {
        printf("[%d, %s], ", arr->array[i].qty, arr->array[i].name);
    }
    printf("[%d, %s]]\n", arr->array[i].qty, arr->array[i].name);
}

/**
 * Returns true if the given item is in the Array.
 * 
 * @param check the item to check for
 * @param arr a pointer to the array to check
 * 
 * @return true if check is an element in arr.
 */
bool is_in_array(const InventoryItem *check, const Array *arr)
{
    for (int i = 0; i < arr->used; i++)
    {
        if (arr->array[i].name == check->name && arr->array[i].qty == check->qty)
        {
            return true;
        }
    }
    return false;
}

/**
 * Find the index of a given element in the array.
 * 
 * This is only searching on the name element of
 * the InventoryItem struct.
 * 
 * @param check the item to find
 * @param arr a pointer to the array to check
 * 
 * @return the index of check, or -1 if it is not found
 */
int index_of(const InventoryItem *check, Array *arr)
{
    for (int i = 0; i < arr->used; i++)
    {
        if (arr->array[i].name == check->name)
        {
            return i;
        }
    }
    return -1;
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
        if (strcmp(first->array[i].name, second->array[i].name) != 0 || second->array[i].qty != second->array[i].qty)
        {
            return false;
        }
    }
    return true;
}

/**
 * Swap the values of x and y.
 *
 * @param x pointer to InventoryItem to swap with
 * y
 * @param y pointer to InventoryItem to swap with
 * x
 */
void swap(InventoryItem *x, InventoryItem *y)
{
    InventoryItem temp = *x;
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
            if (strcmp(arr->array[j].name, arr->array[min_idx].name) < 0)
                min_idx = j;

        swap(&(arr->array[i]), &(arr->array[min_idx]));
    }
}

/**
 * Add the inventory from the longer of arr2 and
 * arr1 to the other.
 *
 * (assuming arr1 is longer):
 * If an item exists in
 * both arr1 and arr2, then the quantity of the
 * item is updated in arr1. If an item exists in
 * only arr2, then the item is added to arr1. If
 * an item only exists in arr1, then that item
 * remains unaffected.
 *
 * @param {[Number, String][]} arr1 the
 * destination inventory
 * @param {[Number, String][]} arr2 the inventory
 *      to add to the destination inventory
 * @returns a combined inventory
 */
Array *inventory_update(Array *arr1, Array *arr2)
{
    // Set longer to the longer of the two arrays
    Array *longer = arr2;
    if (arr1->used > arr2->used)
    {
        longer = arr1;
        arr1 = arr2;
    }

    Array *result = malloc(sizeof(Array));
    init_array(result, longer->used + arr1->used);

    // Since longer is potentially modified, set
    // it to a copy of itself.
    for (int i = 0; i < longer->used; i++)
    {
        insert_array(result, &longer->array[i]);
    }

    longer = result;

    // Iterate over the shorter array, appending
    // items that don't exist in the longer array,
    // or updating the quantity of existing items.
    for (int i = 0; i < arr1->used; i++)
    {

        int idx = index_of(&arr1->array[i], longer);
        if (idx < 0)
        {
            insert_array(longer, &arr1->array[i]);
        }
        else
        {
            longer->array[idx].qty += arr1->array[i].qty;
        }
    }

    // Sort on the string description of each
    // inventory item.
    sort_array(longer);

    return longer;
}

/**
 * Test the inventory_update function.
 */
int main()
{
    // update_inventory([[21, "Bowling Ball"], [2,
    // "Dirty Sock"], [1, "Hair Pin"], [5,
    // "Microphone"]], [[2, "Hair Pin"], [3,
    // "Half-Eaten Apple"], [67, "Bowling Ball"],
    // [7, "Toothpaste"]])
    // should be
    // [[88, "Bowling Ball"], [2, "Dirty Sock"],
    // [3, "Hair Pin"], [3, "Half-Eaten Apple"],
    // [5, "Microphone"], [7, "Toothpaste"]]
    InventoryItem arg1_item1;
    arg1_item1.name = "Bowling Ball";
    arg1_item1.qty = 21;
    InventoryItem arg1_item2;
    arg1_item2.name = "Dirty Sock";
    arg1_item2.qty = 2;
    InventoryItem arg1_item3;
    arg1_item3.name = "Hair Pin";
    arg1_item3.qty = 1;
    InventoryItem arg1_item4;
    arg1_item4.name = "Microphone";
    arg1_item4.qty = 5;

    Array arg1;
    init_array(&arg1, 4);
    insert_array(&arg1, &arg1_item1);
    insert_array(&arg1, &arg1_item2);
    insert_array(&arg1, &arg1_item3);
    insert_array(&arg1, &arg1_item4);

    InventoryItem arg2_item1;
    arg2_item1.name = "Hair Pin";
    arg2_item1.qty = 2;
    InventoryItem arg2_item2;
    arg2_item2.name = "Half-Eaten Apple";
    arg2_item2.qty = 3;
    InventoryItem arg2_item3;
    arg2_item3.name = "Bowling Ball";
    arg2_item3.qty = 67;
    InventoryItem arg2_item4;
    arg2_item4.name = "Toothpaste";
    arg2_item4.qty = 7;

    Array arg2;
    init_array(&arg2, 4);
    insert_array(&arg2, &arg2_item1);
    insert_array(&arg2, &arg2_item2);
    insert_array(&arg2, &arg2_item3);
    insert_array(&arg2, &arg2_item4);

    InventoryItem output_item1;
    output_item1.name = "Bowling Ball";
    output_item1.qty = 88;
    InventoryItem output_item2;
    output_item2.name = "Dirty Sock";
    output_item2.qty = 2;
    InventoryItem output_item3;
    output_item3.name = "Hair Pin";
    output_item3.qty = 3;
    InventoryItem output_item4;
    output_item4.name = "Half-Eaten Apple";
    output_item4.qty = 3;
    InventoryItem output_item5;
    output_item5.name = "Microphone";
    output_item5.qty = 5;
    InventoryItem output_item6;
    output_item6.name = "Toothpaste";
    output_item6.qty = 7;

    Array output;
    init_array(&output, 6);
    insert_array(&output, &output_item1);
    insert_array(&output, &output_item2);
    insert_array(&output, &output_item3);
    insert_array(&output, &output_item4);
    insert_array(&output, &output_item5);
    insert_array(&output, &output_item6);
    print_array(&arg1);
    print_array(&arg2);
    Array *result = inventory_update(&arg1, &arg2);
    print_array(result);

    test_equal("1", &output, result);

    free_array(&arg1);
    free_array(&arg2);
    free_array(&output);

    // update_inventory([[21, "Bowling Ball"], [2,
    // "Dirty Sock"], [1, "Hair Pin"], [5,
    // "Microphone"]], [])
    // should be
    // [[21, "Bowling Ball"], [2, "Dirty Sock"],
    // [1, "Hair Pin"], [5, "Microphone"]]
    arg1_item1.name = "Bowling Ball";
    arg1_item1.qty = 21;
    arg1_item2.name = "Dirty Sock";
    arg1_item2.qty = 2;
    arg1_item3.name = "Hair Pin";
    arg1_item3.qty = 1;
    arg1_item4.name = "Microphone";
    arg1_item4.qty = 5;

    init_array(&arg1, 4);
    insert_array(&arg1, &arg1_item1);
    insert_array(&arg1, &arg1_item2);
    insert_array(&arg1, &arg1_item3);
    insert_array(&arg1, &arg1_item4);

    init_array(&arg2, 0);

    output_item1.name = "Bowling Ball";
    output_item1.qty = 21;
    output_item2.name = "Dirty Sock";
    output_item2.qty = 2;
    output_item3.name = "Hair Pin";
    output_item3.qty = 1;
    output_item4.name = "Microphone";
    output_item4.qty = 5;

    init_array(&output, 4);
    insert_array(&output, &output_item1);
    insert_array(&output, &output_item2);
    insert_array(&output, &output_item3);
    insert_array(&output, &output_item4);
    result = inventory_update(&arg1, &arg2);
    test_equal("2", &output, result);

    free_array(&arg1);
    free_array(&arg2);
    free_array(&output);

    // update_inventory([], [[67, "Bowling Ball"],
    // [2, "Hair Pin"], [3, "Half-Eaten Apple"],
    // [7, "Toothpaste"]])
    // should be
    // [[67, "Bowling Ball"], [2, "Hair Pin"], [3,
    // "Half-Eaten Apple"], [7, "Toothpaste"]]
    init_array(&arg1, 0);

    arg2_item1.name = "Hair Pin";
    arg2_item1.qty = 2;
    arg2_item2.name = "Half-Eaten Apple";
    arg2_item2.qty = 3;
    arg2_item3.name = "Bowling Ball";
    arg2_item3.qty = 67;
    arg2_item4.name = "Toothpaste";
    arg2_item4.qty = 7;

    init_array(&arg2, 4);
    insert_array(&arg2, &arg2_item1);
    insert_array(&arg2, &arg2_item2);
    insert_array(&arg2, &arg2_item3);
    insert_array(&arg2, &arg2_item4);

    output_item1.name = "Bowling Ball";
    output_item1.qty = 67;
    output_item2.name = "Hair Pin";
    output_item2.qty = 2;
    output_item3.name = "Half-Eaten Apple";
    output_item3.qty = 3;
    output_item4.name = "Toothpaste";
    output_item4.qty = 7;

    init_array(&output, 4);
    insert_array(&output, &output_item1);
    insert_array(&output, &output_item2);
    insert_array(&output, &output_item3);
    insert_array(&output, &output_item4);
    result = inventory_update(&arg1, &arg2);
    test_equal("3", &output, result);

    free_array(&arg1);
    free_array(&arg2);
    free_array(&output);

    // update_inventory([[0, "Bowling Ball"], [0,
    // "Dirty Sock"], [0, "Hair Pin"], [0,
    // "Microphone"]], [[1, "Hair Pin"], [1,
    // "Half-Eaten Apple"], [1, "Bowling Ball"],
    // [1, "Toothpaste"]])
    // should be
    // [[1, "Bowling Ball"], [0, "Dirty Sock"],
    // [1, "Hair Pin"], [1, "Half-Eaten Apple"],
    // [0, "Microphone"], [1, "Toothpaste"]]
    arg1_item1.name = "Bowling Ball";
    arg1_item1.qty = 0;
    arg1_item2.name = "Dirty Sock";
    arg1_item2.qty = 0;
    arg1_item3.name = "Hair Pin";
    arg1_item3.qty = 0;
    arg1_item4.name = "Microphone";
    arg1_item4.qty = 0;

    init_array(&arg1, 4);
    insert_array(&arg1, &arg1_item1);
    insert_array(&arg1, &arg1_item2);
    insert_array(&arg1, &arg1_item3);
    insert_array(&arg1, &arg1_item4);

    arg2_item1.name = "Hair Pin";
    arg2_item1.qty = 1;
    arg2_item2.name = "Half-Eaten Apple";
    arg2_item2.qty = 1;
    arg2_item3.name = "Bowling Ball";
    arg2_item3.qty = 1;
    arg2_item4.name = "Toothpaste";
    arg2_item4.qty = 1;

    init_array(&arg2, 4);
    insert_array(&arg2, &arg2_item1);
    insert_array(&arg2, &arg2_item2);
    insert_array(&arg2, &arg2_item3);
    insert_array(&arg2, &arg2_item4);

    output_item1.name = "Bowling Ball";
    output_item1.qty = 1;
    output_item2.name = "Dirty Sock";
    output_item2.qty = 0;
    output_item3.name = "Hair Pin";
    output_item3.qty = 1;
    output_item4.name = "Half-Eaten Apple";
    output_item4.qty = 1;
    output_item5.name = "Microphone";
    output_item5.qty = 0;
    output_item6.name = "Toothpaste";
    output_item6.qty = 1;

    init_array(&output, 6);
    insert_array(&output, &output_item1);
    insert_array(&output, &output_item2);
    insert_array(&output, &output_item3);
    insert_array(&output, &output_item4);
    insert_array(&output, &output_item5);
    insert_array(&output, &output_item6);
    result = inventory_update(&arg1, &arg2);
    test_equal("4", &output, result);

    free_array(&arg1);
    free_array(&arg2);
    free_array(&output);

    return 0;
}