/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <iostream>
#include "../Displays/IDisplayModule.hpp"
#include <vector>

namespace Arcade::Games {


    class IGame {
        public:
            IGame();
            ~IGame();

            /**
            * @brief update the game with inputs
            * @param inputs map of inputs
            * @return void
            */
            virtual void update(std::map<KeyType, bool> inputs) = 0;

            /**
            * @brief Get the map of the game
            * @return std::vector<std::string>
            */
            virtual std::vector<std::vector<Arcade::Displays::ISprite>> getMap(void) = 0;

            /**
            * @brief Get the size of the map
            * @return void
            */
            virtual void getMapSize(void) = 0;

            /**
             * @brief Get the score of the game
             * @return unsigned int
             */
            virtual unsigned int getScore(void) = 0;

            virtual std::vector<Displays::HeaderElement> getHeader(void) = 0;
        protected:
        private:
    };
}

#endif /* !IGAME_HPP_ */
