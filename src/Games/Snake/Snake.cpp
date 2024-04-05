/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Player/SnakePlayer.hpp"
#include "SnakeSprite.hpp"
#include <cstdlib>
#include <iostream>

using namespace Arcade::Games;

Snake::Snake()
{
    SnakeSprite *cyanTile = new SnakeSprite();
    std::cout << "SnakeSprite: " << cyanTile << std::endl;
    cyanTile->setColor(Color::CYAN);
    _textures.push_back(cyanTile);

    SnakeSprite *whiteTile = new SnakeSprite();
    whiteTile->setColor(Color::WHITE);
    _textures.push_back(whiteTile);

    SnakeSprite *head = new SnakeSprite();
    head->setColor(Color::BLUE);
    _textures.push_back(head);

    SnakeSprite *body = new SnakeSprite();
    body->setColor(Color::MAGENTA);
    _textures.push_back(body);

    SnakeSprite *apple = new SnakeSprite();
    apple->setColor(Color::RED);
    _textures.push_back(apple);

    SnakeSprite *bonusApple = new SnakeSprite();
    bonusApple->setColor(Color::YELLOW);
    _textures.push_back(bonusApple);
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

    std::srand(time(nullptr));

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
        std::vector<Arcade::Games::ISprite *> row;
        for (int x = 0; x < _mapSize.x; x++) {
            row.push_back(_textures[1]);
        }
        _map.push_back(row);
    }

    _applesPos.push_back(Vector2i(std::rand() % _mapSize.x, std::rand() % _mapSize.y));
    _map[_applesPos[0].y][_applesPos[0].x] = _textures[4];
    _appleOnMap++;
}

void Snake::close(void)
{
    _map.clear();
    _applesPos.clear();
    _appleOnMap = 0;
    _player.setAlive(false);
    _player.setLength(0);
    _player.setPosHead(Vector2i(0, 0));
    _player.setPosBody({});
    _player.setSpeed(0);
    _player.setDirection(0);
}

void Snake::bonusApples(float deltaT)
{
    for (auto it = _bonusApplesPos.begin(); it != _bonusApplesPos.end();) {
        std::get<1>(*it) -= 1;
        if (std::get<1>(*it) <= 0) {
            _map[std::get<0>(*it).y][std::get<0>(*it).x] = _textures[1];
            it = _bonusApplesPos.erase(it);
            _appleOnMap--;
        } else {
            it++;
        }
    }

    if (_bonusAppleSpawnCooldown > 0) {
        _bonusAppleSpawnCooldown -= deltaT;
        return;
    }
    int x = std::rand() % _mapSize.x;
    int y = std::rand() % _mapSize.y;

    while (_map[y][x] != _textures[1]) {
        x = std::rand() % _mapSize.x;
        y = std::rand() % _mapSize.y;
    }

    _appleOnMap++;
    _bonusApplesPos.push_back(std::make_tuple(Vector2i(x, y), 1000));
    _map[y][x] = _textures[5];

    _bonusAppleSpawnCooldown = _bonusAppleSpawnRate;
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    if (_pause) {
        return true;
    }

    if (_player.getAlive() == false) {
        close();
        init("", 0);
        _player.setAlive(true);
        return true;
    }

    bonusApples(deltaT);

    _player.update(deltaT);

    _player.processUserMovementInput(inputs);
    _player.translatePlayerPositionToPositionInCircularMap(_map);

    _player.handleCollisionWithApple(_applesPos, _score, _map, _bonusApplesPos);
    _player.handlePlayerOverlapping();

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
                _map[y][x] = _textures[2];
            } else {
                bool isBody = false;
                for (auto &pos : _player.getPosBody()) {
                    if (x == pos.x && y == pos.y) {
                        _map[y][x] = _textures[3];
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) {
                    if ((x + y) % 2 == 0) {
                        _map[y][x] = _textures[0];
                    } else {
                        _map[y][x] = _textures[1];
                    }
                    for (auto &applePos : _applesPos) {
                        if (x == applePos.x && y == applePos.y) {
                            _map[y][x] = _textures[4];
                        }
                    }
                    for (auto &bonusApplePos : _bonusApplesPos) {
                        if (x == std::get<0>(bonusApplePos).x && y == std::get<0>(bonusApplePos).y) {
                            _map[y][x] = _textures[5];
                        }
                    }
                }
            }
        }
    }

    return _player.getAlive();
}
