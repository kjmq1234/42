#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed &operator=(Fixed const &rhs);
        ~Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _value;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif