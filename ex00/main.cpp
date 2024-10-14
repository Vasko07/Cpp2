/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:38 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/14 17:29:28 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"
#include <iostream>

int main() {
    FixedPointNumber a;          // Constructor por defecto
    FixedPointNumber b(a);       // Constructor de copia
    FixedPointNumber c;          // Constructor por defecto
    c = b;            // Operador de asignación

    std::cout << a.getRawBits() << std::endl;  // Llamada a getRawBits()
    std::cout << b.getRawBits() << std::endl;  // Llamada a getRawBits()
    std::cout << c.getRawBits() << std::endl;  // Llamada a getRawBits()

    return 0;
}
