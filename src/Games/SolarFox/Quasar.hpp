/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Quasar
*/

#ifndef QUASAR_HPP_
#define QUASAR_HPP_

    #include "../IGameModule.hpp"

namespace Arcade::Games {

    class Quasar {
        public:
            /**
             * @brief Quasar object
             * @details Quasar are obstacles in the game
             * @return Quasar
            */
            Quasar();
            ~Quasar();

            /**
             * @brief Add a quasar to the game
             * @param position Position of the quasar
             * @return void
            */
            void addQuasar(Vector2i position) { _quasars.push_back(position); }
            /**
             * @brief Remove a quasar from the game
             * @param quasar Position of the quasar
             * @return void
            */
            void removeQuasar(Vector2i quasar);
            /**
             * @brief Clear all the quasars from the game
             * @return void
            */
            void clearQuasars(void) { _quasars.clear(); }
            /**
             * @brief Get all the quasars of the game
             * @return std::vector<Vector2i>
            */
            std::vector<Vector2i> getQuasars(void) const { return _quasars; }
            /**
             * @brief Update the quasar's List
             * @param deltaT Time between each frame
             * @details A quasar will spawn every 10 seconds
             * @return void
            */
            void update(float deltaT);
        private:
            /**
             * @brief List of all the quasars in the game
            */
            std::vector<Vector2i> _quasars;
            /**
             * @brief Time between each spawn of a quasar
            */
            float _spawnTime = 100.0f;
    };

};

#endif /* !QUASAR_HPP_ */
