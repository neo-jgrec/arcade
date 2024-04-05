/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakePlayer
*/

#ifndef SNAKEPLAYER_HPP_
    #define SNAKEPLAYER_HPP_

    #include <map>

    #define ROTATION_UP 270
    #define ROTATION_DOWN 90
    #define ROTATION_RIGHT 180
    #define ROTATION_LEFT 0

    #define UP -1
    #define DOWN 1
    #define RIGHT 1
    #define LEFT -1

    #include "../ISprite.hpp"
    #include "../IGameModule.hpp"

namespace Arcade::Games {
    class SnakePlayer {
        public:
            SnakePlayer();
            ~SnakePlayer();

            void setPosHead(Vector2i pos) { _posHead = pos; }
            Vector2i getPosHead() { return _posHead; }

            void setPosBody(std::vector<Vector2i> pos) { _posBody = pos; }
            std::vector<Vector2i> getPosBody() { return _posBody; }

            void addPosBody(Vector2i pos) { _posBody.push_back(pos); }

            void setDirection(int direction) { _direction = direction; }
            int getDirection() { return _direction; }

            void setRotation(int rotation) { _rotation = rotation; }
            int getRotation() { return _rotation; }

            void setSpeed(double speed) { _speed = speed; }
            double getSpeed() { return _speed; }

            void setAlive(bool alive) { _alive = alive; }
            bool getAlive() { return _alive; }

            void setLength(int length) { _length = length; }
            int getLength() { return _length; }

            void processUserMovementInput(std::map<Arcade::Games::KeyType, int> inputs);
            void updateBodyPositions(void);

        protected:
            void goUp(void);
            void goDown(void);
            void goLeft(void);
            void goRight(void);

        protected:
        private:
            Vector2i _posHead = Vector2i(10, 10);
            std::vector<Vector2i> _posBody = {Vector2i(10, 11), Vector2i(10, 12), Vector2i(10, 13)};
            int _direction = 0;
            int _rotation = 0;
            double _speed = 0.5f;
            bool _alive = true;
            int _length = 4;
    };
}

#endif /* !SNAKEPLAYER_HPP_ */
