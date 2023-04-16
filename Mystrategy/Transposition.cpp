#ifndef TRANSPOSITION_CPP
#define TRANSPOSITION_CPP

#include "Transposition.h"
#include <cmath>

Transposition::Transposition() = default;

Transposition::~Transposition() = default;

void Transposition::setKey(std::string key) {
    this->key = key;
}

std::string Transposition::encode(std::string input){
   // This is encode algorithm
    int row = key.length();
    int col = ceil(input.length() / (double)row);
    char matrix[row][col];
    int k = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (k < input.length()) {
                matrix[j][i] = input[k];
                k++;
            } else {
                matrix[j][i] = ' ';
            }
        }
    }
    std::string output;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            output += matrix[i][j];
        }
    }
    return output;
}

std::string Transposition::decode(std::string input){
    // This is decode algorithm
    int row = key.length();
    int col = ceil(input.length() / (double)row);
    char matrix[row][col];
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < input.length()) {
                matrix[i][j] = input[k];
                k++;
            } else {
                matrix[i][j] = ' ';
            }
        }
    }
    std::string output;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            output += matrix[j][i];
        }
    }
    return output;
}

#endif