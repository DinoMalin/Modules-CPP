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
		Fixed	operator+(Fixed const& other);
		Fixed	operator-(Fixed const& other);
		Fixed	operator*(Fixed const& other);
		Fixed	operator/(Fixed const& other);

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		bool	operator>(Fixed const &other);
		bool	operator<(Fixed const &other);
		bool	operator>=(Fixed const &other);
		bool	operator<=(Fixed const &other);
		bool	operator==(Fixed const &other);
		bool	operator!=(Fixed const &other);

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);
};

std::ostream&	operator<<(std::ostream &flux, Fixed const& value);