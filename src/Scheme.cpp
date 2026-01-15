#include "Scheme.h"

Belt* Scheme::createBelt(int index) {
    Belt* belt = new Belt();
    if (index > 0) {
        belt->index = index;
        if (index > this->lastBeltIndex) {
            this->lastBeltIndex = index;
        }
    } else {
        this->lastBeltIndex++;
        belt->index = this->lastBeltIndex;
    }
    this->belts.push_back(belt);
    return belt;
}

void Scheme::loadFromInputFile(std::string filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    while (std::getline(inputFile, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string field;

        while (std::getline(ss, field, ',')) {
            row.push_back(field);
        }
        data.push_back(row);
    }

    inputFile.close();

    for (const auto& row : data) {
        bool isIn = (row[0] == "in");
        bool isOut = (row[0] == "out");

        if (!isIn && !isOut) {
            continue;
        }

        int beltIndex = std::stoi(row[1]);
        std::string type = row[2];
        double flow = std::stod(row[3]);

        if (isIn) {
            bool isHandled = false;
            for (int i = 0; i < this->inputBelts.size(); i++) {
                if (this->inputBelts[i]->index == beltIndex) {
                    Item* _item = new Item();
                    _item->type = type;
                    _item->flow = flow;
                    this->inputBelts[i]->items.push_back(_item);
                    isHandled = true;
                    break;
                }
            }

            if (!isHandled) {
                Belt* b = this->createBelt();
                b->index = beltIndex;
                Item* c = new Item();
                c->type = type;
                c->flow = flow;
                b->items.push_back(c);
                this->inputBelts.push_back(b);
            }
        }

        if (isOut) {
            bool isHandled = false;
            for (int i = 0; i < this->destOutputBelts.size(); i++) {
                if (this->destOutputBelts[i]->index == beltIndex) {
                    Item* _item = new Item();
                    _item->type = type;
                    _item->flow = flow;
                    this->destOutputBelts[i]->items.push_back(_item);
                    isHandled = true;
                    break;
                }
            }

            if (!isHandled) {
                Belt* b = this->createBelt();
                b->index = beltIndex;
                Item* c = new Item();
                c->type = type;
                c->flow = flow;
                b->items.push_back(c);
                this->destOutputBelts.push_back(b);
            }
        }
    }

    for (const auto destBelt : this->destOutputBelts) {
        Belt* belt = destBelt->copy();
        this->outputBelts.push_back(belt);
    }
}

void Scheme::printToConsole() {
    std::cout << "inputBelts" << std::endl;
    for (const auto b : this->inputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "destOutputBelts" << std::endl;
    for (const auto b : this->destOutputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "outputBelts" << std::endl;
    for (const auto b : this->outputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "innerBelts" << std::endl;
    for (const auto b : this->innerBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "splitters" << std::endl;
    for (const auto s : this->splitters) {
        s->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "lastBeltIndex" << std::endl;
    std::cout << this->lastBeltIndex << std::endl;
}
