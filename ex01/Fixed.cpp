/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:29 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 17:24:44 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Usa el operador de asignación para copiar
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = num << _fractionalBits;  // Multiplica por 2^8 (desplaza a la izquierda)
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(num * (1 << _fractionalBits));  // Multiplica por 2^8 y redondea
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Sobrecarga del operador de asignación
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // Evitar autoasignación
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Devuelve el valor crudo almacenado en _fixedPointValue
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Establece el valor crudo almacenado en _fixedPointValue
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);  // Divide por 2^8
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;  // Desplaza a la derecha para eliminar la parte fraccionaria
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
    os << fp.toFloat();
    return os;
}
