// conditional_inclusion.cpp
#include <iostream>

#ifdef FEATURE_ENABLED
void conditionalFunc() {
    std::cout << "Vulnerable feature is enabled!" << std::endl;
    char buffer[10];
    std::cout << "Enter a string: ";
    std::cin >> buffer; // This can cause buffer overflow if input exceeds 10 characters
    std::cout << "You entered: " << buffer << std::endl;
}
#else
void conditionalFunc() {
    std::cout << "Vulnerable feature is not enabled." << std::endl;
}
#endif

void vulnerableFunction(const char* input) {
    char buffer[10];
    // Vulnerable to buffer overflow
    strcpy(buffer, input);
    std::cout << "Buffer content: " << buffer << std::endl;
}

int main() {
    conditionalFunc();

    const char* largeInput = "This is a very large input that will overflow the buffer";
    vulnerableFunction(largeInput);
    
    return 0;
}