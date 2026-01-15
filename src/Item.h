#pragma once
#include <iostream>

class Item {
    public:
        std::string type;
        double flow;

        void printToConsole();
        Item* copy();
};
