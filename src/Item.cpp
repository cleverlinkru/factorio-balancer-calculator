#include "Item.h"

void Item::printToConsole() {
    std::cout << this->type << std::endl;
    std::cout << this->flow << std::endl;
}

Item* Item::copy() {
    Item* item = new Item();
    item->type = this->type;
    item->flow = this->flow;
    return item;
}
