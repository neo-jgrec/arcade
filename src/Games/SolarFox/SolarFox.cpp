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
        SolarSprite *_background = new SolarSprite();
        SolarSprite *_enemy = new SolarSprite();
        SolarSprite *_enemyLaser = new SolarSprite();
        SolarSprite *_playerLaser = new SolarSprite();
        SolarSprite *_wall = new SolarSprite();
        SolarSprite *_fuzor = new SolarSprite();

        _background->setAscii(" ");
        _background->setPath(std::string("gameAssets/solarfox/sprites/background.png"));
        _background->setColor(Color::BLACK);

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
    }

    SolarFox::~SolarFox()
    {
        while (!_textures.empty()) {
            delete(_textures.back());
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
    }

    void SolarFox::close(void)
    {
    }

    void SolarFox::loadRack()
    {
        std::ifstream file("gameAssets/solarfox/maps/rack" + std::to_string(_rackIndex) + ".txt");
        std::string line;
        std::vector<std::string> rack;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                rack.push_back(line);
            }
            file.close();
        } else {
            std::cerr << "Solar Fox: loadRack: Unable to open file" << std::endl;
            exit(84);
        }

        for (std::size_t i = 0; i < rack.size(); i++) {
            std::vector<ISprite *> row;
            for (std::size_t j = 0; j < rack[i].size(); j++) {
                switch (rack[i][j]) {
                    case '#':
                        row.push_back(WALL_TILE);
                        break;
                    case 'P':
                        row.push_back(PLAYER_TILE);
                        break;
                    case '.':
                        row.push_back(BACKGROUND_TILE);
                        break;
                    case 'E':
                        row.push_back(ENEMY_TILE);
                        break;
                    case 'F':
                        row.push_back(FUZOR_TILE);
                        break;
                    default:
                        break;
                }
            }
            _map.push_back(row);
        }
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

    void SolarFox::updateMap()
    {
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

    std::vector<std::vector<std::pair<Arcade::Games::KeyType, int>, std::function<void>>> _functs = {
        {
            {(KeyType::RESTART, 1), restart},
            {(KeyType::VER, UP), moveUP},
            {(KeyType::VER, DOWN), moveDown},
            {(KeyType::HOR, RIGHT), moveRight},
            {(KeyType::HOR, LEFT), moveLeft}
        }
    };

    bool SolarFox::update(std::map<KeyType, int> inputs, float deltaT)
    {
        KeyType vertical = KeyType::VER;
        KeyType horizontal = KeyType::HOR;
        std::vector<Vector2i> fuzors = _fuzors.getFuzors();
        SolarSprite *playerSprite = _player.getSprite();
        Vector2i direction = _player.getDirection();

        for (std::vector<std::pair<Arcade::Games::KeyType, int>, std::function<void>> &funct : _functs) {
            for (std::pair<KeyType, int> &key : funct) {
                if (inputs.at(key.first) == key.second) {
                    funct.back();
                }
            }
        }

        if (inputs.at(KeyType::ACTION2) && _player.getVelocity() == 1) {
            _player.setVelocity(2);
        } else if (!inputs.at(KeyType::ACTION2) && _player.getVelocity() == 2) {
            _player.setVelocity(1);
        }

        if (deltaT > 5) {
            updatePlayer(_map[_player.getPosition().y + _player.getDirection().y][_player.getPosition().x + _player.getDirection().x]);
            updateMap();
        }
        return true;
    }

    float SolarFox::getAnimationTime(void)
    {
        return _animationTime;
    }

    std::vector<IText *> SolarFox::getTexts(void)
    {
        _texts.clear();
        IText *score = new SolarText(std::to_string(_score), Vector2i(0, 0), Color::WHITE);
        IText *lives = new SolarText(std::to_string(_player.getLives()), Vector2i(0, 1), Color::WHITE);
        IText *rack = new SolarText(std::string("Rack n°") + std::to_string(_rackIndex), Vector2i(0, 2), Color::WHITE);
        _texts.push_back(score);
        return _texts;
    }
}
