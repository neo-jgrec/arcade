/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Lasers
*/

#ifndef LASERS_HPP_
#define LASERS_HPP_

#include "Entity.hpp"

namespace Arcade::Games {

    class Lasers : public Entity {
        public:
            Lasers() {}
            /**
             * @brief Lasers object
             * @param position Position of the laser
             * @param direction Direction of the laser
             * @param sprite Sprite of the laser
             * @param boundary Boundary of the laser
             * @return Lasers
            */
            Lasers( Vector2i position, Vector2i direction, ISprite *sprite, Vector2i boundary);
            ~Lasers();

            void update(float elapsedTime);
            /**
             * @brief Get the boundary of the laser
             * @return Vector2i
            */
            Vector2i getBoundary(void) { return _boundary; }
            /**
             * @brief Set the boundary of the laser
             * @param newBoundary New boundary of the laser
             * @return void
            */
            void setBoundary(Vector2i newBoundary) { _boundary = newBoundary; }

            /**
             * @brief Get the state of the laser
             * @details Only usefull for the player laser
             * @return bool
            */
            bool getState(void) { return state; }
            /**
             * @brief Set the state of the laser
             * @param newState New state of the laser
             * @details Only usefull for the player laser
             * @return void
            */
            void setState(bool newState) { state = newState; }
            /**
             * @brief set the move cooldown of the laser
             * @return float
            */
            void setMoveCooldown(float newMoveCooldown) { _moveCooldown = newMoveCooldown; }

        protected:
        private:
            /**
             * @brief Cooldown of the laser
             * @details The cooldown is the time between each move of the laser
            */
            float _moveCooldown = 30.0f;
            /**
             * @brief Timer of the laser
             * @details The timer is the time since the last move of the laser
            */
            float _moveTimer = 0.0f;
            /**
             * @brief Boundary of the laser
             * @details The boundary is the position where the laser will be destroyed
            */
            Vector2i _boundary = Vector2i(0, 0);
            /**
             * @brief State of the laser
             * @details The state is true if the laser is active, false otherwise
            */
            bool state = false;
    };
};

#endif /* !LASERS_HPP_ */
