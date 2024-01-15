/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:54:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/15 17:21:34 by mgagne           ###   ########.fr       */
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
		int nb;
		static const int fixedBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &new_cpy);
		Fixed(const int new_nb);
		Fixed(const float new_nb);
		~Fixed(void);
		void operator=(const Fixed &new_cpy);
		void setRawBits(const int raw);
		int getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
	};

	std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixedObj);
	
#endif
