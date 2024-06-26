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
            bool operator==(const Vector2i &rhs) const { return x == rhs.x && y == rhs.y; }
            Vector2i operator+(const Vector2i &rhs) const { return Vector2i(x + rhs.x, y + rhs.y); }
            Vector2i operator-(const Vector2i &rhs) const { return Vector2i(x - rhs.x, y - rhs.y); }
            Vector2i operator*(const int i) const { return Vector2i(x * i, y * i); }
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
