/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

namespace Arcade::Games {

    SolarFox::SolarFox()
    {
        SolarSprite *_background = new SolarSprite();
        SolarSprite *_enemy = new SolarSprite();
        SolarSprite *_enemyLaser = new SolarSprite();
        SolarSprite *_playerLaser = new SolarSprite();
        SolarSprite *_wallVer = new SolarSprite();
        SolarSprite *_wallHor = new SolarSprite();
        SolarSprite *_corner_0 = new SolarSprite();
        SolarSprite *_corner_90 = new SolarSprite();
        SolarSprite *_corner_180 = new SolarSprite();
        SolarSprite *_corner_270 = new SolarSprite();
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

        _wallVer->setAscii("W");
        _wallVer->setPath(std::string("gameAssets/solarfox/sprites/wall.png"));
        _wallVer->setColor(Color::WHITE);

        _wallHor->setAscii("W");
        _wallHor->setPath(std::string("gameAssets/solarfox/sprites/wall.png"));
        _wallHor->setColor(Color::WHITE);
        _wallHor->setRotation(90);

        _corner_0->setAscii("W");
        _corner_0->setPath(std::string("gameAssets/solarfox/sprites/corner.png"));
        _corner_0->setColor(Color::WHITE);
        _corner_0->setRotation(0);

        _corner_90->setAscii("W");
        _corner_90->setPath(std::string("gameAssets/solarfox/sprites/corner.png"));
        _corner_90->setColor(Color::WHITE);
        _corner_90->setRotation(90);

        _corner_180->setAscii("W");
        _corner_180->setPath(std::string("gameAssets/solarfox/sprites/corner.png"));
        _corner_180->setColor(Color::WHITE);
        _corner_180->setRotation(180);

        _corner_270->setAscii("W");
        _corner_270->setPath(std::string("gameAssets/solarfox/sprites/corner.png"));
        _corner_270->setColor(Color::WHITE);
        _corner_270->setRotation(270);

        _fuzor->setAscii("F");
        _fuzor->setPath(std::string("gameAssets/solarfox/sprites/fuzor.png"));
        _fuzor->setColor(Color::YELLOW);
        _fuzor->setShape(Shape::CIRCLE);

        _textures.push_back(_background);
        _textures.push_back(_enemy);
        _textures.push_back(_enemyLaser);
        _textures.push_back(_playerLaser);
        _textures.push_back(_wallVer);
        _textures.push_back(_fuzor);
        _textures.push_back(_corner_0);
        _textures.push_back(_corner_90);
        _textures.push_back(_corner_180);
        _textures.push_back(_corner_270);
        _textures.push_back(_wallHor);


        _functs.emplace_back(KeyType::RESTART, 1, [this](){ return restart(); });
        _functs.emplace_back(KeyType::VER, UP, [this](){ return moveUP(); });
        _functs.emplace_back(KeyType::VER, DOWN, [this](){ return moveDown(); });
        _functs.emplace_back(KeyType::HOR, RIGHT, [this](){ return moveRight(); });
        _functs.emplace_back(KeyType::HOR, LEFT, [this](){ return moveLeft(); });

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
            {B, B, B, C0, _, _, _, _, _, _, _, _, _, _, C9, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, I, B, B, B, B, B, B, B, B, B, B, I, B, B, B},
            {B, B, B, C27, _, _, _, _, _, _, _, _, _, _, C18, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
        };
    }


    void SolarFox::updatePlayer()
    {
        Vector2i pDir = _player.getDirection();
        Vector2i pPos = _player.getPosition();
        ISprite *tile = _map[pDir.y + pPos.y][pDir.x + pPos.x];

        if (tile == WALL_TILE ||  tile == _) {
            _player.loseOneLife();
            _player.setPosition(Vector2i(8, 8));
        } else {
            _player.move();
        }
    }

    Vector2i SolarFox::getMapSize(void)
    {
        return _mapSize;
    }

    void SolarFox::updateMap()
    {
        int x = _player.getPosition().x;
        int y = _player.getPosition().y;

        loadRack();
        _map[y][x] = PLAYER_TILE;
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
        _player.setPosition(Vector2i(8, 8));
        _player.setDirection(Vector2i(1, 0));
        _player.setLives(3);
        _player.setVelocity(1);
        _score = 0;
        _rackIndex = 1;
        _pause = false;
        loadRack();
    }

    bool SolarFox::update(std::map<KeyType, int> inputs, float deltaT)
    {
        KeyType vertical = KeyType::VER;
        KeyType horizontal = KeyType::HOR;
        std::vector<Vector2i> fuzors = _fuzors.getFuzors();
        SolarSprite *playerSprite = _player.getSprite();
        Vector2i direction = _player.getDirection();


        for (auto funct : _functs) {
            if (inputs.at(std::get<0>(funct)) == std::get<1>(funct)) {
                std::get<2>(funct)();
            }
        }

        _time += deltaT;

        if (_time > 10) {
            _time = 0;
            std::cout << "deltaT: " << deltaT << std::endl;
            updatePlayer();
        }

        return true;
    }

    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> SolarFox::getTexts(void)
    {
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
        std::string score = std::string("score: ") + std::to_string(_score);
        std::string lives = std::string("lives: ") + std::to_string(_player.getLives());
        Vector2i scorePos = Vector2i(4, 0);
        Vector2i livesPos = Vector2i(4, 1);

        texts.push_back(std::make_tuple(score, scorePos, Color::WHITE));
        texts.push_back(std::make_tuple(lives, livesPos, Color::WHITE));
        return texts;
    }
}
