/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:54:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/18 10:22:52 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <iostream>
	#include <string>

	class Fixed
	{
	private:
		int nb;
		static const int fixedBits = 8;

	public:
				Fixed(void);
				Fixed(const Fixed &new_cpy);
				~Fixed(void);
		Fixed	&operator=(const Fixed &new_cpy);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
	};
#endif
