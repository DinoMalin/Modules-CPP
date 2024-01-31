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

Fixed& Fixed::operator=(const Fixed &instance) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = instance.getRawBits();
	return *this;
}
Fixed Fixed::operator+(Fixed const& other) {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed	Fixed::operator-(Fixed const& other) {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed	Fixed::operator*(Fixed const& other) {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed	Fixed::operator/(Fixed const& other) {
	return Fixed(this->toFloat() / other.toFloat());
}

bool	Fixed::operator>(Fixed const &other) {
	return this->toFloat() > other.toFloat();
}
bool	Fixed::operator<(Fixed const &other) {
	return this->toFloat() < other.toFloat();
}
bool	Fixed::operator>=(Fixed const &other) {
	return this->toFloat() >= other.toFloat();
}
bool	Fixed::operator<=(Fixed const &other) {
	return this->toFloat() <= other.toFloat();
}
bool	Fixed::operator==(Fixed const &other) {
	return this->toFloat() == other.toFloat();
}
bool	Fixed::operator!=(Fixed const &other) {
	return this->toFloat() != other.toFloat();
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	(this->fixedPoint)++;
	return temp;
}
Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	(this->fixedPoint)--;
	return temp;
}
Fixed&	Fixed::operator++() {
	++(this->fixedPoint);
	return *this;
}
Fixed&	Fixed::operator--() {
	--(this->fixedPoint);
	return *this;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return b;
	else
		return a;
}
Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return b;
	else
		return a;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	else
		return b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	else
		return b;
}
