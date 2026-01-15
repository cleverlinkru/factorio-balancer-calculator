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
        if (row[0] == "inputBelt") {
            int beltIndex = std::stoi(row[1]);
            if (!this->findBeltByIndex(beltIndex)) {
                Belt* b = this->createBelt();
                b->index = beltIndex;
                this->inputBelts.push_back(b);
            }
        }

        if (row[0] == "destOutputBelt") {
            int beltIndex = std::stoi(row[1]);
            if (!this->findBeltByIndex(beltIndex)) {
                Belt* b = this->createBelt();
                b->index = beltIndex;
                this->destOutputBelts.push_back(b);
            }
        }

        if (row[0] == "innerBelt") {
            int beltIndex = std::stoi(row[1]);
            if (!this->findBeltByIndex(beltIndex)) {
                Belt* b = this->createBelt();
                b->index = beltIndex;
                this->innerBelts.push_back(b);
            }
        }

        if (row[0] == "item") {
            int beltIndex = std::stoi(row[1]);
            std::string type = row[2];
            double flow = std::stod(row[3]);

            for (const auto b : this->belts) {
                if (b->index == beltIndex) {
                    Item* item = new Item();
                    item->type = type;
                    item->flow = flow;
                    b->items.push_back(item);
                    break;
                }
            }
        }

        if (row[0] == "splitter") {
            Splitter* splitter = new Splitter();
            if (row[1] != "") {
                int leftInputBeltIndex = std::stoi(row[1]);
                splitter->leftInput = this->findBeltByIndex(leftInputBeltIndex);
            }
            if (row[2] != "") {
                int rightInputBeltIndex = std::stoi(row[2]);
                splitter->rightInput = this->findBeltByIndex(rightInputBeltIndex);
            }
            if (row[3] != "") {
                int leftOutputBeltIndex = std::stoi(row[3]);
                splitter->leftOutput = this->findBeltByIndex(leftOutputBeltIndex);
            }
            if (row[4] != "") {
                int rightOutputBeltIndex = std::stoi(row[4]);
                splitter->rightOutput = this->findBeltByIndex(rightOutputBeltIndex);
            }
            int inputPriority = std::stoi(row[5]);
            int outputPriority = std::stoi(row[6]);
            this->splitters.push_back(splitter);
        }
    }

    for (const auto destBelt : this->destOutputBelts) {
        Belt* belt = destBelt->copy();
        belt->items.clear();
        this->outputBelts.push_back(belt);
    }
}

void Scheme::printToConsole() {
    std::cout << "---inputBelts---" << std::endl;
    for (const auto b : this->inputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "---destOutputBelts---" << std::endl;
    for (const auto b : this->destOutputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "---outputBelts---" << std::endl;
    for (const auto b : this->outputBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "---innerBelts---" << std::endl;
    for (const auto b : this->innerBelts) {
        b->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "---splitters---" << std::endl;
    for (const auto s : this->splitters) {
        s->printToConsole();
        std::cout << "---" << std::endl;
    }
    std::cout << "---lastBeltIndex---" << std::endl;
    std::cout << this->lastBeltIndex << std::endl;
}

Belt* Scheme::findBeltByIndex(int index) {
    for (Belt* belt : this->belts) {
        if (belt->index == index) {
            return belt;
        }
    }
    return nullptr;
}
