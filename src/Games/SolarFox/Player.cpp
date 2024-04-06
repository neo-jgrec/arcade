/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Player
*/

#include "Player.hpp"

namespace Arcade::Games {


    Player::Player()
    {
    }

    Player::~Player()
    {
    }

    void Player::headUp(void)
    {
        if (_direction.y == DOWN)
            return;
        _direction = Vector2i(NEUTRAL, UP);
        _sprite->setRotation(ROTATION_UP);
        _sprite->setDirection(_direction);
    }

    void Player::headDown(void)
    {
        if (_direction.y == UP)
            return;
        _direction = Vector2i(NEUTRAL, DOWN);
        _sprite->setRotation(ROTATION_DOWN);
        _sprite->setDirection(_direction);
    }

    void Player::headRight(void)
    {
        if (_direction.x == LEFT)
            return;
        _direction = Vector2i(RIGHT, NEUTRAL);
        _sprite->setRotation(ROTATION_RIGHT);
        _sprite->setDirection(_direction);
    }

    void Player::headLeft(void)
    {
        if (_direction.x == RIGHT)
            return;
        _direction = Vector2i(LEFT, NEUTRAL);
        _sprite->setRotation(ROTATION_LEFT);
        _sprite->setDirection(_direction);
    }

    void Player::update(float elapsedTime)
    {
        if (_moveCooldown > 0)
            _moveCooldown -= elapsedTime * (_turbo ? 2 : 1);
        else {
            _moveCooldown = 15.0f;
            move();
        }
    }
}
