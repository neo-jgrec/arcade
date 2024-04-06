/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Fuzors
*/

#include "Fuzors.hpp"

#include <random>
#include <ctime>

namespace Arcade::Games {

    Fuzors::Fuzors()
    {
        std::srand(std::time(nullptr));
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

    void Fuzors::update(float deltaT)
    {
        _spawnTime -= deltaT;
        if (_spawnTime <= 0) {
            _fuzors.push_back(Vector2i(4 + rand() % 10, 4 + rand() % 10));
            _spawnTime = 50.0f;
        }
    }
};
