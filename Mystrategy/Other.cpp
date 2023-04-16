#ifndef OTHER_CPP
#define OTHER_CPP

#include "Other.h"

Other::Other() = default;

Other::~Other() = default;

void Other::setKey(int key) {
    // nothing to do here
}

std::string Other::encode(std::string input) {
   std::string output;
    // This is atbash cipher - encode
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output += (char)('z' - input[i] + 'a');
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output += (char)('Z' - input[i] + 'A');
        } else {
            output += input[i];
        }
    }
    return output;
}
// encode and decode are the same
std::string Other::decode(std::string input) {
    std::string output;
    // This is atbash cipher - decode
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output += (char)('z' - input[i] + 'a');
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output += (char)('Z' - input[i] + 'A');
        } else {
            output += input[i];
        }
    }
    return output;
}


#endif // OTHER_CPP