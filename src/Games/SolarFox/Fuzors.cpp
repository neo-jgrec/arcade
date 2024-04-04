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

    void Fuzors::removeFuzor(Vector2i fuzor)
    {
        for (size_t i = 0; i < _fuzors.size(); i++) {
            if (_fuzors[i] == fuzor) {
                _fuzors.erase(_fuzors.begin() + i);
                return;
            }
        }
    }

    void Fuzors::setValue(unsigned int newValue)
    {
        _value = newValue;
    }
};
