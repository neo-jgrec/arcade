/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include <string>

namespace Arcade::Displays {
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
             * @brief Set the name of the sprite
             * @param name std::string corresponding to the name of the sprite
             * @return void
             */
            virtual void setName(std::string name) = 0;
            /**
             * @brief Get the name of the sprite
             * @return std::string corresponding to the name of the sprite
             */
            virtual std::string getName(void) = 0;

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

        protected:
        private:
    };
}

#endif /* !ISPRITE_HPP_ */
