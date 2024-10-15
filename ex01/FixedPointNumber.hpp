/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:18 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 17:51:47 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

 #include <cmath>
 #include <iostream>

class FixedPointNumber {
private:
    int _fixedPointValue;                        // Almacena el valor del número de punto fijo
    static const int _fractionalBits = 8;        // Número de bits fraccionarios (constante, siempre 8)

public:
    // Constructor por defecto que inicializa el valor a 0
    FixedPointNumber();

    // Constructor de copia
    FixedPointNumber(const FixedPointNumber &other);

    // Constructor con entero
    FixedPointNumber(const int num);

    // Constructor con float
    FixedPointNumber(const float num);
    
    // Destructor
    ~FixedPointNumber();

    // Sobrecarga del operador de asignación
    FixedPointNumber& operator=(const FixedPointNumber &other);

    // Devuelve el valor crudo almacenado
    int getRawBits() const;

    // Establece el valor crudo
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const FixedPointNumber& fp);

#endif // FIXED_HPP
