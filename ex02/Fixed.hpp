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

    float   toFloat(void) const;
    int     toInt(void) const;

    int getRawBits(void) const;
    void setRawBit(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed & fixed);

#endif