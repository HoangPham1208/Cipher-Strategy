#ifndef VIGENERE_CPP
#define VIGENERE_CPP

#include "Vigenere.h"


Vigenere::Vigenere() = default;

Vigenere::~Vigenere() = default;

void Vigenere::setKey(std::string key) {
    this->key = key;
}

std::string Vigenere::encode(std::string input) {
    std::string output;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            if(key[i % key.length()] >= 'a' && key[i % key.length()] <= 'z') {
                output += (input[i] - 'a' + key[i % key.length()] - 'a') % 26 + 'a';
            } else if (key[i % key.length()] >= 'A' && key[i % key.length()] <= 'Z') {
                output += (input[i] - 'a' + key[i % key.length()] - 'A') % 26 + 'a';
            } else {
                output += input[i];
            }
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            if(key[i % key.length()] >= 'a' && key[i % key.length()] <= 'z') {
                output += (input[i] - 'A' + key[i % key.length()] - 'a') % 26 + 'A';
            } else if (key[i % key.length()] >= 'A' && key[i % key.length()] <= 'Z') {
                output += (input[i] - 'A' + key[i % key.length()] - 'A') % 26 + 'A';
            } else {
                output += input[i];
            }
        } else {
            output += input[i];
        }
    }
    return output;
}

std::string Vigenere::decode(std::string input) {
    std::string output;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            if(key[i % key.length()] >= 'a' && key[i % key.length()] <= 'z') {
                output += (input[i] - 'a' - key[i % key.length()] + 'a' + 26) % 26 + 'a';
            } else if (key[i % key.length()] >= 'A' && key[i % key.length()] <= 'Z') {
                output += (input[i] - 'a' - key[i % key.length()] + 'A' + 26) % 26 + 'a';
            } else {
                output += input[i];
            }
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            if(key[i % key.length()] >= 'a' && key[i % key.length()] <= 'z') {
                output += (input[i] - 'A' - key[i % key.length()] + 'a' + 26) % 26 + 'A';
            } else if (key[i % key.length()] >= 'A' && key[i % key.length()] <= 'Z') {
                output += (input[i] - 'A' - key[i % key.length()] + 'A' + 26) % 26 + 'A';
            } else {
                output += input[i];
            }
        } else {
            output += input[i];
        }
    }
    return output;
}

#endif