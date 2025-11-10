#include "Fixed.hpp"

Fixed::Fixed() {
    _fixedValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & obj) {
    *this = obj;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed & obj) {
    std::cout << "Copy assignement called" << std::endl;
    if (this != &obj)
        this->_fixedValue = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedValue;
}

void Fixed::setRawBit(int const raw) {
    this->_fixedValue = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
