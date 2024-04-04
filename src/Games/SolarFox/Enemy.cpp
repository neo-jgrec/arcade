/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Enemy
*/

#include "Enemy.hpp"

#include <random>
#include <ctime>

namespace Arcade::Games {

    Enemy::Enemy()
    {
        std::srand(std::time(nullptr));
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::shoot(float elapsedTime)
    {    
        _reloadTime -= elapsedTime;
        if (_reloadTime > 0)
            return;
        _reloadTime = 10.0f;
        if ((std::rand() % 100) / (100 - _shootProbability) < 0)
            return;
        // Shoot
    }

    void Enemy::update(float elapsedTime)
    {
        if (_isActive == false) {
            _respawnTime -= elapsedTime;
            if (_respawnTime <= 0) {
                _isActive = true;
                _respawnTime = 30.0f;
            }
            return;
        }
        shoot(elapsedTime);
        //move();
    }

}