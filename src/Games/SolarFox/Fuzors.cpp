/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Fuzors
*/

#include "Fuzors.hpp"

namespace Arcade::Games {

    Fuzors::Fuzors()
    {
    }

    Fuzors::~Fuzors()
    {
    }

    void Fuzors::removeFuzorAt(int index)
    {
        _fuzors.erase(_fuzors.begin() + index);
    }

    void Fuzors::setValue(unsigned int newValue)
    {
        if (newValue < 0)
            throw std::invalid_argument("Fuzor value cannot be negative");
        else
            _value = newValue;
    }
};
