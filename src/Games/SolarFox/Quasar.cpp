/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Quasar
*/

#include "Quasar.hpp"

#include <random>
#include <ctime>

namespace Arcade::Games {

    Quasar::Quasar()
    {
        std::srand(std::time(nullptr));
    }

    Quasar::~Quasar()
    {
    }

    void Quasar::removeQuasar(Vector2i fuzor)
    {
        for (size_t i = 0; i < _quasars.size(); i++) {
            if (_quasars[i] == fuzor) {
                _quasars.erase(_quasars.begin() + i);
                return;
            }
        }
    }

    void Quasar::update(float deltaT)
    {
        _spawnTime -= deltaT;
        if (_spawnTime <= 0) {
            _quasars.push_back(Vector2i(4 + rand() % 10, 4 + rand() % 10));
            _spawnTime = 100.0f;
        }
    }
};
