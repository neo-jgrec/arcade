/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeSprite
*/

#ifndef SNAKESPRITE_HPP_
#define SNAKESPRITE_HPP_

#include "../ISprite.hpp"

namespace Arcade::Games {
    class SnakeSprite : public ISprite {
        public:
            SnakeSprite();
            ~SnakeSprite();

            void setAscii(std::string ascii) { _ascii = ascii; }
            std::string getAscii() { return _ascii; }

            void setPath(std::string path) { _path = path; }
            std::string getPath() { return _path; }

            void setRotation(int rotation) { _rotation = rotation; }
            int getRotation(void) { return _rotation; }

            void setDirection(Vector2i direction) { _direction = direction; }
            Vector2i getDirection(void) { return _direction; }

            void setColor(Color color) { _color = color; }
            Color getColor(void) { return _color; }

            void setShape(Shape shape) { _shape = shape; }
            Shape getShape(void) { return _shape; }

        private:
            std::string _ascii = "";
            std::string _path = "";
            int _rotation = 0;
            Vector2i _direction = Vector2i(0, 0);
            Color _color = Color::DEFAULT;
            Shape _shape = Shape::RECTANGLE;
    };
}

#endif /* !SNAKESPRITE_HPP_ */
