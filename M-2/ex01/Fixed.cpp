#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& instance) {
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}
Fixed::Fixed(const int value) : fixedPoint(value << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;

}
Fixed::Fixed(const float value) : fixedPoint(roundf(value * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &instance) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = instance.getRawBits();
	return *this;
}
std::ostream& operator<<(std::ostream &flux, Fixed const& value) {
	flux << value.toFloat();
	return flux;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const {
	return float(this->fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->fixedPoint >> this->fractionalBits;
}