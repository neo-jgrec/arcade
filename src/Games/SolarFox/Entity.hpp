/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Player
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "SolarSprite.hpp"

namespace Arcade::Games {

    class Entity {
        public:
            Entity();
            ~Entity();

            Vector2i getPosition(void) const { return _position; }
            void setPosition(Vector2i newPosition);

            SolarSprite *getSprite(void) const { return _sprite; }
            void setSprite(SolarSprite *newSprite) { _sprite = newSprite; }

            u_int16_t getVelocity(void) const { return _velocity; }
            void setVelocity(u_int16_t newVelocity);

            Vector2i getDirection(void) const { return _direction; }
            void setDirection(Vector2i newDirection) { _direction = newDirection; }

            void move() { _position = _position + _direction; }

        protected:
            Vector2i _position = Vector2i(5, 5);
            Vector2i _direction = Vector2i(0, 0);
            SolarSprite *_sprite;
            u_int16_t _velocity = 1;
    };

};

#endif /* !ENTITY_HPP_ */
