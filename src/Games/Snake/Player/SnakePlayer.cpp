/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakePlayer
*/

#include "SnakePlayer.hpp"
#include <functional>
#include <tuple>
#include <vector>

using namespace Arcade::Games;

SnakePlayer::SnakePlayer()
{
}

SnakePlayer::~SnakePlayer()
{
}

void SnakePlayer::updateBodyPositions() {
    for (int i = _posBody.size() - 1; i > 0; --i) {
        _posBody[i] = _posBody[i - 1];
    }
    _posBody[0] = _posHead;
}

void SnakePlayer::goUp(void)
{
    _direction = UP;
    _rotation = ROTATION_UP;

    Vector2i prevHeadPos = _posHead;
    _posHead = Vector2i(_posHead.x, _posHead.y - 1);
    updateBodyPositions();
    _posBody[0] = prevHeadPos;
}

void SnakePlayer::goDown(void)
{
    _direction = DOWN;
    _rotation = ROTATION_DOWN;

    Vector2i prevHeadPos = _posHead;
    _posHead = Vector2i(_posHead.x, _posHead.y + 1);
    updateBodyPositions();
    _posBody[0] = prevHeadPos;
}

void SnakePlayer::goLeft(void)
{
    _direction = LEFT;
    _rotation = ROTATION_LEFT;

    Vector2i prevHeadPos = _posHead;
    _posHead = Vector2i(_posHead.x - 1, _posHead.y);
    updateBodyPositions();
    _posBody[0] = prevHeadPos;
}

void SnakePlayer::goRight(void)
{
    _direction = RIGHT;
    _rotation = ROTATION_RIGHT;

    Vector2i prevHeadPos = _posHead;
    _posHead = Vector2i(_posHead.x + 1, _posHead.y);
    updateBodyPositions();
    _posBody[0] = prevHeadPos;
}

void SnakePlayer::update(float deltaT)
{
    if (_moveCooldown > 0) {
        _moveCooldown -= deltaT;
    } else {
        if (_hasBoost) {
            _moveCooldown = _speed - (static_cast<double>(_length) / 10) * 5;
            _hasBoost = -true;
        } else {
            _moveCooldown = _speed;
        }

        if (_rotation == ROTATION_UP) {
            goUp();
        } else if (_rotation == ROTATION_DOWN) {
            goDown();
        } else if (_rotation == ROTATION_LEFT) {
            goLeft();
        } else if (_rotation == ROTATION_RIGHT) {
            goRight();
        }
    }
}

void SnakePlayer::translatePlayerPositionToPositionInCircularMap(std::vector<std::vector<Arcade::Games::ISprite *>> &_map)
{
    int mapWidth = _map.size();
    int mapHeight = _map[0].size();

    _posHead.x = (_posHead.x + mapWidth) % mapWidth;
    _posHead.y = (_posHead.y + mapHeight) % mapHeight;

    for (Vector2i& pos : _posBody) {
        pos.x = (pos.x + mapWidth) % mapWidth;
        pos.y = (pos.y + mapHeight) % mapHeight;
    }
}

void SnakePlayer::processUserMovementInput(std::map<Arcade::Games::KeyType, int> inputs)
{
    std::map<KeyType, std::function<void(void)>> keyToFunctionMap = {
        {KeyType::HOR, [this, &inputs]() {
            if (inputs[KeyType::HOR] == 1) {
                if (_rotation == ROTATION_UP) {
                    _direction = RIGHT;
                    _rotation = ROTATION_RIGHT;
                } else if (_rotation == ROTATION_DOWN) {
                    _direction = LEFT;
                    _rotation = ROTATION_LEFT;
                } else if (_rotation == ROTATION_RIGHT) {
                    _direction = DOWN;
                    _rotation = ROTATION_DOWN;
                } else if (_rotation == ROTATION_LEFT) {
                    _direction = UP;
                    _rotation = ROTATION_UP;
                }
            } else if (inputs[KeyType::HOR] == -1) {
                if (_rotation == ROTATION_UP) {
                    _direction = LEFT;
                    _rotation = ROTATION_LEFT;
                } else if (_rotation == ROTATION_DOWN) {
                    _direction = RIGHT;
                    _rotation = ROTATION_RIGHT;
                } else if (_rotation == ROTATION_RIGHT) {
                    _direction = UP;
                    _rotation = ROTATION_UP;
                } else if (_rotation == ROTATION_LEFT) {
                    _direction = DOWN;
                    _rotation = ROTATION_DOWN;
                }
            }
        }},
        {KeyType::ACTION1, [this, &inputs]() {
            if (inputs[KeyType::ACTION1] == 1) {
                _hasBoost = true;
            } else if (inputs[KeyType::ACTION1] == 0 && _hasBoost == -true) {
                _hasBoost = false;
            }
        }}
    };

    for (const auto& [key, function] : keyToFunctionMap) {
        if (inputs.count(key) > 0) {
            function();
        }
    }
}

void SnakePlayer::addBody(void)
{
    if (_posBody.size() == 0) {
        _posBody.push_back(_posHead);
    } else {
        _posBody.push_back(_posBody[_posBody.size() - 1]);
    }

    _length++;
}

void SnakePlayer::handleCollisionWithApple(std::vector<Vector2i> &applesPos, long int &score, std::vector<std::vector<Arcade::Games::ISprite *>> &map, std::vector<std::tuple<Vector2i, int>> &bonusApplesPos)
{
    for (unsigned long i = 0; i < applesPos.size(); ++i) {
        if (_posHead == applesPos[i]) {
            applesPos.erase(applesPos.begin() + i);
            score++;
            addBody();
            applesPos.push_back(Vector2i(std::rand() % map.size(), std::rand() % map[0].size()));
            map[applesPos[applesPos.size() - 1].y][applesPos[applesPos.size() - 1].x] = nullptr;
            break;
        }
    }
    for (unsigned long i = 0; i < bonusApplesPos.size(); ++i) {
        if (_posHead == std::get<0>(bonusApplesPos[i])) {
            bonusApplesPos.erase(bonusApplesPos.begin() + i);
            score++;
            addBody();
            break;
        }
    }
}

void SnakePlayer::handlePlayerOverlapping()
{
    for (unsigned long i = 0; i < _posBody.size(); ++i) {
        if (_posHead == _posBody[i]) {
            _alive = false;
            break;
        }
    }
}
