#pragma once

#include <iostream>

class Fixed {
	private:
		int					fixedPoint;
		const static int	fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& instance);
		Fixed& operator=(const Fixed &instance);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
