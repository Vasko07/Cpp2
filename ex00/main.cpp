/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:38 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 18:02:41 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;          // Constructor por defecto
    Fixed b(a);       // Constructor de copia
    Fixed c;          // Constructor por defecto
    c = b;            // Operador de asignación

    std::cout << a.getRawBits() << std::endl;  // Llamada a getRawBits()
    std::cout << b.getRawBits() << std::endl;  // Llamada a getRawBits()
    std::cout << c.getRawBits() << std::endl;  // Llamada a getRawBits()

    return 0;
}
