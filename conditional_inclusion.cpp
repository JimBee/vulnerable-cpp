// conditional_inclusion.cpp
#include <iostream>

#ifdef FEATURE_ENABLED
void featureFunction() {
    std::cout << "Vulnerable feature is enabled!" << std::endl;
    char buffer[10];
    std::cout << "Enter a string: ";
    std::cin >> buffer; // This can cause buffer overflow if input exceeds 10 characters
    std::cout << "You entered: " << buffer << std::endl;
}
#else
void featureFunction() {
    std::cout << "Vulnerable feature is not enabled." << std::endl;
}
#endif

int main() {
    featureFunction();
    return 0;
}