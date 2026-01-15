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
    scheme->printToConsole();

    return 0;
}
