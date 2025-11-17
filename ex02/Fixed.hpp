#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>

class Fixed
{
private:
    int                 _fixedValue;
    static const int    _fractBits = 8;
public:
    Fixed();
    Fixed(const Fixed & obj);
    Fixed& operator=(const Fixed & obj);
    ~Fixed();

    Fixed(int integer);
    Fixed(float floatNum);

    bool operator>(const Fixed& n) const;
	bool operator<(const Fixed& n) const;
	bool operator>=(const Fixed& n) const;
	bool operator<=(const Fixed& n) const;
	bool operator==(const Fixed& n) const;
	bool operator!=(const Fixed& n) const;

	Fixed operator+(const Fixed& n) const;
	Fixed operator-(const Fixed& n) const;
	Fixed operator*(const Fixed& n) const;
	Fixed operator/(const Fixed& n) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

    float   toFloat(void) const;
    int     toInt(void) const;

    int getRawBits(void) const;
    void setRawBit(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed & fixed);

#endif