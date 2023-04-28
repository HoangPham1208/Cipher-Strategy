#ifndef VIEGNERE_H
#define VIEGNERE_H

#include "CipherStrategy.h"

class Vigenere : public CipherStrategy<std::string> {
private:
    std::string key;
public:
    Vigenere();
    ~Vigenere();
    void setKey(std::string key);
    std::string encode(std::string input) override;
    std::string decode(std::string input) override;
};
#ifndef VIGENERE_CPP
#include "Vigenere.cpp"
#endif 
#endif