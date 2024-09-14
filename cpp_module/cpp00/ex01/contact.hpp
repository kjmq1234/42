#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
    private:
        std::string	firstName;
        std::string	lastName;
        std::string	nickname;
        std::string	phoneNumber;
        std::string	darkestSecret;
    public:
        Contact();
        ~Contact();
        void		set_firstName(std::string firstName);
        void		set_lastName(std::string lastName);
        void		set_nickname(std::string nickname);
        void		set_phoneNumber(std::string phoneNumber);
        void		set_darkestSecret(std::string darkestSecret);
        std::string	get_firstName();
        std::string	get_lastName();
        std::string	get_nickname();
        std::string	get_phoneNumber();
        std::string	get_darkestSecret();
};

#endif