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

            void update(float elapsedTime);
            void shoot(float elapsedTime);

        protected:
        private:
            bool _isActive = true;
            float _respawnTime = 30.0f;
            float _reloadTime = 10.0f;
            int _shootProbability = 60;
    };

};

#endif /* !ENEMY_HPP_ */
