/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeText
*/

#ifndef SNAKETEXT_HPP_
#define SNAKETEXT_HPP_

#include "../IGameModule.hpp"

namespace Arcade::Games {
    class SnakeText : public IGameModule {
        public:
            SnakeText() = default;
            ~SnakeText() = default;

            SnakeText(std::string text, Vector2i pos, Color color) : _text(text), _pos(pos), _color(color) { };

            void setText(std::string text) { _text = text; }
            std::string getText() { return _text; };

            void setPos(Vector2i pos) { _pos = pos; }
            Vector2i getPos() { return _pos; };

            void setColor(Color color) { _color = color; }
            Color getColor() { return _color; }

        protected:
        private:
            std::string _text = "";
            Vector2i _pos = Vector2i(0, 0);
            Color _color = Color::DEFAULT;
    };
}

#endif /* !SNAKETEXT_HPP_ */
