/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Lasers
*/

#include "Lasers.hpp"

namespace Arcade::Games {

    Lasers::Lasers(Vector2i position, Vector2i direction, ISprite *sprite, Vector2i boundary)
    {
        _position = position;
        _direction = direction;
        _sprite = sprite;
        _boundary = boundary;
    }

    Lasers::~Lasers()
    {
    }

    void Lasers::update(float elapsedTime)
    {
        _moveTimer -= elapsedTime;
        if (_moveTimer <= 0) {
            move();
            _moveTimer = _moveCooldown;
        }
    }

}

