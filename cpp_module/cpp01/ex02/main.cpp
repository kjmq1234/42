#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "String's Address: " << &str << std::endl;
    std::cout << "Pointer's Value: " << stringPTR << std::endl;
    std::cout << "Reference's Address: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "String's Value: " << str << std::endl;
    std::cout << "Pointer's Value's Value: " << *stringPTR << std::endl;
    std::cout << "Reference's Value: " << stringREF << std::endl;
}