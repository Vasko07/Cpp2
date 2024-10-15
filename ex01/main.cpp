/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:38 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 17:50:15 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"
#include <iostream>

int main( void ) {
FixedPointNumber a;
FixedPointNumber const b( 10 );
FixedPointNumber const c( 42.42f );
FixedPointNumber const d( b );
a = FixedPointNumber( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
