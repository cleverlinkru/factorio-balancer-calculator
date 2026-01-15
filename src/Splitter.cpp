#include "Splitter.h"

void Splitter::printToConsole() {
    std::cout << "leftInput" << std::endl;
    if (this->leftInput) {
        std::cout << this->leftInput->index << std::endl;
    }
    std::cout << "rightInput" << std::endl;
    if (this->rightInput) {
        std::cout << this->rightInput->index << std::endl;
    }
    std::cout << "leftOutput" << std::endl;
    if (this->leftOutput) {
        std::cout << this->leftOutput->index << std::endl;
    }
    std::cout << "rightOutput" << std::endl;
    if (this->rightOutput) {
        std::cout << this->rightOutput->index << std::endl;
    }
    std::cout << "inputPriority" << std::endl;
    std::cout << this->inputPriority << std::endl;
    std::cout << "outputPriority" << std::endl;
    std::cout << this->outputPriority << std::endl;
}
