def inventory_update(arg1, arg2):
    longer = arg2
    if len(arg2) > len(arg1):
        temp = arg1
        arg1 = longer
        longer = temp

    longer = longer.copy()

    for tup in arg1:
        qty = tup[0]
        name = tup[1]

        try:
            i = [x[1] for x in longer].index(name)
        except ValueError:
            i = -1

        if i < 0:
            longer.append(tup)
        else:
            longer[i][0] += qty

    longer.sort(key=lambda x: x[1])

    return longer
