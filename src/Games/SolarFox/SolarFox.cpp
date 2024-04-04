/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

#include <functional>
#include <fstream>

namespace Arcade::Games {

    SolarFox::SolarFox()
    {
        //std::cout << "\n--------SolarFox-------\n" << std::endl;
        SolarSprite *_background = new SolarSprite();
        SolarSprite *_enemy = new SolarSprite();
        SolarSprite *_enemyLaser = new SolarSprite();
        SolarSprite *_playerLaser = new SolarSprite();
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

        _playerLaser->setAscii("o");
        _playerLaser->setPath(std::string("gameAssets/solarfox/sprites/playerLaser.png"));
        _playerLaser->setColor(Color::GREEN);
        _playerLaser->setShape(Shape::TRIANGLE);

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
        _textures.push_back(_playerLaser);
        _textures.push_back(_wall);
        _textures.push_back(_fuzor);

        loadRack();
        //std::cout << "\n--------\\SolarFox-------\n" << std::endl;
    }

    SolarFox::~SolarFox()
    {
        while (!_textures.empty()) {
            delete(_textures.back());
            _textures.pop_back();
        }
    }

    void SolarFox::init(std::string oui, size_t nb_args)
    {
        //std::cout << "\n--------\\init-------\n" << std::endl;
        if (nb_args != 0)
        {
            std::cerr << "Solar Fox: init: Wrong number of arguments, expected 0 args" << std::endl;
            exit(84);
        }
        //std::cout << "\n--------\\init-------\n" << std::endl;
    }

    void SolarFox::close(void)
    {
        //std::cout << "\n--------close-------\n" << std::endl;
        //std::cout << "\n--------\\close-------\n" << std::endl;
    }

    void SolarFox::loadRack()
    {
        _map = std::vector<std::vector<Arcade::Games::ISprite *>>{
            {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
            {W, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, W},
            {W, B, W, W, W, W, W, W, W, W, W, W, W, W, W, W, B, W},
            {W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W},
        };
    }


    void SolarFox::updatePlayer(ISprite *tile)
    {
        if (tile == WALL_TILE) {
            _player.setDirection(Vector2i(NEUTRAL, NEUTRAL));
            _player.loseOneLife();
            _player.setPosition(Vector2i(5, 5));
        } else {
            _player.move();
        }
    }

    Vector2i SolarFox::getMapSize(void)
    {
        //std::cout << "\n--------getMapSize-------\n" << std::endl;
        //std::cout << "\n--------\\getMapSize-------\n" << std::endl;
        return _mapSize;
    }

    void SolarFox::updateMap()
    {
        //std::cout << "\n--------updateMap-------\n" << std::endl;
        //std::cout << "\n--------\\updateMap-------\n" << std::endl;
    }

    void SolarFox::moveUP(void)
    {
        if (_player.getDirection().y == DOWN)
            return;
        _player.setDirection(Vector2i(NEUTRAL, UP));
        _player.getSprite()->setRotation(ROTATION_UP);
        _player.getSprite()->setDirection(_player.getDirection());
    }

    void SolarFox::moveDown(void)
    {
        if (_player.getDirection().y == UP)
            return;
        _player.setDirection(Vector2i(NEUTRAL, DOWN));
        _player.getSprite()->setRotation(ROTATION_DOWN);
        _player.getSprite()->setDirection(_player.getDirection());
    }

    void SolarFox::moveRight(void)
    {
        if (_player.getDirection().x == LEFT)
            return;
        _player.setDirection(Vector2i(RIGHT, NEUTRAL));
        _player.getSprite()->setRotation(ROTATION_RIGHT);
        _player.getSprite()->setDirection(_player.getDirection());
    }

    void SolarFox::moveLeft(void)
    {
        if (_player.getDirection().x == RIGHT)
            return;
        _player.setDirection(Vector2i(LEFT, NEUTRAL));
        _player.getSprite()->setRotation(ROTATION_LEFT);
        _player.getSprite()->setDirection(_player.getDirection());
    }

    void SolarFox::restart(void)
    {
        _player.setPosition(Vector2i(5, 5));
        _player.setDirection(Vector2i(1, 0));
        _player.setLives(3);
        _player.setVelocity(1);
        _score = 0;
        _rackIndex = 1;
        _pause = false;
        _map.clear();
        loadRack();
    }

    // std::vector<std::vector<std::pair<Arcade::Games::KeyType, int>, std::function<void>>> _functs = {
    //     {
    //         {(KeyType::RESTART, 1), restart},
    //         {(KeyType::VER, UP), moveUP},
    //         {(KeyType::VER, DOWN), moveDown},
    //         {(KeyType::HOR, RIGHT), moveRight},
    //         {(KeyType::HOR, LEFT), moveLeft}
    //     }
    // };

    bool SolarFox::update(std::map<KeyType, int> inputs, float deltaT)
    {
        //std::cout << "\n\n--------Update-------\n\n" << std::endl;
        // KeyType vertical = KeyType::VER;
        // KeyType horizontal = KeyType::HOR;
        // std::vector<Vector2i> fuzors = _fuzors.getFuzors();
        // SolarSprite *playerSprite = _player.getSprite();
        // Vector2i direction = _player.getDirection();

        // if (inputs.at(KeyType::ACTION2) && _player.getVelocity() == 1) {
        //     _player.setVelocity(2);
        // } else if (!inputs.at(KeyType::ACTION2) && _player.getVelocity() == 2) {
        //     _player.setVelocity(1);
        // }

        // if (deltaT > 5) {
        //     updatePlayer(_map[_player.getPosition().y + _player.getDirection().y][_player.getPosition().x + _player.getDirection().x]);
        //     updateMap();
        // }

        //std::cout << "\n--------\\Update-------\n" << std::endl;
        return true;
    }

    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> SolarFox::getTexts(void)
    {
        //std::cout << "\n\n--------GetTexts-------\n\n" << std::endl;
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
        std::string score = std::to_string(_score);
        std::string lives = std::to_string(_player.getLives());
        Vector2i scorePos = Vector2i(0, 0);
        Vector2i livesPos = Vector2i(0, 1);

        texts.push_back(std::make_tuple(score, scorePos, Color::WHITE));
        texts.push_back(std::make_tuple(lives, livesPos, Color::WHITE));
        //std::cout << "\n\n--------\\GetTexts-------\n\n" << std::endl;
        return texts;
    }
}
