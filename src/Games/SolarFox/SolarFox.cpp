/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

namespace Arcade::Games
{

    SolarFox::SolarFox()
    {
        SolarSprite *_background = new SolarSprite();
        SolarSprite *_enemy = new SolarSprite();
        SolarSprite *_enemyLaser = new SolarSprite();
        SolarSprite *_playerLaserSprite = new SolarSprite();
        SolarSprite *_playerSprite = new SolarSprite();
        SolarSprite *_wall = new SolarSprite();
        SolarSprite *_fuzor = new SolarSprite();

        _background->setAscii(" ");
        _background->setPath(std::string("gameAssets/solarfox/sprites/background.png"));
        _background->setColor(Color::DEFAULT);

        _enemy->setAscii("E");
        _enemy->setPath(std::string("gameAssets/solarfox/sprites/enemy.png"));
        _enemy->setColor(Color::RED);

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

        _textures.push_back(_background);
        _textures.push_back(_enemy);
        _textures.push_back(_enemyLaser);
        _textures.push_back(_wall);
        _textures.push_back(_fuzor);

        _functs.emplace_back(KeyType::RESTART, 1, [this](){ return restart(); });
        _functs.emplace_back(KeyType::VER, UP, [this](){ return _player.headUp(); });
        _functs.emplace_back(KeyType::VER, DOWN, [this](){ return _player.headDown(); });
        _functs.emplace_back(KeyType::HOR, RIGHT, [this](){ return _player.headRight(); });
        _functs.emplace_back(KeyType::HOR, LEFT, [this](){ return _player.headLeft(); });
        _functs.emplace_back(KeyType::ACTION1, 1, [this](){ return _player.setTurbo(true); });
        _functs.emplace_back(KeyType::ACTION1, 0, [this](){ return _player.setTurbo(false); });
        _functs.emplace_back(KeyType::ACTION2, 1, [this](){ return _player.shoot(); });

        loadRack();
    }

    SolarFox::~SolarFox()
    {
        while (!_textures.empty())
        {
            delete (_textures.back());
            _textures.pop_back();
        }
    }

    void SolarFox::init(std::string, size_t nb_args)
    {
        if (nb_args != 0)
        {
            std::cerr << "Solar Fox: init: Wrong number of arguments, expected 0 args" << std::endl;
            exit(84);
        }

        _player.setDirection(Vector2i(1, 0));
    }

    void SolarFox::close(void)
    {
    }

    void SolarFox::loadRack()
    {
        _map.clear();
        _map = std::vector<std::vector<Arcade::Games::ISprite *>>{
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, W, W, W, E, W, W, W, W, W, W, W, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, E, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, E, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, B, B, B, B, B, B, B, B, B, B, W, B, B, B},
            {B, B, B, W, W, W, W, W, E, W, W, W, W, W, W, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
        };
    }

    Vector2i SolarFox::getMapSize(void)
    {
        return _mapSize;
    }

    void SolarFox::updateMap()
    {
        Vector2i pPos = _player.getPosition();

        loadRack();
        _map[pPos.y][pPos.x] = PLAYER_TILE;
        for (auto fuzor : _fuzors.getFuzors())
        {
            _map[fuzor.y][fuzor.x] = FUZOR_TILE;
        }
    }

    void SolarFox::restart(void)
    {
        _player.setPosition(Vector2i(8, 8));
        _player.setDirection(Vector2i(1, 0));
        _player.setLives(3);
        _player.setVelocity(1);
        _score = 0;
        _rackIndex = 1;
        _pause = false;
        loadRack();
    }

    void SolarFox::updateColisions()
    {
        Vector2i pPos = _player.getPosition();

        if (_map[pPos.y][pPos.x] == WALL_TILE || _map[pPos.y][pPos.x] == ENEMY_TILE) {
            _player.setLives(_player.getLives() - 1);
            _player.setPosition(Vector2i(8, 8));
        }
        for (auto fuzor : _fuzors.getFuzors())
        {
            if (fuzor == pPos)
            {
                _score += 100;
                _fuzors.removeFuzor(fuzor);
            }
        }
        return;
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

        _time = deltaT * 1000;

        _player.update(_time);
        _fuzors.update(_time);
        updateColisions();
        return true;
    }

    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> SolarFox::getTexts(void)
    {
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
        std::string score = std::string("score: ") + std::to_string(_score);
        std::string lives = std::string("lives: ") + std::to_string(_player.getLives());
        std::string turbo = std::string("turbo: ") + std::to_string(_player.getTurbo() ? 1 : 0);
        std::string time = std::string("time: ") + std::to_string(_time);

        Vector2i scorePos = Vector2i(4, 0);
        Vector2i livesPos = Vector2i(4, 1);
        Vector2i turboPos = Vector2i(4, 2);
        Vector2i timePos = Vector2i(15, 0);

        texts.push_back(std::make_tuple(score, scorePos, Color::DEFAULT));
        texts.push_back(std::make_tuple(lives, livesPos, Color::DEFAULT));
        texts.push_back(std::make_tuple(turbo, turboPos, Color::DEFAULT));
        texts.push_back(std::make_tuple(time, timePos, Color::DEFAULT));
        return texts;
    }
}
