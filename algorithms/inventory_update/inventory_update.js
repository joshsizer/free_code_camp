/*
 * Created on Sun Apr 25 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Add the inventory from the longer of arr2 and
 * arr1 to the other.
 *
 * (assuming arr1 is longer)
 * If an item exists in both arr1 and arr2, then
 * the quantity of the item is updated in arr1. If
 * an item exists in only arr2, then the item is
 * added to arr1. If an item only exists in arr1,
 * then that item remains unaffected.
 *
 * @param {[Number, String][]} arr1 the
 * destination inventory
 * @param {[Number, String][]} arr2 the inventory
 *      to add to the destination inventory
 * @returns a combined inventory
 */
function updateInventory(arr1, arr2) {
    // Set longer to the longer of the two arrays
    let longer = arr2
    if (arr1.length > arr2.length) {
        let temp = arr1
        arr1 = longer
        longer = temp
    }

    // Since longer is potentially modified, set
    // it to a copy of itself.
    longer = longer.slice()

    // Iterate over the shorter array, appending
    // items that don't exist in the longer array,
    // or updating the quantity of existing items.
    for (let tuple of arr1) {
        let qty = tuple[0]
        let name = tuple[1]

        let i = longer.map(e => e[1]).indexOf(name)
        if (i < 0) {
            longer.push(tuple)
        } else {
            longer[i][0] += qty
        }
    }

    // Sort on the string description of each
    // inventory item.
    longer.sort((a, b) => {
        return a[1] > b[1] ? 1 : a[1] === b[1] ? 0 : -1
    })

    return longer
}

module.exports = updateInventory