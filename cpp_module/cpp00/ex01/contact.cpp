#include "phonebook.hpp"

Contact::Contact()
{
}

Contact::~Contact(void)
{
}


void	Contact::set_firstName(std::string firstName)
{
    this->firstName = firstName;
}

void	Contact::set_lastName(std::string lastName)
{
    this->lastName = lastName;
}

void	Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void	Contact::set_phoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void	Contact::set_darkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string	Contact::get_firstName()
{
    return (this->firstName);
}

std::string	Contact::get_lastName()
{
    return (this->lastName);
}

std::string	Contact::get_nickname()
{
    return (this->nickname);
}

std::string	Contact::get_phoneNumber()
{
    return (this->phoneNumber);
}

std::string	Contact::get_darkestSecret()
{
    return (this->darkestSecret);
}