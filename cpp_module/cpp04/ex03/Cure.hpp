#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const & src);
        Cure & operator=(Cure const & src);
        virtual ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif