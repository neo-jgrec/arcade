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
        _moveCooldown = _speed;

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
