
#include <iostream>
#include "check_string.h"

#ifdef STD_REGEX
#include "std_regex/std_regex.h"
#elif defined FLEX 
#include "flex/flex_regex.h"
#elif defined SMC 
#include "smc/AppClass.h"

#endif

int main() {

    std::cout << "In use: ";

    CheckString *checker = nullptr;

    #ifdef STD_REGEX
    checker = new StdCheckString{};
    std::cout << "std::regex";
    #elif defined FLEX 
    checker = new FlexCheckString{};
    std::cout << "flex++";
    #elif defined SMC 
    checker = new SmcCheckString{};
    std::cout << "smc";
    #endif
    std::cout << std::endl;

    std::string line;

    while (!std::getline(std::cin, line).eof()) {
        bool result = (*checker)(line);
        std::cout << result << ' ';
    } 
    checker->print();
    std::cout << std::endl;
    //delete checker;

    return 0;
}

