/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "ISprite.hpp"

namespace Arcade::Displays {

    enum class KeyType {
        VER,
        HOR,
        ACTION1,
        ACTION2,
        ACTION3,
        ACTION4,
        QUIT,
        ESC,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        RESTART
    };

    class IDisplayModule {
        public:
            ~IDisplayModule();

            /**
             * @brief Init the display
             * @return void
             */
            virtual void init(void) = 0;
            /**
             * @brief close, responsible to close the display, free all
             * @return void
             */
            virtual void close(void) = 0;
            /**
             * @brief Get the Inputs object
             * @return std::map<KeyType, int>
             */
            virtual std::map<Arcade::Displays::KeyType, int> getInputs(void) const = 0;
            /**
             * @brief Set the name of the game
             * @param name the name of the game
             * @return void
             */
            virtual void setGameName(std::string name) = 0;

            /**
             * @brief Set the Size of the map
             * @param x horizontal size
             * @param y vertical size
             * @return void
             */
            virtual void setMapSize(Arcade::Displays::Vector2i size) = 0;

            /**
             * @brief Clear the display
             * @return void
             */
            virtual void clear(void) = 0;

            /**
             * @brief Display a tile / update a tile
             * @param x horizontal position
             * @param y vertical position
             * @param sprite
             * @return void
             */
            virtual void updateTile(Arcade::Displays::Vector2i position, Arcade::Displays::ISprite *sprite) = 0;


            /**
             * @brief Update the display of the game after drawing the map with displayTile
             * @return void
             */
            virtual void displayGame(void) = 0;

            /**
             * @brief Set the time of the animation
             * @return void
             */
            virtual void setAnimationTime(float time) = 0;

            /**
             * @brief Get the delta time
             * @return float
             */
            virtual float getDeltaT(void) = 0;

            virtual void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) = 0;

        protected:
        private:
    };
}


#endif /* !IDISPLAY_HPP_ */
