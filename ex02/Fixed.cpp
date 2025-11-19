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
bool Fixed::operator>(const Fixed& n) const
{
	return _fixedValue > n._fixedValue; 
}

bool Fixed::operator<(const Fixed& n) const
{
	return _fixedValue < n._fixedValue;
}

bool Fixed::operator>=(const Fixed& n) const
{
	return _fixedValue >= n._fixedValue;
}

bool Fixed::operator<=(const Fixed& n) const
{
	return _fixedValue <= n._fixedValue;
}

bool Fixed::operator==(const Fixed& n) const
{
	return _fixedValue == n._fixedValue;
}

bool Fixed::operator!=(const Fixed& n) const
{
	return _fixedValue != n._fixedValue;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& n) const
{
	return Fixed(this->toFloat() + n.toFloat());
}

Fixed Fixed::operator-(const Fixed& n) const
{
	return Fixed(this->toFloat() - n.toFloat());
}

Fixed Fixed::operator*(const Fixed& n) const
{
	return Fixed(this->toFloat() * n.toFloat());
}

Fixed Fixed::operator/(const Fixed& n) const
{
	int	divide;

	divide = n.toFloat();
	if (divide == 0)
	{
		std::cout << "Error: Division by 0 forbidden."<<std::endl;
		return (-1);
	}
	return Fixed(this->toFloat() / n.toFloat());
}

// Incrementation / decrementation
Fixed& Fixed::operator++()
{
	_fixedValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{ 
	Fixed tmp(*this);
	_fixedValue++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	_fixedValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{ 
	Fixed tmp(*this);
	_fixedValue--;
	return tmp;
}

// --- Fonctions min / max ---
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
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

merci pour les snus.
*/