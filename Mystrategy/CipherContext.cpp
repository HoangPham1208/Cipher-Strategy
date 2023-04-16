#include "CipherContext.h"

template<typename T>
CipherContext<T>::CipherContext() = default;

template<typename T>
CipherContext<T>::~CipherContext() {
    delete strategy;
}

template<typename T>
void CipherContext<T>::setKey(T key) {
    this->key = key;
}

template<typename T>
void CipherContext<T>::setStrategy(CipherStrategy<T>* strategy) {
    this->strategy = strategy;
}

template<typename T>
void CipherContext<T>::doStrategy(std::string input, int mode) {
    this->strategy->setKey(this->key);
    // mode 0 is encode, mode 1 is decode, mode 2 is both
    if (mode == 0) {
        std::cout << "The input is: " << input << std::endl;
        std::cout << "The ciphertext (encode) is: " << this->strategy->encode(input) << std::endl;
    }
    else if (mode == 1) {
        std::cout << "The input is: " << input << std::endl;
        std::cout << "The plaintext (decode) is: " << this->strategy->decode(input) << std::endl;
    }
    else {
        std::cout << "The input is: " << input << std::endl;
        std::cout << "The ciphertext (encode) is: " << this->strategy->encode(input) << std::endl;
        std::cout << "The plaintext (decode) is: " << this->strategy->decode(input) << std::endl;
    }

}