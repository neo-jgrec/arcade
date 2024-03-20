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


    class IGameModule {
        public:
            IGameModule();
            ~IGameModule();

            /**
             * @brief init the game
             * @return void
             */
            virtual void init(void) = 0;
            /**
             * @brief update the game with inputs
             * @param inputs map of inputs
             * @return void
             */
            virtual void update(std::map<KeyType, bool> inputs, float deltaT) = 0;
            /**
             * @brief Get the name of the game
             * @return std::string
             */
            void close(void);

            /**
             * @brief Get the height of the map
             * @return void
             */
            virtual void getMapHeight(void) = 0;
            /**
             * @brief Get the width of the map
             * @return void
             */
            virtual void getMapWidth(void) = 0;

            /**
            * @brief Get the map of the game
            * @return std::vector<std::string>
            */
            virtual std::vector<std::vector<Arcade::Displays::ISprite>> getMap(void) = 0;
            /**
             * @brief Get the list of boxes for the game header
             * @return std::vector<Displays::Box>
             */
            virtual std::vector<Displays::Box> getHeader(void) = 0;
            /**
             * @brief Get the score of the game
             * @return unsigned int
             */
            virtual unsigned int getScore(void) = 0;

            /**
             * @brief Get the animation time of the game
             * @return float
             */
            virtual float getAnimationTime(void) = 0;

        protected:
        private:
    };
}

#endif /* !IGAME_HPP_ */
