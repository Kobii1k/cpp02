/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:54:24 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/19 10:26:00 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	nb = 0;
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed &new_cpy)
{
	nb = new_cpy.nb;
}

Fixed 	&Fixed::operator=(const Fixed &new_cpy)
{
	this->setRawBits(new_cpy.getRawBits());
	return (*this);
}

Fixed::Fixed(const int new_nb)
{
	nb = (new_nb * (1 << fixedBits));
}
Fixed::Fixed(const float new_nb)
{
	nb = roundf(new_nb * (1 << fixedBits));
}

void	Fixed::setRawBits(int const raw)
{
	nb = raw;
}

int		Fixed::getRawBits(void) const
{
	return (nb);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

float 	Fixed::toFloat(void) const
{
	return ((double)nb / (double)(1 << fixedBits));
}

int 	Fixed::toInt(void) const
{
	return (nb >> fixedBits);
}

Fixed	Fixed::operator+(const Fixed &nb) const
{
	return (Fixed(this->toFloat() + nb.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &nb) const
{
	return (Fixed(this->toFloat() - nb.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &nb) const
{
	return (Fixed(this->toFloat() * nb.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &nb) const
{
	return (Fixed(this->toFloat() / nb.toFloat()));
}

bool	Fixed::operator<(const Fixed &nb) const
{
	return (this->toFloat() < nb.toFloat());
}

bool	Fixed::operator>(const Fixed &nb) const
{
	return (this->toFloat() > nb.toFloat());
}

bool	Fixed::operator<=(const Fixed &nb) const
{
	return (this->toFloat() <= nb.toFloat());
}

bool	Fixed::operator>=(const Fixed &nb) const
{
	return (this->toFloat() >= nb.toFloat());
}

bool	Fixed::operator==(const Fixed &nb) const
{
	return (this->toFloat() == nb.toFloat());
}

bool	Fixed::operator!=(const Fixed &nb) const
{
	return (this->toFloat() != nb.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->nb++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->nb--;
	return (*this);
}

Fixed&			Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else
		return (nb2);
}

Fixed&			Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb2 < nb1)
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb2 < nb1)
		return (nb1);
	else
		return (nb2);
}

