// mkdir Build
// cd Build
// cmake ..
// cmake --build .
// ./FactorioBalancerCalculator

#include "src/Scheme.h"
#include "src/Splitter.h"

int main() {
    Scheme* scheme = new Scheme();
    scheme->loadFromInputFile("in.csv");

    Belt* belt_1 = scheme->createBelt();
    scheme->innerBelts.push_back(belt_1);

    Splitter* splitter_1 = new Splitter();
    scheme->splitters.push_back(splitter_1);
    splitter_1->leftInput = scheme->inputBelts[0];
    splitter_1->rightInput = scheme->inputBelts[1];
    splitter_1->leftOutput = belt_1;

    Splitter* splitter_2 = new Splitter();
    scheme->splitters.push_back(splitter_2);
    splitter_2->leftInput = belt_1;
    splitter_2->leftOutput = scheme->outputBelts[0];
    splitter_2->rightOutput = scheme->outputBelts[1];

    scheme->printToConsole();

    return 0;
}
