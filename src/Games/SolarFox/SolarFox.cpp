/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

#include <ctime>
#include <random>

namespace Arcade::Games
{

    SolarFox::SolarFox()
    {
        SolarSprite *_background = new SolarSprite();
        SolarSprite *_enemyLaser = new SolarSprite();
        SolarSprite *_playerLaserSprite = new SolarSprite();
        SolarSprite *_playerSprite = new SolarSprite();
        SolarSprite *_wall = new SolarSprite();
        SolarSprite *_fuzor = new SolarSprite();
        SolarSprite *_enemySpriteUp = new SolarSprite();
        SolarSprite *_enemySpriteDown = new SolarSprite();
        SolarSprite *_enemySpriteRight = new SolarSprite();
        SolarSprite *_enemySpriteLeft = new SolarSprite();
        SolarSprite *_quasar = new SolarSprite();

        _background->setAscii(" ");
        _background->setPath(std::string("gameAssets/solarfox/sprites/background.png"));
        _background->setColor(Color::BLACK);

        _enemyLaser->setAscii("o");
        _enemyLaser->setPath(std::string("gameAssets/solarfox/sprites/enemyLaser.png"));
        _enemyLaser->setColor(Color::RED);
        _enemyLaser->setShape(Shape::TRIANGLE);

        _playerSprite->setAscii("P");
        _playerSprite->setPath(std::string("gameAssets/solarfox/sprites/player.png"));
        _playerSprite->setColor(Color::BLUE);
        _playerSprite->setShape(Shape::TRIANGLE);
        _player.setSprite(_playerSprite);

        _playerLaserSprite->setAscii("o");
        _playerLaserSprite->setPath(std::string("gameAssets/solarfox/sprites/playerLaser.png"));
        _playerLaserSprite->setColor(Color::GREEN);
        _playerLaserSprite->setShape(Shape::TRIANGLE);

        _wall->setAscii("W");
        _wall->setPath(std::string("gameAssets/solarfox/sprites/wall.png"));
        _wall->setColor(Color::WHITE);

        _fuzor->setAscii("F");
        _fuzor->setPath(std::string("gameAssets/solarfox/sprites/fuzor.png"));
        _fuzor->setColor(Color::YELLOW);
        _fuzor->setShape(Shape::CIRCLE);

        _enemySpriteUp->setAscii("E");
        _enemySpriteUp->setPath(std::string("gameAssets/solarfox/sprites/enemy.png"));
        _enemySpriteUp->setColor(Color::RED);
        _enemySpriteUp->setShape(Shape::TRIANGLE);
        _enemySpriteUp->setRotation(ROTATION_DOWN);

        _enemySpriteDown->setAscii("E");
        _enemySpriteDown->setPath(std::string("gameAssets/solarfox/sprites/enemy.png"));
        _enemySpriteDown->setColor(Color::RED);
        _enemySpriteDown->setShape(Shape::TRIANGLE);
        _enemySpriteDown->setRotation(ROTATION_UP);

        _enemySpriteRight->setAscii("E");
        _enemySpriteRight->setPath(std::string("gameAssets/solarfox/sprites/enemy.png"));
        _enemySpriteRight->setColor(Color::RED);
        _enemySpriteRight->setShape(Shape::TRIANGLE);
        _enemySpriteRight->setRotation(ROTATION_LEFT);

        _enemySpriteLeft->setAscii("E");
        _enemySpriteLeft->setPath(std::string("gameAssets/solarfox/sprites/enemy.png"));
        _enemySpriteLeft->setColor(Color::RED);
        _enemySpriteLeft->setShape(Shape::TRIANGLE);
        _enemySpriteLeft->setRotation(ROTATION_RIGHT);

        _quasar->setAscii("Q");
        _quasar->setPath(std::string("gameAssets/solarfox/sprites/quasar.png"));
        _quasar->setColor(Color::MAGENTA);
        _quasar->setShape(Shape::CIRCLE);

        _textures.push_back(_background);
        _textures.push_back(_enemyLaser);
        _textures.push_back(_wall);
        _textures.push_back(_fuzor);
        _textures.push_back(_enemySpriteUp);
        _textures.push_back(_enemySpriteDown);
        _textures.push_back(_enemySpriteRight);
        _textures.push_back(_enemySpriteLeft);
        _textures.push_back(_playerLaserSprite);
        _textures.push_back(_playerSprite);
        _textures.push_back(_quasar);

        _functs.emplace_back(KeyType::RESTART, 1, [this](){ return restart(); });
        _functs.emplace_back(KeyType::VER, UP, [this](){ return _player.headUp(); });
        _functs.emplace_back(KeyType::VER, DOWN, [this](){ return _player.headDown(); });
        _functs.emplace_back(KeyType::HOR, RIGHT, [this](){ return _player.headRight(); });
        _functs.emplace_back(KeyType::HOR, LEFT, [this](){ return _player.headLeft(); });
        _functs.emplace_back(KeyType::ACTION1, 1, [this](){ return _player.setTurbo(!_player.getTurbo()); });
        _functs.emplace_back(KeyType::ACTION2, 1, [this](){ return shoot(); });

        loadRack();
        initEnemies();
    }

    SolarFox::~SolarFox()
    {
        while (!_textures.empty())
        {
            delete (_textures.back());
            _textures.pop_back();
        }
    }

    void SolarFox::shoot(void)
    {
        if (_playerLaser.getState() == false)
        {
            _playerLaser.setPosition(_player.getPosition() + _player.getDirection());
            _playerLaser.setDirection(_player.getDirection());
            _playerLaser.setBoundary(_player.getPosition() + _player.getDirection() * 3);
            _playerLaser.setState(true);
        }
    }

    void SolarFox::init(std::string, size_t nb_args)
    {
        std::srand(std::time(nullptr));

        if (nb_args != 0)
        {
            std::cerr << "Solar Fox: init: Wrong number of arguments, expected 0 args" << std::endl;
            exit(84);
        }
        _player.setDirection(Vector2i(1, 0));
        _playerLaser.setSprite(_textures[8]);
        _playerLaser.setMoveCooldown(5.0f);
    }

    void SolarFox::initEnemies(void)
    {
        Enemy _enemy_1;
        Enemy _enemy_2;
        Enemy _enemy_3;
        Enemy _enemy_4;

        _enemy_1.setPosition(Vector2i(5, 3));
        _enemy_1.setDirection(Vector2i(RIGHT, NEUTRAL));
        _enemy_1.setBoundaries(Vector2i(4, 3), Vector2i(13, 3));
        _enemy_1.setSprite(_textures[4]);

        _enemy_2.setPosition(Vector2i(9, 14));
        _enemy_2.setDirection(Vector2i(LEFT, NEUTRAL));
        _enemy_2.setBoundaries(Vector2i(4, 14), Vector2i(13, 14));
        _enemy_2.setSprite(_textures[5]);

        _enemy_3.setPosition(Vector2i(3, 6));
        _enemy_3.setDirection(Vector2i(NEUTRAL, DOWN));
        _enemy_3.setBoundaries(Vector2i(3, 13), Vector2i(3, 4));
        _enemy_3.setSprite(_textures[6]);

        _enemy_4.setPosition(Vector2i(14, 10));
        _enemy_4.setDirection(Vector2i(NEUTRAL, UP));
        _enemy_4.setBoundaries(Vector2i(14, 13), Vector2i(14, 4));
        _enemy_4.setSprite(_textures[7]);

        _enemies.push_back(_enemy_1);
        _enemies.push_back(_enemy_2);
        _enemies.push_back(_enemy_3);
        _enemies.push_back(_enemy_4);
    }

    void SolarFox::close(void)
    {
    }

    void SolarFox::loadRack()
    {
        _map.clear();
        _map = std::vector<std::vector<Arcade::Games::ISprite *>>{
        //   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 0
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 1
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 2
            {B, B, B, W, W, W, W, W, W, W, W, W, W, W, W, B, B, B}, // 3
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 4
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 5
            {B, B, B, W, B, B, W, B, B, B, B, B, B, B, W, B, B, B}, // 6
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 7
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 8
            {B, B, B, W, B, B, B, B, B, B, W, B, B, B, W, B, B, B}, // 9
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 10
            {B, B, B, W, B, W, B, B, B, B, B, B, B, B, W, B, B, B}, // 11
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 12
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B}, // 13
            {B, B, B, W, W, W, W, W, W, W, W, W, W, W, W, B, B, B}, // 14
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 15
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 16
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}, // 1
        };
    }

    Vector2i SolarFox::getMapSize(void)
    {
        return _mapSize;
    }

    void SolarFox::updateMap()
    {
        Vector2i pPos = _player.getPosition();
        Vector2i pLPos = _playerLaser.getPosition();

        loadRack();
        _map[pPos.y][pPos.x] = PLAYER_TILE;
        for (auto fuzor : _fuzors.getFuzors()) {
            _map[fuzor.y][fuzor.x] = FUZOR_TILE;
        }
        for (auto quasar : _quasars.getQuasars()) {
            _map[quasar.y][quasar.x] = QUASAR_TILE;
        }
        for (auto enemy : _enemies) {
            Vector2i ePos = enemy.getPosition();
            _map[ePos.y][ePos.x] = enemy.getSprite();
        }
        for (auto laser : _enemiesLasers) {
            Vector2i lPos = laser.getPosition();
            _map[lPos.y][lPos.x] = ENEMY_LASER_TILE;
        }
        if (_playerLaser.getState()) {
            _map[pLPos.y][pLPos.x] = PLAYER_lASER_TILE;
        }
    }

    void SolarFox::restart(void)
    {
        _player.setPosition(Vector2i(8, 8));
        _player.setDirection(Vector2i(RIGHT, NEUTRAL));
        _player.setLives(3);
        _player.setTurbo(false);
        _score = 0;
        _pause = false;
        _playerLaser.setState(false);
        _fuzors.clearFuzors();
        _quasars.clearQuasars();
        _enemiesLasers.clear();
        loadRack();
    }

    void SolarFox::updateColisions()
    {
        Vector2i pPos = _player.getPosition();
        Vector2i pLPos = _playerLaser.getPosition();

        if (_map[pPos.y][pPos.x] == WALL_TILE) {
            _player.setLives(_player.getLives() - 1);
            _player.setPosition(Vector2i(8, 8));
        }
        for (auto enemy : _enemies) {
            if (enemy.getPosition() == pPos) {
                _player.setLives(_player.getLives() - 1);
                _player.setPosition(Vector2i(8, 8));
            }
        }
        for (auto fuzor : _fuzors.getFuzors()) {
            if (fuzor == pPos) {
                _score += 100;
                _fuzors.removeFuzor(fuzor);
            } else if (fuzor == pLPos) {
                _score += 100;
                _playerLaser.setState(false);
                _fuzors.removeFuzor(fuzor);
            }
        }
        if (_playerLaser.getState()) {
            if (pLPos == _playerLaser.getBoundary())
                _playerLaser.setState(false);
        }
        for (auto quasar : _quasars.getQuasars()) {
            if (quasar == pPos) {
                _player.setLives(_player.getLives() - 1);
                _player.setPosition(Vector2i(8, 8));
                _quasars.removeQuasar(quasar);
            } else if (quasar == pLPos) {
                _playerLaser.setState(false);
                _quasars.removeQuasar(quasar);
            }
        }
        for (size_t i = 0; i < _enemiesLasers.size(); i++) {
            Vector2i elPos = _enemiesLasers[i].getPosition();
            if (elPos == pPos) {
                _player.setLives(_player.getLives() - 1);
                _player.setPosition(Vector2i(8, 8));
                _enemiesLasers.erase(_enemiesLasers.begin() + i);
            } else if  (elPos == _enemiesLasers[i].getBoundary()) {
                _enemiesLasers.erase(_enemiesLasers.begin() + i);
            } else if (elPos == _playerLaser.getPosition()) {
                _playerLaser.setState(false);
                _enemiesLasers.erase(_enemiesLasers.begin() + i);
            }
            if (_playerLaser.getBoundary() == _playerLaser.getPosition()) {
                _playerLaser.setState(false);
            }
        }
        if (_player.getLives() == 0) {
            restart();
        }

        return;
    }

    void SolarFox::createEnemyLaser(Vector2i pos)
    {
        Vector2i direction = Vector2i(0, 0);
        Vector2i boundary = Vector2i(0, 0);

        if (pos.x == 14) {
            direction = Vector2i(LEFT, NEUTRAL);
            boundary = Vector2i(3, pos.y);
        }
        if (pos.x == 3) {
            direction = Vector2i(RIGHT, NEUTRAL);
            boundary = Vector2i(14, pos.y);
        }
        if (pos.y == 14) {
            direction = Vector2i(NEUTRAL, UP);
            boundary = Vector2i(pos.x, 3);
        }
        if (pos.y == 3) {
            direction = Vector2i(NEUTRAL, DOWN);
            boundary = Vector2i(pos.x, 14);
        }

        Lasers laser = Lasers(pos, direction, ENEMY_LASER_TILE, boundary);
        _enemiesLasers.push_back(laser);
    }

    bool SolarFox::update(std::map<KeyType, int> inputs, float deltaT)
    {
        for (auto funct : _functs)
        {
            if (inputs.at(std::get<0>(funct)) == std::get<1>(funct))
            {
                std::get<2>(funct)();
            }
        }

        float time = deltaT * 300;

        _player.update(time);
        _fuzors.update(time);
        _quasars.update(time);
        for (auto &enemy : _enemies) {
            if (enemy.update(time)) {
                createEnemyLaser(enemy.getPosition());
            }
        }
        for (auto &laser : _enemiesLasers) {
            laser.update(time);
        }
        _playerLaser.update(time);
        updateColisions();
        return true;
    }

    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> SolarFox::getTexts(void)
    {
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
        std::string score = std::string("score: ") + std::to_string(_score);
        std::string lives = std::string("lives: ") + std::to_string(_player.getLives());
        std::string turbo = std::string("turbo: ") + std::to_string(_player.getTurbo() ? 1 : 0);

        Vector2i scorePos = Vector2i(4, 0);
        Vector2i livesPos = Vector2i(4, 1);
        Vector2i turboPos = Vector2i(4, 2);

        texts.push_back(std::make_tuple(score, scorePos, Color::DEFAULT));
        texts.push_back(std::make_tuple(lives, livesPos, Color::DEFAULT));
        texts.push_back(std::make_tuple(turbo, turboPos, Color::DEFAULT));
        return texts;
    }
}
