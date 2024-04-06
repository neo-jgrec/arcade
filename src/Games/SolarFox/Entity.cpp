/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Entity
*/

#include "Entity.hpp"

namespace Arcade::Games {

    Entity::Entity()
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::setPosition(Vector2i newPosition)
    {
        if ((newPosition.x < 0 && newPosition.x > 9) || (newPosition.y < 0 && newPosition.y > 9))
            throw std::invalid_argument("Position is out of bounds");
        else
            _position = newPosition;
    }
};
