/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:24:29 by gpinilla          #+#    #+#             */
/*   Updated: 2024/10/14 17:26:34 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"
#include <iostream>

// Constructor por defecto
FixedPointNumber::FixedPointNumber() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
FixedPointNumber::FixedPointNumber(const FixedPointNumber &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Usa el operador de asignación para copiar
}

// Sobrecarga del operador de asignación
FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // Evitar autoasignación
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
FixedPointNumber::~FixedPointNumber() {
    std::cout << "Destructor called" << std::endl;
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
