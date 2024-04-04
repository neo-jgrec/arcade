/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <iostream>
#include <vector>
#include <map>
#include "ISprite.hpp"
#include <map>

namespace Arcade::Games {

    /**
     * VER: -1 = down | 1 = up
     * HOR: -1 = left | 1 = right
    */
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

    class IText {
        public:
            virtual ~IText() = default;

            virtual void setText(std::string text) = 0;
            virtual std::string getText() = 0;

            virtual void setPos(Vector2i pos) = 0;
            virtual Vector2i getPos() = 0;

            virtual void setColor(Color color) = 0;
            virtual Color getColor() = 0;
    };

    class IGameModule {
        public:
            ~IGameModule();

            /**
             * @brief init the game
             * @return void
             */
            virtual void init(std::string args, size_t nb_args) = 0;
            virtual void close(void) = 0;

            /**
             * @brief update the game with inputs
             * @param inputs map of inputs
             * @return void
             */
            virtual bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) = 0;
            /**
             * @brief Get the name of the game
             * @return std::string
             */
            virtual std::string getGameName(void) = 0;

            virtual Vector2i getMapSize(void) = 0;

            /**
            * @brief Get the map of the game
            * @return std::vector<std::string>
            */
            virtual std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) = 0;

            /**
             * @brief Get the score of the game
             * @return std::string
             */
            virtual std::string getScore(void) = 0;

            /**
             * @brief Get the animation time of the game
             * @return float
             */
            virtual float getAnimationTime(void) = 0;

            /**
             * @brief Get the texts of the game
             * @return std::vector<IText *>
             */
            virtual std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void) = 0;

        protected:
        private:
    };
}

#endif /* !IGAME_HPP_ */
