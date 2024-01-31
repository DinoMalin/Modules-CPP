#pragma once

#include <iostream>

class Fixed {
	private:
		int					fixedPoint;
		const static int	fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& instance);
		Fixed(const int value);
		Fixed(const float value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed&	operator=(const Fixed &instance);
		Fixed	operator+(Fixed const& a, Fixed const& b);
		Fixed	operator-(Fixed const& a, Fixed const& b);
		Fixed	operator*(Fixed const& a, Fixed const& b);
		Fixed	operator=(Fixed const& a, Fixed const& b);
};

std::ostream&	operator<<(std::ostream &flux, Fixed const& value);