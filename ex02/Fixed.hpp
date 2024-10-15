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
 #include <climits>

class Fixed {
private:
    int _fixedPointValue;                        // Almacena el valor del número de punto fijo
    static const int _fractionalBits = 8;        // Número de bits fraccionarios (constante, siempre 8)

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int num);
    Fixed(const float num);
    ~Fixed();

    // Sobrecarga del operador de asignación
    Fixed& operator=(const Fixed &other);

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    // Sobrecarga de operadores de comparación
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

     // Sobrecarga de operadores aritméticos
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Sobrecarga de los operadores de incremento y decremento
    Fixed& operator++();    // Pre-incremento
    Fixed operator++(int);  // Post-incremento
    Fixed& operator--();    // Pre-decremento
    Fixed operator--(int);  // Post-decremento

     // min y max (dos versiones para cada uno)
    static Fixed& min(Fixed &a, Fixed &b);                  // Para objetos no constantes
    static const Fixed& min(const Fixed &a, const Fixed &b); // Para objetos constantes

    static Fixed& max(Fixed &a, Fixed &b);                  // Para objetos no constantes
    static const Fixed& max(const Fixed &a, const Fixed &b); // Para objetos constantes
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif // FIXED_HPP
