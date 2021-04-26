function updateInventory(arr1, arr2) {
    let longer = arr2
    if (arr1.length > arr2.length) {
        let temp = arr1
        arr1 = longer
        longer = temp
    }

    longer = longer.slice()

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

    longer.sort((a, b) => {
        return a[1] > b[1] ? 1 : a[1] === b[1] ? 0 : -1
    })
    return longer
}

module.exports = updateInventory