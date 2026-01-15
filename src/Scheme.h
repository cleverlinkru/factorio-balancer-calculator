#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Belt.h"
#include "Splitter.h"

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
        void loadFromInputFile(std::string filename);
        void printToConsole();
};
