#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <string>
#include "Belt.h"
#include "Splitter.h"
#include "Item.h"

class Scheme {
    public:
        std::vector<Belt*> belts;
        std::vector<Belt*> inputBelts;
        std::vector<Belt*> outputBelts;
        std::vector<Belt*> destOutputBelts;
        std::vector<Belt*> innerBelts;
        std::vector<Splitter*> splitters;
        int lastBeltIndex = 0;

        Belt* createBelt(int index = 0);
        void loadFromFile(std::string filename);
        void newFile(std::string filename);
        void saveToFile(std::string filename);
        void printToConsole();
        Belt* findBeltByIndex(int index);
        Scheme* copy();
        void calculate();
};
