/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakePlayer
*/

#include "SnakePlayer.hpp"
#include <functional>
#include <tuple>

using namespace Arcade::Games;

SnakePlayer::SnakePlayer()
{
}

SnakePlayer::~SnakePlayer()
{
}

void SnakePlayer::goUp(void)
{
    _direction = UP;
    _rotation = ROTATION_UP;

    _posHead = Vector2i(_posHead.x, _posHead.y - 1);
    for (size_t i = 0; i < _posBody.size(); i++) {
        _posBody[i] = Vector2i(_posBody[i].x, _posBody[i].y - 1);
    }
}

void SnakePlayer::goDown(void)
{
    _direction = DOWN;
    _rotation = ROTATION_DOWN;

    _posHead = Vector2i(_posHead.x, _posHead.y + 1);
    for (size_t i = 0; i < _posBody.size(); i++) {
        _posBody[i] = Vector2i(_posBody[i].x, _posBody[i].y + 1);
    }
}

void SnakePlayer::goLeft(void)
{
    _direction = LEFT;
    _rotation = ROTATION_LEFT;

    _posHead = Vector2i(_posHead.x - 1, _posHead.y);
    for (size_t i = 0; i < _posBody.size(); i++) {
        _posBody[i] = Vector2i(_posBody[i].x - 1, _posBody[i].y);
    }
}

void SnakePlayer::goRight(void)
{
    _direction = RIGHT;
    _rotation = ROTATION_RIGHT;

    _posHead = Vector2i(_posHead.x + 1, _posHead.y);
    for (size_t i = 0; i < _posBody.size(); i++) {
        _posBody[i] = Vector2i(_posBody[i].x + 1, _posBody[i].y);
    }
}

void SnakePlayer::processUserMovementInput(std::map<Arcade::Games::KeyType, int> inputs)
{
    std::map<KeyType, std::function<void(void)>> keyToFunctionMap = {
        {KeyType::VER, [this, &inputs]() {
            if (inputs[KeyType::VER] == -1) {
                this->goUp();
            } else if (inputs[KeyType::VER] == 1) {
                this->goDown();
            }
        }},
        {KeyType::HOR, [this, &inputs]() {
            if (inputs[KeyType::HOR] == 1) {
                this->goRight();
            } else if (inputs[KeyType::HOR] == -1) {
                this->goLeft();
            }
        }}
    };

    for (const auto& [key, function] : keyToFunctionMap) {
        if (inputs.count(key) > 0) {
            function();
        }
    }
}
