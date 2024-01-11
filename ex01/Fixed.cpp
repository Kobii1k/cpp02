/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:54:24 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/11 18:22:07 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	nb = 0;
}

Fixed::Fixed(const Fixed &new_cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	nb = new_cpy.nb;
}

Fixed::Fixed(const int new_nb)
{
	std::cout << "Int constructor called" << std::endl;
	nb = (new_nb * (1 << fixedBits));
}
Fixed::Fixed(const float new_nb)
{
	std::cout << "Float constructor called" << std::endl;
	nb = roundf(new_nb * (1 << fixedBits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	nb = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (nb);
}

void Fixed::operator=(const Fixed &new_cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	nb = new_cpy.nb;
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

float Fixed::toFloat(void) const
{
	return ((double)nb / (double)(1 << fixedBits));
}

int Fixed::toInt(void) const
{
	return (nb >> fixedBits);
}
