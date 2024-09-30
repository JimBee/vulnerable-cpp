// conditional_inclusion.cpp
#include <iostream>

#ifdef FEATURE_ENABLED
void conditionalFunc() {
    const char* largeInput = "This is a very large input that will overflow the buffer";
    char buffer[10];
    // Vulnerable to buffer overflow
    strcpy(buffer, largeInput);
    std::cout << "Buffer content from conditionalFunc: " << buffer << std::endl;
}
#else
void conditionalFunc() {
    std::cout << "Vulnerable feature is not enabled." << std::endl;
}
#endif

void vulnerableFunction() {
    const char* largeInput = "This is a very large input that will overflow the buffer";
    char buffer[10];
    // Vulnerable to buffer overflow
    strcpy(buffer, largeInput);
    std::cout << "Buffer content from vulnerableFunction: " << buffer << std::endl;
}

int main() {
    conditionalFunc();
    vulnerableFunction();
    return 0;
}