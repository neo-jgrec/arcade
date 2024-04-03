/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Projectile
*/

#include "Projectile.hpp"


namespace Arcade::Games {

    Projectile::Projectile()
    {
    }

    Projectile::~Projectile()
    {
    }

    void Projectile::setVelocity(int newVelocity)
    {
        if (newVelocity < 0)
            throw std::invalid_argument("Velocity can't be negative");
        else 
            velocity = newVelocity;
    }
};