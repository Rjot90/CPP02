#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    _fixedValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & obj) {
    *this = obj;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int integer) {
    std::cout << "Integer constructor called";
    _fixedValue = integer << _fractBits;
}

Fixed::Fixed(float floatNum) {
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = roundf(floatNum * (1 << _fractBits));
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

float Fixed::toFloat(void) const {
    return (float)(_fixedValue) / (1 << _fractBits);
}

int Fixed::toInt(void) const {
    return _fixedValue >> _fractBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed & fixed) {
    return out << fixed.toFloat();
}

/*
Si je veux stocker un nombre tel que : 5.5

il faut que je le multiplie par 256 pour garder les decimales en memoire
fixedValue = 5.5 * 256 = 1408

---

pour convertir cette valeur stocker en memoire en int on doit par exemple faire:

toInt() = _fixedValue >> _fractBits = 1408 >> _fractBits

On decale les bits vers la droite pour commencer par le bit le moins signifactif.

---

pour toFloat on va decaler les bits vers la gauche par exemple:

toFloat() = (float)_fixedValue / (1 << _fractBits) =
    (cast de float) = 1408 / (256)

On oublie pas de cast pour passer d'un int a un nombre a virgule.

reviens a: 256 = 2^8 = (1 << _fracBits)

---

Surchage d'operateur va permettre de dire a la funct "std::ostream" ce qu'elle doit ecrire
si je lui passe une class Fixed

pour cela j'ai une declaration dans le .hpp et l'application dans le .cpp

je vais lui dire que: 

sur sa sortie nommee out je retourne la conversion "toFloat" = out << Fixed.toFloat();

l'operateur << est donc surcharger et sais quoi donner a la fonction std::cout.

merci pour les snus.
*/