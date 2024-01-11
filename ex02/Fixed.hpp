/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:54:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/11 19:18:02 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <iostream>
	#include <string>
	#include <cmath>

	class Fixed
	{
	private:
		int					nb;
		static const int	fixedBits = 8;

	public:

		//constructors & destructors
		Fixed(void);
		Fixed(const Fixed &new_cpy);
		Fixed(const int new_nb);
		Fixed(const float new_nb);
		~Fixed(void);

		//operators
		friend std::ostream &operator<<(std::ostream& outputStream, const Fixed &fixedObj);


		bool				operator<(const Fixed &nb) const;
		bool				operator>(const Fixed &nb) const;
		bool				operator<=(const Fixed &nb) const;
		bool				operator>=(const Fixed &nb) const;
		bool				operator==(const Fixed &nb) const;
		bool				operator!=(const Fixed &nb) const;


		void				operator=(const Fixed &new_cpy);
		Fixed				operator+(const Fixed &nb) const;
		Fixed				operator-(const Fixed &nb) const;
		Fixed				operator*(const Fixed &nb) const;
		Fixed				operator/(const Fixed &nb) const;

		Fixed				operator++(int);
		Fixed				operator++(void);
		Fixed				operator--(int);
		Fixed				operator--(void);

		//getters & setters
		void				setRawBits(const int raw);
		int					getRawBits(void) const;

		//member functions

		float 				toFloat(void) const;
		int 				toInt(void) const;
		static Fixed		&min(Fixed &nb1, Fixed &nb2);
		static const Fixed	&min(const Fixed &nb1, const Fixed &nb2);
		static Fixed		&max(Fixed &nb1, Fixed &nb2);
		static const Fixed	&max(const Fixed &nb1, const Fixed &nb2);
	};
#endif
