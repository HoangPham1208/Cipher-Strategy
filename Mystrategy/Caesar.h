#ifndef CAESAR_H
#define CAESAR_H

#include "CipherStrategy.h"


class Caesar : public CipherStrategy<int>
{
public:
    Caesar();
    ~Caesar();
    void setKey(int key);
    std::string encode(std::string input) override;
    std::string decode(std::string input) override;
};
#ifndef CAESAR_CPP
#include "Caesar.cpp"
#endif // CAESAR_CPP

#endif // CAESAR_H