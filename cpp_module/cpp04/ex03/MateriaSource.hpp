#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _inventory[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const & src);
        MateriaSource & operator=(MateriaSource const & src);
        virtual ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif