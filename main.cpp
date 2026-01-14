// mkdir Build
// cd Build
// cmake ..
// cmake --build .
// ./FactorioBalancerCalculator

#include "src/Scheme.h"

int main() {
    Scheme* scheme = new Scheme();
    scheme->loadFromInputFile();
    scheme->printToConsole();

    return 0;
}
