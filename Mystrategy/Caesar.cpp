#ifndef CAESAR_CPP
#define CAESAR_CPP


#include "Caesar.h"

Caesar::Caesar() = default;

Caesar::~Caesar() = default;

void Caesar::setKey(int key) {
    this->key = key;
}

std::string Caesar::encode(std::string input) {
    // ENCODE
    std::string output;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output += (input[i] - 'a' + key%26) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output += (input[i] - 'A' + key%26) % 26 + 'A';
        } else {
            output += input[i];
        }
    }
    return output;
}

std::string Caesar::decode(std::string input) {
    // DECODE
    std::string output;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output += (input[i] - 'a' - key%26 + 26) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output += (input[i] - 'A' - key%26 + 26) % 26 + 'A';
        } else {
            output += input[i];
        }
    }
    return output;
}


#endif // CAESAR_CPP