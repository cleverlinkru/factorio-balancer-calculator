#pragma once

class Splitter {
    public:
        Belt* leftInput = nullptr;
        Belt* rightInput = nullptr;
        Belt* leftOutput = nullptr;
        Belt* rightOutput = nullptr;
        int inputPriority = 0;
        int outputPriority = 0;

        void printToConsole();
};
