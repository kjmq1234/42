#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(Fixed const &src) {
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

Fixed::Fixed(const int value) {
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
    out << value.toFloat();
    return out;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractionalBits);
}


int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

bool Fixed::operator>(Fixed const &rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void) {
    this->_value++;
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->_value--;
    return *this;
}

const Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a <= b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a >= b)
        return a;
    return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    if (a <= b)
        return a;
    return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    if (a >= b)
        return a;
    return b;
}