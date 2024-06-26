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

            void addBody(void);

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

            void update(float deltaT);

            void translatePlayerPositionToPositionInCircularMap(std::vector<std::vector<Arcade::Games::ISprite *>> &_map);

            void handleCollisionWithApple(std::vector<Vector2i> &applesPos, long int &score, std::vector<std::vector<Arcade::Games::ISprite *>> &map, std::vector<std::tuple<Vector2i, int>> &bonusApplesPos);
            void handlePlayerOverlapping(void);

        protected:
            void goUp(void);
            void goDown(void);
            void goLeft(void);
            void goRight(void);

        protected:
        private:
            Vector2i _posHead = Vector2i(10, 10);
            std::vector<Vector2i> _posBody = {Vector2i(10, 11), Vector2i(10, 12), Vector2i(10, 13)};
            int _direction = UP;
            int _rotation = ROTATION_UP;
            int _hasBoost = false;
            double _speed = 1.75f;
            bool _alive = true;
            int _length = 4;
            double _moveCooldown = 0.0f;
    };
}

#endif /* !SNAKEPLAYER_HPP_ */
