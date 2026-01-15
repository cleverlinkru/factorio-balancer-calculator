#include "Splitter.h"

void Splitter::printToConsole() {
    if (this->leftInput) {
        std::cout << "leftInput" << std::endl;
        std::cout << this->leftInput->index << std::endl;
    }
    if (this->rightInput) {
        std::cout << "rightInput" << std::endl;
        std::cout << this->rightInput->index << std::endl;
    }
    if (this->leftOutput) {
        std::cout << "leftOutput" << std::endl;
        std::cout << this->leftOutput->index << std::endl;
    }
    if (this->rightOutput) {
        std::cout << "rightOutput" << std::endl;
        std::cout << this->rightOutput->index << std::endl;
    }
    std::cout << "inputPriority" << std::endl;
    std::cout << this->inputPriority << std::endl;
    std::cout << "outputPriority" << std::endl;
    std::cout << this->outputPriority << std::endl;
}
