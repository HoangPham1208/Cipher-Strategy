#ifndef CIPHERCONTEXT_H
#define CIPHERCONTEXT_H
#include "CipherStrategy.h"

template <typename T>
class CipherContext
{
    private:
        CipherStrategy<T>* strategy;
        T key;
    public:
        CipherContext();
        ~CipherContext();
        void setKey(T key);
        void setStrategy(CipherStrategy<T>* strategy);
        void doStrategy(std::string input, int mode);
};
#ifndef CIPHERCONTEXT_CPP
#include "CipherContext.cpp"
#endif // CipherContext_CPP
#endif // CipherContext_H