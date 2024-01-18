/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:53:59 by mgagne            #+#    #+#             */
/*   Updated: 2024/01/18 10:49:35 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(10.5f);
	Fixed d(15);
	Fixed e(10.5f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "(10.5 < 15)	:" << (c < d) << std::endl;
	std::cout << "(15 < 10.5)	:" << (d < c) << std::endl;
	std::cout << "(15 > 10.5)	:" << (d > c) << std::endl;
	std::cout << "(10.5 > 15)	:" << (c > d) << std::endl;

	std::cout << "(10.5 >= 10.5)	:" << (c >= e) << std::endl;
	std::cout << "(10.5 >= 10.5)	:" << (e >= c) << std::endl;
	std::cout << "(10.5 <= 10.5)	:" << (c <= e) << std::endl;
	std::cout << "(10.5 <= 10.5)	:" << (e <= c) << std::endl;

	std::cout << "(10.5 == 10.5)	:" << (c == e) << std::endl;
	std::cout << "(15 == 10.5)	:" << (d == c) << std::endl;

	std::cout << "min(0.0078125, 10.1016)	:" << Fixed::min(a, b) << std::endl;

	std::cout << "a	=" << a << std::endl;
	std::cout << "--a	=" << --a << std::endl;
	std::cout << "a--	=" << a-- << std::endl;
	std::cout << "a	=" << a << std::endl;
	return 0;
}
