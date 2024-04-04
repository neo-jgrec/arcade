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
        _sprite->setAscii("P");
        _sprite->setPath(std::string("gameAssets/solarfox/sprites/player.png"));
        _sprite->setColor(Color::BLUE);
        _sprite->setShape(Shape::TRIANGLE);
    }

    Player::~Player()
    {
        delete _sprite;
    }

    void Player::setPosition(Vector2i newPosition)
    {
        if ((newPosition.x < 0 && newPosition.x > 9) || (newPosition.y < 0 && newPosition.y > 9))
            throw std::invalid_argument("Position is out of bounds");
        else
            _position = newPosition;
    }

    void Player::setVelocity(u_int16_t newVelocity)
    {
        int intCast = newVelocity;
        if (intCast < 0)
            throw std::invalid_argument("Velocity cannot be negative");
        else
            _velocity = newVelocity;
    }
};
