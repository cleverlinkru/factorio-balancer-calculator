#pragma once
#include <iostream>
#include <vector>
#include "Item.h"

class Belt {
    public:
        int index;
        std::vector<Item*> items;

        void printToConsole();
        Belt* copy();
};
