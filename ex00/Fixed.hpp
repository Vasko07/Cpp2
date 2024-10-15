/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:18 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/14 17:26:34 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;                        // Almacena el valor del número de punto fijo
    static const int _fractionalBits = 8;        // Número de bits fraccionarios (constante, siempre 8)

public:
    // Constructor por defecto que inicializa el valor a 0
    Fixed();

    // Constructor de copia
    Fixed(const Fixed &other);

    // Sobrecarga del operador de asignación
    Fixed& operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Devuelve el valor crudo almacenado
    int getRawBits() const;

    // Establece el valor crudo
    void setRawBits(int const raw);
};

#endif // FIXED_HPP
