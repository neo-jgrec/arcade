/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarSprite
*/

#include "SolarSprite.hpp"

namespace Arcade::Games {

    SolarSprite::SolarSprite()
    {
    }

    SolarSprite::~SolarSprite()
    {
    }

    void SolarSprite::setAscii(std::string ascii)
    {
        _ascii = ascii;
    }

    std::string SolarSprite::getAscii()
    {
        return _ascii;
    }

    void SolarSprite::setPath(std::string path)
    {
        _path = path;
    }

    std::string SolarSprite::getPath()
    {
        return _path;
    }

    void SolarSprite::setRotation(int rotation)
    {
        _rotation = rotation;
    }

    int SolarSprite::getRotation(void)
    {
        return _rotation;
    }

    void SolarSprite::setDirection(Vector2i direction)
    {
        _direction = direction;
    }

    Vector2i SolarSprite::getDirection(void)
    {
        return _direction;
    }

    void SolarSprite::setColor(Color color)
    {
        _color = color;
    }

    Color SolarSprite::getColor(void)
    {
        return _color;
    }

    void SolarSprite::setShape(Shape shape)
    {
        _shape = shape;
    }

    Shape SolarSprite::getShape(void)
    {
        return _shape;
    }
}
