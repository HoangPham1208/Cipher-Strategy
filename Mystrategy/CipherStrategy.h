#ifndef CipherSTRATEGY_H
#define CipherSTRATEGY_H

#include <iostream>

template <typename T>
class CipherStrategy
{
public:
    CipherStrategy();
    virtual ~CipherStrategy();

    virtual void setKey(T key) = 0;
    virtual std::string encode(std::string input) = 0;
    virtual std::string decode(std::string input) = 0;
};

#ifndef CipherSTRATEGY_CPP
#include "CipherStrategy.cpp"
#endif // CipherSTRATEGY_CPP
#endif // CipherSTRATEGY_H