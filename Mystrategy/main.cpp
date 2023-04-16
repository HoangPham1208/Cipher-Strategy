#include "main.h"

#include <iostream>
#include <string>
#include <limits>

bool isNumber(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
    }
    return true;
}
int main() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Welcome to the Cipher Program!" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Please select a cipher to use:" << std::endl;
    std::cout << "1. Caesar" << std::endl;
    std::cout << "2. Vigenere" << std::endl;
    std::cout << "3. Transposition" << std::endl;
    std::cout << "4. Atbash" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    std::string choice;
    getline(std::cin, choice);
    while (!isNumber(choice) || std::stoi(choice) < 1 || std::stoi(choice) > 5) {
        std::cout << "Invalid choice. Please enter a number between 1 and 5: ";
        getline(std::cin, choice);
    }
    int choiceInt = std::stoi(choice);
    if(choiceInt == 5) {
        std::cout << "Goodbye!" << std::endl;
        return 0;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Please enter a message to encode/decode: ";
    std::string message;
    getline(std::cin, message);
    std::cout << "--------------------------------------------" << std::endl;
    int mode;
    std::cout << "Please select a mode:" << std::endl;
    std::cout << "0. Encode" << std::endl;
    std::cout << "1. Decode" << std::endl;
    std::cout << "2. Encode and Decode" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    getline(std::cin, choice);
    while (!isNumber(choice) || std::stoi(choice) < 0 || std::stoi(choice) > 2) {
        std::cout << "Invalid choice. Please enter a number between 0 and 2: ";
        getline(std::cin, choice);
    }
    mode = std::stoi(choice);
    std::cout << "--------------------------------------------" << std::endl;
    std::string key;
    if(choiceInt == 1) {
            CipherContext<int> *context1 = new CipherContext<int>();
            context1->setStrategy(new Caesar());
            std::cout << "Please enter a key: ";
            getline(std::cin, key);
            while (!isNumber(key)) {
                std::cout << "Invalid key. Please enter a number: ";
                getline(std::cin, key);
            }
            context1->setKey(std::stoi(key));
            context1->doStrategy(message, mode);
    }
    else if (choiceInt == 2) {
            CipherContext<std::string> *context2 = new CipherContext<std::string>();
            context2->setStrategy(new Vigenere());
            std::cout << "Please enter a key: ";
            getline(std::cin, key);
            // key of Vigenere cipher must be all letters
            while (!isalpha(key[0])) {
                std::cout << "Invalid key. Please enter a string of letters: ";
                getline(std::cin, key);
            }
            context2->setKey(key);
            context2->doStrategy(message, mode);
    }
    else if (choiceInt == 3) {
            CipherContext<std::string> *context3 = new CipherContext<std::string>();
            context3->setStrategy(new Transposition());
            std::cout << "Please enter a key: ";
            getline(std::cin, key);
            // key of Transposition cipher must be all letters
            while (!isalpha(key[0])) {
                std::cout << "Invalid key. Please enter a string of letters: ";
                getline(std::cin, key);
            }
            context3->setKey(key);
            context3->doStrategy(message, mode);
    }
    else {
            CipherContext<int> *context4 = new CipherContext<int>();
            context4->setStrategy(new Other());
            context4->setKey(0);
            context4->doStrategy(message, mode);
    }
    std:: cout << "--------------------------------------------" << std::endl;
    std:: cout << "Thank you for using the Cipher Program!" << std::endl;
    std:: cout << "--------------------------------------------" << std::endl;
    return 0;
}