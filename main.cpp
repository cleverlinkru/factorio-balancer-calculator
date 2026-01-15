// mkdir Build
// cd Build
// cmake ..
// cmake --build .
// ./FactorioBalancerCalculator

#include "src/Scheme.h"

int main(int argc, char* argv[]) {
    Scheme* scheme = new Scheme();
    scheme->loadFromFile("in.csv");
    scheme->newFile("out.csv");
    scheme->saveToFile("out.csv");

    if (std::string(argv[1]) == "calc") {
        int iterCount = std::stoi(argv[2]);
        for (int i = 1; i <= iterCount; i++) {
            scheme->calculate();
            scheme->saveToFile("out.csv");
        }
    }
//    scheme->printToConsole();

    return 0;
}
