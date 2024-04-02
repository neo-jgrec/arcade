/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ISprite
*/

#ifndef ISPRITEDISPLAY_HPP_
#define ISPRITEDISPLAY_HPP_

#include <string>

namespace Arcade::Displays {
    class Vector2i {
        public:
            Vector2i(int x, int y) : x(x), y(y) {}
            ~Vector2i() = default;

            int x;
            int y;
    };

    enum class Color {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        DEFAULT
    };

    enum class Shape {
        RECTANGLE,
        CIRCLE,
        TRIANGLE
    };

    class ISprite {
        public:
            virtual ~ISprite() = default;

            /**
             * @brief Set the path of the sprite
             * @param path std::string corresponding to the path of the sprite
             * @return void
             */
            virtual void setPath(std::string path) = 0;
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

            virtual void setColor(Color color) = 0;
            virtual Color getColor(void) = 0;

            virtual void setShape(Shape shape) = 0;
            virtual Shape getShape(void) = 0;

        protected:
        private:
    };
}

#endif /* !ISPRITE_HPP_ */
