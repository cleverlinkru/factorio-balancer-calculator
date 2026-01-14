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
        std::vector<Belt*> inputBelts;
        std::vector<Belt*> outputBelts;
        std::vector<Splitter*> splitters;
        int nextBeltIndex = 0;

        void loadFromInputFile();
        void printToConsole();
};
