/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Entity.hpp"

namespace Arcade::Games {

    class Enemy : public Entity {
        public:
            Enemy();
            ~Enemy();

            bool update(float elapsedTime);
            bool shoot(float elapsedTime);

            void setBoundaries(Vector2i pointA, Vector2i pointB) {
                _boundaryA = pointA;
                _boundaryB = pointB;
            }

        protected:
        private:
            bool _isActive = true;
            float _respawnTime = 30.0f;
            float _reloadTime = 60.0f;
            float _moveCooldown = 15.0f;
            int _shootProbability = 15;
            Vector2i _boundaryA = Vector2i(0, 0);
            Vector2i _boundaryB = Vector2i(0, 0);
    };
};

#endif /* !ENEMY_HPP_ */
