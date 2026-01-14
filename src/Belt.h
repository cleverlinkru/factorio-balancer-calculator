#pragma once
#include "Item.h"
#include <vector>

class Belt {
    public:
        int index;
        std::vector<Item*> items;
};
