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
            /**
             * @brief Entity object
             * @details Entity is the base class for all the objects in the game
             * @return Entity
            */
            Entity();
            ~Entity();

            /**
             * @brief Get the position of the entity
             * @return Vector2i
            */
            Vector2i getPosition(void) const { return _position; }
            /**
             * @brief Set the position of the entity
             * @param newPosition New position of the entity
             * @return void
            */
            void setPosition(Vector2i newPosition);

            /**
             * @brief Get the sprite of the entity
             * @return ISprite
            */
            ISprite *getSprite(void) const { return _sprite; }
            /**
             * @brief Set the sprite of the entity
             * @param newSprite New sprite of the entity
             * @return void
            */
            void setSprite(ISprite *newSprite) { _sprite = newSprite; }

            /**
             * @brief Get the direction of the entity
             * @return Vector2i
            */
            Vector2i getDirection(void) const { return _direction; }
            /**
             * @brief Set the direction of the entity
             * @param newDirection New direction of the entity
             * @return void
            */
            void setDirection(Vector2i newDirection) { _direction = newDirection; }

            /**
             * @brief Make the entity move
             * @details Move the entity by adding the direction to the position
             * @return void
            */
            void move() { _position = _position + _direction; }

        protected:
            Vector2i _position = Vector2i(5, 5);
            Vector2i _direction = Vector2i(0, 0);
            ISprite *_sprite;
    };

};

#endif /* !ENTITY_HPP_ */
