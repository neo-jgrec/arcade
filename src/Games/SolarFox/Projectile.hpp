/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Projectile
*/

#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

    #include "SolarSprite.hpp"

namespace Arcade::Games {

    class Projectile {
        public:
            Projectile();
            ~Projectile();

            Vector2i getPosition(void) { return _position; }
            void setPosition(Vector2i newPosition) { _position = newPosition; }

            SolarSprite getSprite(void) { return _sprite; }

            int getVelocity(void) { return velocity; }
            void setVelocity(int newVelocity);
        private:
            Vector2i _position = Vector2i(5, 5);
            SolarSprite _sprite;
            int velocity = 1;
    };

};

#endif /* !PROJECTILE_HPP_ */
