/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarSprite
*/
#ifndef SOLARSPRITE_HPP_
#define SOLARSPRITE_HPP_

    #include "../ISprite.hpp"

namespace Arcade::Games {

    class SolarSprite : public ISprite {

        public:
            SolarSprite();
            ~SolarSprite();

            void setAscii(std::string ascii);
            std::string getAscii();

            void setPath(std::string path);
            std::string getPath();

            void setRotation(int rotation);
            int getRotation(void);

            void setDirection(Vector2i direction);
            Vector2i getDirection(void);

            void setColor(Color color);
            Color getColor(void);

            void setShape(Shape shape);
        Shape getShape(void);

        private:
            std::string _ascii = "";
            std::string _path = "";
            int _rotation = 0;
            Vector2i _direction = Vector2i(0, 0);
            Color _color = Color::DEFAULT;
            Shape _shape = Shape::RECTANGLE;
    };
};

#endif /* !SPRITE_HPP_ */
