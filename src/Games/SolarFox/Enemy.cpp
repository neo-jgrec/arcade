/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Enemy
*/

#include "Enemy.hpp"

#include <random>

namespace Arcade::Games {

    Enemy::Enemy()
    {
    }

    Enemy::~Enemy()
    {
    }

    bool Enemy::shoot(float elapsedTime)
    {
        _reloadTime -= elapsedTime;
        if (_reloadTime > 0)
            return false;
        _reloadTime = 60.0f;
        float shootProbability = (std::rand() % 100) / (100 - _shootProbability);
        if (shootProbability > 0)
            return true;
        return false;
    }

    bool Enemy::update(float elapsedTime)
    {
        if (_isActive == false) {
            _respawnTime -= elapsedTime;
            if (_respawnTime <= 0) {
                _isActive = true;
                _respawnTime = 30.0f;
            }
            return false;
        }
        if (_moveCooldown > 0) {
            _moveCooldown = _moveCooldown - elapsedTime;
        } else {
            _moveCooldown = 45.0f;
            if (_position == _boundaryA || _position == _boundaryB) {
                _direction.x = _direction.x * -1;
                _direction.y = _direction.y * -1;
            }
            move();
        }
        return shoot(elapsedTime);
    }

}