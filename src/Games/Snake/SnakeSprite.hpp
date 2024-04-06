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
            SnakeSprite() {};
            ~SnakeSprite() {};

            void setPath(std::string path) override { _path = path; }
            std::string getPath() override { return _path; }

            void setRotation(int rotation) override { _rotation = rotation; }
            int getRotation(void) override { return _rotation; }

            void setDirection(Vector2i direction) override { _direction = direction; }
            Vector2i getDirection(void) override { return _direction; }

            void setColor(Color color) override { _color = color; }
            Color getColor(void) override { return _color; }

            void setShape(Shape shape) override { _shape = shape; }
            Shape getShape(void) override { return _shape; }

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
