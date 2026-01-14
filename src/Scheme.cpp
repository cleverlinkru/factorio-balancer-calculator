#include "Scheme.h"

void Scheme::loadFromInputFile() {
    std::string filename = "in.csv";
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

        if (beltIndex >= this->nextBeltIndex) {
            this->nextBeltIndex = beltIndex + 1;
        }

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
                Belt* b = new Belt();
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
            for (int i = 0; i < this->outputBelts.size(); i++) {
                if (this->outputBelts[i]->index == beltIndex) {
                    Item* _item = new Item();
                    _item->type = type;
                    _item->flow = flow;
                    this->outputBelts[i]->items.push_back(_item);
                    isHandled = true;
                    break;
                }
            }

            if (!isHandled) {
                Belt* b = new Belt();
                b->index = beltIndex;
                Item* c = new Item();
                c->type = type;
                c->flow = flow;
                b->items.push_back(c);
                this->outputBelts.push_back(b);
            }
        }
    }
}

void Scheme::printToConsole() {
    std::cout << "inputBelts" << std::endl;
    for (const auto b : this->inputBelts) {
        std::cout << b->index << std::endl;
        for (const auto i : b->items) {
            std::cout << i->type << std::endl;
            std::cout << i->flow << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    std::cout << "outputBelts" << std::endl;
    for (const auto b : this->outputBelts) {
        std::cout << b->index << std::endl;
        for (const auto i : b->items) {
            std::cout << i->type << std::endl;
            std::cout << i->flow << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    std::cout << "nextBeltIndex" << std::endl;
    std::cout << this->nextBeltIndex << std::endl;
}
