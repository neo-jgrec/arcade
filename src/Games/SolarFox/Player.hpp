/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Entity.hpp"
#include "Macro.hpp"

namespace Arcade::Games {

    class Player : public Entity {
        public:
            Player();
            ~Player();

            void setTurbo(bool newTurbo) { _turbo = newTurbo; }
            bool getTurbo(void) const { return _turbo; }

            void setLives(int newLives) { lives = newLives; }
            int getLives(void) const { return lives; }

            void headUp(void);
            void headDown(void);
            void headLeft(void);
            void headRight(void);

            void update(float elapsedTime);
            void shoot(void);

        protected:
        private:
            float _moveCooldown = 0.0f;
            bool _turbo = false;
            int lives = 3;
    };
};

#endif /* !PLAYER_HPP_ */
