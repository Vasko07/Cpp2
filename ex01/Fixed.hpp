/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:18 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 17:51:47 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

 #include <cmath>
 #include <iostream>

class Fixed {
private:
    int _fixedPointValue;                        // Almacena el valor del número de punto fijo
    static const int _fractionalBits = 8;        // Número de bits fraccionarios (constante, siempre 8)

public:
    // Constructor por defecto que inicializa el valor a 0
    Fixed();

    // Constructor de copia
    Fixed(const Fixed &other);

    // Constructor con entero
    Fixed(const int num);

    // Constructor con float
    Fixed(const float num);
    
    // Destructor
    ~Fixed();

    // Sobrecarga del operador de asignación
    Fixed& operator=(const Fixed &other);

    // Devuelve el valor crudo almacenado
    int getRawBits() const;

    // Establece el valor crudo
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif // FIXED_HPP
