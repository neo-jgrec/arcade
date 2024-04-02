/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "../Displays/ISprite.hpp"

class Sprite : public Arcade::Displays::ISprite {
    public:
        Sprite() : _shape(Arcade::Displays::Shape::RECTANGLE), _color(Arcade::Displays::Color::DEFAULT), _rotation(0), _direction(Arcade::Displays::Vector2i(0, 0)), _path("")
        {};
        ~Sprite() {};

        void setPath(std::string path) override { _path = path; };
        std::string getPath() override { return _path; };

        void setShape(Arcade::Displays::Shape shape) override { _shape = shape; };
        Arcade::Displays::Shape getShape() override { return _shape; };

        void setColor(Arcade::Displays::Color color) override { _color = color; };
        Arcade::Displays::Color getColor() override { return _color; };

        void setRotation(int rotation) override { _rotation = rotation; };
        int getRotation() override { return _rotation; };

        void setDirection(Arcade::Displays::Vector2i direction) override { _direction = direction; };
        Arcade::Displays::Vector2i getDirection() override { return _direction; };
    protected:
    private:
        Arcade::Displays::Shape _shape;
        Arcade::Displays::Color _color;
        int _rotation;
        Arcade::Displays::Vector2i _direction;
        std::string _path;
};

#endif /* !SPRITE_HPP_ */
