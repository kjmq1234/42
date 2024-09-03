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

        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;

        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;

        Fixed &operator++(void);
        const Fixed operator++(int);
        Fixed &operator--(void);
        const Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);

    private:
        int _value;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif