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
}

// Constructor de copia
Fixed::Fixed(const Fixed &other) {
    *this = other;  // Usa el operador de asignación para copiar
}

Fixed::Fixed(const int num) {
    this->_fixedPointValue = num << _fractionalBits;  // Multiplica por 2^8 (desplaza a la izquierda)
}

Fixed::Fixed(const float num) {
    this->_fixedPointValue = roundf(num * (1 << _fractionalBits));  // Multiplica por 2^8 y redondea
}

// Destructor
Fixed::~Fixed() {}

// Sobrecarga del operador de asignación
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {  // Evitar autoasignación
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Devuelve el valor crudo almacenado en _fixedPointValue
int Fixed::getRawBits() const {
    return this->_fixedPointValue;
}

// Establece el valor crudo almacenado en _fixedPointValue
void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;

    // Chequeo de desbordamiento en la multiplicación
    if (this->_fixedPointValue != 0 && other._fixedPointValue != 0) {
        if (this->_fixedPointValue > INT_MAX / other._fixedPointValue) {
            std::cout << "Error: Multiplication overflow" << std::endl;
            return result; // Devolver un objeto Fixed sin valor
        }
    }
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;

    // Chequeo de división por cero
    if (other._fixedPointValue == 0) {
        std::cout << "Error: Division by zero" << std::endl;
        return result; // Devolver un objeto Fixed sin valor
    }

    // Chequeo de pérdida de precisión para números pequeños
    if (this->_fixedPointValue < (1 << _fractionalBits)) {
        std::cout << "Warning: Potential loss of precision in division" << std::endl;
    }

    // Desplazamos a la izquierda los bits fraccionarios antes de realizar la división
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

// Pre-incremento
Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

// Post-incremento
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

// Pre-decremento
Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

// Post-decremento
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
