#ifndef OTHER_H
#define OTHER_H

#include "CipherStrategy.h"

// nothing in type T, so we can use int here
class Other : public CipherStrategy<int> {
public:
    Other();
    ~Other();
    void setKey(int key) override;
    std::string encode(std::string input) override;
    std::string decode(std::string input) override;
};
#ifndef OTHER_CPP
#include "Other.cpp"
#endif // OTHER_CPP

#endif // OTHER_H