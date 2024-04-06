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
            /**
             * @brief Player object
             * @details Player is the class for the player object
             * @return Player
            */
            Player();
            ~Player();

            /**
             * @brief Set the state of the turbo
             * @param newTurbo New state
             * @return void
            */
            void setTurbo(bool newTurbo) { _turbo = newTurbo; }
            /**
             * @brief Get the turbo state
             * @return bool
            */
            bool getTurbo(void) const { return _turbo; }

            /**
             * @brief Set the lives of the player
             * @param newLives New lives of the player
             * @return void
            */
            void setLives(int newLives) { lives = newLives < 0 ? 0 : newLives; }
            /**
             * @brief Get the lives of the player
             * @return int
            */
            int getLives(void) const { return lives; }

            /**
             * @brief set the direction of the player to up
             * @return void
            */
            void headUp(void);
            /**
             * @brief set the direction of the player to down
             * @return void
            */
            void headDown(void);
            /**
             * @brief set the direction of the player to left
             * @return void
            */
            void headLeft(void);
            /**
             * @brief set the direction of the player to right
             * @return void
            */
            void headRight(void);

            /**
             * @brief Update the player
             * @param elapsedTime Time between each frame
             * @details Update the player's position
             * @return void
            */
            void update(float elapsedTime);

        private:
            /**
             * @brief time between each move of the player
             */
            float _moveCooldown = 15.0f;
            /**
             * @brief State of the turbo
             */
            bool _turbo = false;
            /**
             * @brief Lives of the player
             */
            int lives = 3;
    };
};

#endif /* !PLAYER_HPP_ */
