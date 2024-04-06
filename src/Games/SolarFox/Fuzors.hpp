/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Fuzors
*/

#ifndef FUZORS_HPP_
#define FUZORS_HPP_

    #include "../IGameModule.hpp"

namespace Arcade::Games {

    class Fuzors {
        public:
            /**
             * @brief Fuzors object
             * @details Fuzors are the collectable items in the game
             * @return Fuzors
            */
            Fuzors();
            ~Fuzors();

            /**
             * @brief Add a fuzor to the game
             * @param position Position of the fuzor
             * @return void
            */
            void addFuzor(Vector2i position) { _fuzors.push_back(position); }
            /**
             * @brief Remove a fuzor from the game
             * @param fuzor Position of the fuzor
             * @return void
            */
            void removeFuzor(Vector2i fuzor);
            /**
             * @brief Clear all the fuzors from the game
             * @return void
            */
            void clearFuzors(void) { _fuzors.clear(); }
            /**
             * @brief Get all the fuzors of the game
             * @return std::vector<Vector2i>
            */
            std::vector<Vector2i> getFuzors(void) const { return _fuzors; }
            /**
             * @brief Update the fuzor's List
             * @param deltaT Time between each frame
             * @details A fuzor will spawn every 10 seconds
             * @return void
            */
            void update(float deltaT);
        private:
            /**
             * @brief List of all the fuzors in the game
            */
            std::vector<Vector2i> _fuzors;
            /**
             * @brief Time between each spawn of a fuzor
            */
            float _spawnTime = 10.0f;
    };

};

#endif /* !FUZORS_HPP_ */
