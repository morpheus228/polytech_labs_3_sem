#include "utils.h"


void BitsPrint(int nubmer, int bitness) {
  for(int i = bitness - 1; i >= 0; i--) {
    if(nubmer & (1 << i)) std::cout << "1";
    else std::cout << "0";
  }
}


unsigned int GetNumber() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        try {
            int number = std::stoi(input);
            return number;

        } catch (const std::exception& e) {
            std::cout << "Error! Isn't a number! Enter a number..." << std::endl;
        }
    }
}
