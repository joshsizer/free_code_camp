from inventory_update import inventory_update


class TestInventoryUpdate:
    def test_inventory_update1(self):
        assert inventory_update(
            [
                [21, "Bowling Ball"],
                [2, "Dirty Sock"],
                [1, "Hair Pin"],
                [5, "Microphone"],
            ],
            [
                [2, "Hair Pin"],
                [3, "Half-Eaten Apple"],
                [67, "Bowling Ball"],
                [7, "Toothpaste"],
            ],
        ) == [
            [88, "Bowling Ball"],
            [2, "Dirty Sock"],
            [3, "Hair Pin"],
            [3, "Half-Eaten Apple"],
            [5, "Microphone"],
            [7, "Toothpaste"],
        ]

    def test_inventory_update2(self):
        assert inventory_update(
            [
                [21, "Bowling Ball"],
                [2, "Dirty Sock"],
                [1, "Hair Pin"],
                [5, "Microphone"],
            ],
            [],
        ) == [
            [21, "Bowling Ball"],
            [2, "Dirty Sock"],
            [1, "Hair Pin"],
            [5, "Microphone"],
        ]

    def test_inventory_update3(self):
        assert inventory_update(
            [],
            [
                [2, "Hair Pin"],
                [3, "Half-Eaten Apple"],
                [67, "Bowling Ball"],
                [7, "Toothpaste"],
            ],
        ) == [
            [67, "Bowling Ball"],
            [2, "Hair Pin"],
            [3, "Half-Eaten Apple"],
            [7, "Toothpaste"],
        ]

    def test_inventory_update4(self):
        assert inventory_update(
            [
                [0, "Bowling Ball"],
                [0, "Dirty Sock"],
                [0, "Hair Pin"],
                [0, "Microphone"],
            ],
            [
                [1, "Hair Pin"],
                [1, "Half-Eaten Apple"],
                [1, "Bowling Ball"],
                [1, "Toothpaste"],
            ],
        ) == [
            [1, "Bowling Ball"],
            [0, "Dirty Sock"],
            [1, "Hair Pin"],
            [1, "Half-Eaten Apple"],
            [0, "Microphone"],
            [1, "Toothpaste"],
        ]
