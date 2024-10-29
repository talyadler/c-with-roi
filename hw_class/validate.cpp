#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "validate.hpp"

// Validate char user input
void validatechar(const std::string& prompt, char* output, size_t size){
	std::string input;
	std::cout << prompt;
    std::getline(std::cin >> std::ws, input);
    strncpy(output, input.c_str(), size - 1);
    output[size - 1] = '\0';
}

// Validate integer user input
unsigned int validateint(const std::string& prompt){
    int tempValue;
	std::cout << prompt;
    while (true) {
        	if (std::cin >> tempValue && tempValue > 0){
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return static_cast<unsigned int>(tempValue);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printf("Bad input. Enter integer: ");
	}
}

// Validate float user input
float validatefloat(const std::string& prompt) {
    float value;
	std::cout << prompt;
    while (true) {
       if (std::cin >> value || value < 0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		return value;
	   }
	   std::cin.clear();
	   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	   printf("Bad input. Enter positive number: ");
	}
}
