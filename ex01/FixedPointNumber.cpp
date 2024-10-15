/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:29 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/15 17:24:44 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"

// Constructor por defecto
FixedPointNumber::FixedPointNumber() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
FixedPointNumber::FixedPointNumber(const FixedPointNumber &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Usa el operador de asignación para copiar
}

FixedPointNumber::FixedPointNumber(const int num) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = num << _fractionalBits;  // Multiplica por 2^8 (desplaza a la izquierda)
}

FixedPointNumber::FixedPointNumber(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(num * (1 << _fractionalBits));  // Multiplica por 2^8 y redondea
}

// Destructor
FixedPointNumber::~FixedPointNumber() {
    std::cout << "Destructor called" << std::endl;
}

// Sobrecarga del operador de asignación
FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // Evitar autoasignación
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Devuelve el valor crudo almacenado en _fixedPointValue
int FixedPointNumber::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Establece el valor crudo almacenado en _fixedPointValue
void FixedPointNumber::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float FixedPointNumber::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);  // Divide por 2^8
}

int FixedPointNumber::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;  // Desplaza a la derecha para eliminar la parte fraccionaria
}

std::ostream& operator<<(std::ostream& os, const FixedPointNumber& fp) {
    os << fp.toFloat();
    return os;
}
