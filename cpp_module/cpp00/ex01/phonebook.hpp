#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iomanip>
# include "contact.hpp"
# include <cstring>
class Phonebook
{
    private:
        Contact		contacts[8];
        int			contactCount;

    public:
        Phonebook();
        ~Phonebook();
        void		add_contact();
        void		search_contact();
};

#endif