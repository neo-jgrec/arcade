/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ISprite
*/

#ifndef ISPRITEGAME_HPP_
#define ISPRITEGAME_HPP_

#include <iostream>

namespace Arcade::Games {
    class Vector2i {
        public:
            Vector2i(int x, int y) : x(x), y(y) {}
            ~Vector2i() = default;

            int x;
            int y;
    };


    class ISprite {
        public:
            ISprite();
            ~ISprite();

            /**
            * @brief Set the ascii of the sprite
            * @param ascii
            * @return void
            * @note ascii is a std::string because it can be multiple characters (if its 4 characters, it will be a 2x2 sprite for example)
            */
            virtual void setAscii(std::string ascii) = 0;
            /**
             * @brief Get the ascii of the sprite
             * @return std::string corresponding to the ascii of the sprite, can be multiple characters
             */
            virtual std::string getAscii() = 0;

            /**
             * @brief Set the path of the sprite
             * @param path std::string corresponding to the path of the sprite
             * @return void
             */
            virtual void setPath(char path) = 0;
            /**
             * @brief Get the path of the sprite
             * @return std::string corresponding to the path of the sprite
             */
            virtual std::string getPath() = 0;

            /**
             * @brief Set the rotation of the sprite
             * @param rotation int corresponding to the rotation of the sprite
             * @return void
             */
            virtual void setRotation(int rotation) = 0;
            /**
             * @brief Get the rotation of the sprite
             * @return int corresponding to the rotation of the sprite
             */
            virtual int getRotation(void) = 0;

            virtual void setDirection(Vector2i direction) = 0;
            virtual Vector2i getDirection(void) = 0;

        protected:
        private:
    };
}

#endif /* !ISPRITE_HPP_ */
