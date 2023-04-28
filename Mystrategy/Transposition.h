#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include "CipherStrategy.h"

class Transposition : public CipherStrategy<std::string> {
private:
    std::string key;
public:
    Transposition();
    ~Transposition();
    void setKey(std::string key);
    std::string encode(std::string input) override;
    std::string decode(std::string input) override;
};
#ifndef TRANSPOSITION_CPP
#include "Transposition.cpp"
#endif

#endif