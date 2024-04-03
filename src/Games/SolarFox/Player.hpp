/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "SolarSprite.hpp"

namespace Arcade::Games {

    class Player {
        public:
            Player();
            ~Player();

            Vector2i getPosition(void) const { return _position; }
            void setPosition(Vector2i newPosition);

            SolarSprite *getSprite(void) const { return _sprite; }

            u_int16_t getLives(void) const { return _lives; }
            void loseOneLife(void) { _lives = _lives <= 0 ? 0 : _lives - 1; }
            void setLives(u_int16_t newLives) { _lives = newLives; }

            u_int16_t getVelocity(void) const { return _velocity; }
            void setVelocity(u_int16_t newVelocity);

            Vector2i getDirection(void) const { return _direction; }
            void setDirection(Vector2i newDirection) { _direction = newDirection; }

            void move() { _position = _position + _direction; }

        private:
            Vector2i _position = Vector2i(5, 5);
            Vector2i _direction = Vector2i(0, 0);
            SolarSprite *_sprite = new SolarSprite();
            u_int16_t _lives = 3;
            u_int16_t _velocity = 1;
    };

};

#endif /* !PLAYER_HPP_ */
