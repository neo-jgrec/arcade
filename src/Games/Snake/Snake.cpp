/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Player/SnakePlayer.hpp"
#include "SnakeSprite.hpp"
#include <iostream>

using namespace Arcade::Games;

Snake::Snake()
{
    SnakeSprite *tile = new SnakeSprite();
    std::cout << "SnakeSprite: " << tile << std::endl;
    tile->setColor(Color::WHITE);
    _textures.push_back(tile);

    SnakeSprite *head = new SnakeSprite();
    head->setColor(Color::YELLOW);
    _textures.push_back(head);

    SnakeSprite *body = new SnakeSprite();
    body->setColor(Color::BLUE);
    _textures.push_back(body);
}

Snake::~Snake()
{
    for (auto &texture : _textures) {
        delete texture;
    }
}

void Snake::init(std::string args, size_t nb_args)
{
    (void)args;
    (void)nb_args;

    _player.setDirection(ROTATION_UP);
    _player.setLength(3);
    _player.setPosHead(Vector2i(_mapSize.x / 2, _mapSize.y / 2));
    std::vector<Vector2i> bodyPositions;
    for (int i = 0; i < _player.getLength(); i++) {
        bodyPositions.push_back(Vector2i(_mapSize.x / 2, _mapSize.y / 2 + i + 1));
    }
    _player.setPosBody(bodyPositions);
    _player.setSpeed(0.1);
    _player.setAlive(true);

    for (int y = 0; y < _mapSize.y; y++) {
        std::vector<ISprite *> line;
        for (int x = 0; x < _mapSize.x; x++) {
            if (x == _player.getPosHead().x && y == _player.getPosHead().y) {
                line.push_back(_textures[1]);
            } else {
                bool isBody = false;
                for (auto &pos : _player.getPosBody()) {
                    if (x == pos.x && y == pos.y) {
                        line.push_back(_textures[2]);
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) {
                    line.push_back(_textures[0]);
                }
            }
        }
        _map.push_back(line);
    }
}

void Snake::close(void)
{
    _map.clear();
    _player.setAlive(false);
    _player.setLength(0);
    _player.setPosHead(Vector2i(0, 0));
    _player.setPosBody({});
    _player.setSpeed(0);
    _player.setDirection(0);
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    if (_pause) {
        return true;
    }

    _player.update(deltaT);

    _player.processUserMovementInput(inputs);
    _player.translatePlayerPositionToPositionInCircularMap(_map);

    if (_player.getPosHead().x < 0 || _player.getPosHead().x >= _mapSize.x ||
        _player.getPosHead().y < 0 || _player.getPosHead().y >= _mapSize.y) {
        _player.setAlive(false);
    }

    for (auto &pos : _player.getPosBody()) {
        if (_player.getPosHead().x == pos.x && _player.getPosHead().y == pos.y) {
            _player.setAlive(false);
            break;
        }
    }

    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (x == _player.getPosHead().x && y == _player.getPosHead().y) {
                _map[y][x] = _textures[1];
            } else {
                bool isBody = false;
                for (auto &pos : _player.getPosBody()) {
                    if (x == pos.x && y == pos.y) {
                        _map[y][x] = _textures[2];
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) {
                    _map[y][x] = _textures[0];
                }
            }
        }
    }

    return _player.getAlive();
}

