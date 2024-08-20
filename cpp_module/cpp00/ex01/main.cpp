#include "phonebook.hpp"

int	main()
{
    Phonebook	phonebook;
    std::string	command;

    while (1)
    {
        std::cout << "ADD, SEARCH, EXIT 중 하나를 입력하세요: ";
        std::cin >> command;
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break ;
    }
    return (0);
}