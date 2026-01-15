#include "Belt.h"

void Belt::printToConsole() {
    std::cout << this->index << std::endl;
    for (const auto i : this->items) {
        i->printToConsole();
    }
}

Belt* Belt::copy() {
    Belt* belt = new Belt();
    belt->index = this->index;
    for (const auto i : this->items) {
        Item* item = i->copy();
        belt->items.push_back(item);
    }
    return belt;
}