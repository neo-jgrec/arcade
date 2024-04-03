/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <dirent.h>

#define GAME _games[_currentGame]
#define DISPLAY _displays[_currentLib]
#define DVEC(x, y) Arcade::Displays::Vector2i(x, y)
#define DCOL(color) Arcade::Displays::Color::color
#define DSHA(shape) Arcade::Displays::Shape::shape
#define GKEY(key) Arcade::Games::KeyType::key

using namespace Arcade::Core;

Core::Core()
{
    const size_t path_max = 256;
    char path[path_max] = "./lib/";
    DIR *dir;

    dir = opendir(path);
    if (dir == NULL)
    {
        std::cerr << "Error: cannot open directory" << std::endl;
        exit(84);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type != DT_DIR)
            addLibraries(path + std::string(entry->d_name));
    }
    closedir(dir);
}

Core::~Core()
{
}

int Core::Start(std::string displayLib)
{
    std::cout << "Starting core..." << std::endl;
    std::cout << displayLib << std::endl;
    displayLibraries();
    if (_displays.find(displayLib) == _displays.end())
    {
        std::cerr << "Error: Display library not found" << std::endl;
        return 84;
    }
    _currentLib = displayLib;
    std::cout << "Current display library: " << displayLib << std::endl;
    std::cout << "Current game library: " << _currentGame << std::endl;
    Loop();
    return 0;
}

void Core::addLibraries(const std::string &path)
{
    std::cout << "Adding libraries from path: " << path << std::endl;
    try {
        _displays[path] = _displayLoader.getInstance(path, "displayEntryPoint");
        std::cout << "Display library loaded: " << path << std::endl;
    } catch (const std::exception &e) {}
    try {
        _games[path] = _gameLoader.getInstance(path, "gameEntryPoint");
        std::cout << "Game library loaded: " << path << std::endl;
    } catch (const std::exception &e) {}
}

void Core::displayLibraries(void)
{
    std::cout << "Displays:" << std::endl;
    for (auto &display : _displays)
    {
        std::cout << display.first << std::endl;
    }
    std::cout << std::endl << "Games:" << std::endl;
    for (auto &game : _games)
    {
        std::cout << game.first << std::endl;
    }
    std::cout << std::endl;
}

void Core::Loop(void)
{
    bool running = true;

    std::cout << "Starting game loop..." << std::endl;
    _inGame = true;
    _index = 0;
    _module = 0;
    _currentGame = "./lib/arcade_solarfox.so";
    for (auto &game : _games)
     std::cout << game.first << std::endl;
    GAME->init("", 0);
    DISPLAY->init();
    DISPLAY->setMapSize(DVEC(GAME->getMapSize().x, GAME->getMapSize().y));
    while (running)
    {
        DISPLAY->clear();
        getInputs();
        _deltaT = DISPLAY->getDeltaT();

        if (_inGame) {
            GAME->update(_inputs, _deltaT);
            if (_inputs[Arcade::Games::KeyType::ESC] == 1)
                _inGame = false;
            setTiles();
            setTexts();
            setTiles();
        } else {
            displayMenu();
        }
        DISPLAY->displayGame();
    }
    DISPLAY->close();
    // GAME->close();
}

void Core::setTiles(void)
{
    std::vector<std::vector<Arcade::Games::ISprite *>> map = GAME->getMap();
    for (size_t y = 0; y < map.size(); y++)
    {
        for (size_t x = 0; x < map[y].size(); x++)
        {
            // std::cout << "x: " << x << " y: " << y << std::endl;
            DISPLAY->updateTile(Arcade::Displays::Vector2i(x, y), getSprite(*map[y][x]));
        }
    }

}

Arcade::Displays::Color Core::getColor(Arcade::Games::Color color)
{
    switch (color)
    {
    case Arcade::Games::Color::BLACK:
        return Arcade::Displays::Color::BLACK;
    case Arcade::Games::Color::BLUE:
        return Arcade::Displays::Color::BLUE;
    case Arcade::Games::Color::CYAN:
        return Arcade::Displays::Color::CYAN;
    }
    return Arcade::Displays::Color::DEFAULT;
}

Arcade::Displays::ISprite *Core::getSprite(Arcade::Games::ISprite &sprite) {
    Sprite *newSprite = new Sprite();
    newSprite->setPath(sprite.getPath());
    Arcade::Games::Shape shape = sprite.getShape();
    Arcade::Games::Color color = sprite.getColor();
    Arcade::Games::Vector2i dir = sprite.getDirection();

    switch (shape)
    {
    case Arcade::Games::Shape::CIRCLE:
        newSprite->setShape(Arcade::Displays::Shape::CIRCLE);
        break;
    case Arcade::Games::Shape::RECTANGLE:
        newSprite->setShape(Arcade::Displays::Shape::RECTANGLE);
        break;
    case Arcade::Games::Shape::TRIANGLE:
        newSprite->setShape(Arcade::Displays::Shape::TRIANGLE);
        break;
    }
    newSprite->setRotation(sprite.getRotation());
    newSprite->setDirection(Arcade::Displays::Vector2i(dir.x, dir.y));
    return newSprite;
}

void Core::getInputs(void)
{
    _inputs.clear();
    std::map<Arcade::Displays::KeyType, int> displayInputs = _displays[_currentLib]->getInputs();
    for (auto &input : displayInputs)
    {
        switch (input.first)
        {
        case Arcade::Displays::KeyType::ESC:
            _inputs[Arcade::Games::KeyType::ESC] = input.second;
            break;
        case Arcade::Displays::KeyType::HOR:
            _inputs[Arcade::Games::KeyType::HOR] = input.second;
            break;
        case Arcade::Displays::KeyType::VER:
            _inputs[Arcade::Games::KeyType::VER] = input.second;
            break;
        case Arcade::Displays::KeyType::ACTION1:
            _inputs[Arcade::Games::KeyType::ACTION1] = input.second;
            break;
        default:
            break;
        }
    }
}

void Core::setTiles(void)
{
    std::vector<std::vector<Arcade::Games::ISprite *>> map = GAME->getMap();
    for (size_t y = 0; y < map.size(); y++)
    {
        for (size_t x = 0; x < map[y].size(); x++)
        {
            DISPLAY->updateTile(Arcade::Displays::Vector2i(x, y), &getSprite(*map[y][x]));
        }
    }

}

void Core::setTexts(void)
{
    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
    texts = _games[_currentGame]->getTexts();
    for (auto &text : texts)
    {
        Arcade::Games::Vector2i pos = std::get<1>(text);
        Arcade::Games::Color color = std::get<2>(text);

        _displays[_currentLib]->setText(std::get<0>(text), Arcade::Displays::Vector2i(pos.x, pos.y), getColor(color));
    }
}

Arcade::Displays::Shape Core::getShape(Arcade::Games::Shape shape)
{
    switch (shape)
    {
    case Arcade::Games::Shape::CIRCLE:
        return Arcade::Displays::Shape::CIRCLE;
    case Arcade::Games::Shape::RECTANGLE:
        return Arcade::Displays::Shape::RECTANGLE;
    case Arcade::Games::Shape::TRIANGLE:
        return Arcade::Displays::Shape::TRIANGLE;
    }
    return Arcade::Displays::Shape::RECTANGLE;
}

void Core::displayMenu(void)
{
    int i = 0;

    if (_inputs[Arcade::Games::KeyType::VER] == -1)
        _index -= 1;
    if (_inputs[Arcade::Games::KeyType::VER] == 1)
        _index += 1;
    if (_inputs[Arcade::Games::KeyType::HOR] == -1)
        _module = (_module - 1) % 3;
    if (_inputs[Arcade::Games::KeyType::HOR] == 1)
        _module = (_module + 1) % 3;
    if (_module == -1)
        _module = 2;
    if (_module == 0)
        _index = _index % _games.size();
    if (_module == 1)
        _index = _index % _displays.size();
    if (_inputs[Arcade::Games::KeyType::ACTION1] == 1)
    {
        std::cout << "Enter pressed" << std::endl;
        int j = 0;
        for (auto &display : _displays)
        {
            if (j == _index && _module == 1) {
                std::cout << "Selected display: " << display.first << std::endl;
                DISPLAY->close();
                _currentLib = display.first;
                DISPLAY->init();
            }
            j++;
        }
        // if (_module == 0)
        //     _currentGame = _games.begin()->first;
        // if (_module == 1)
        //     _currentLib = _displays.begin()->first;
        // if (_module == 2)
        //     _inGame = true;
    }

    displayOptions("F1: Games", DVEC(2, 1), _module == 0, false);
    displayOptions("F2: Graphics", DVEC(10, 1), _module == 1, false);
    for (auto &game : _games)
        displayOptions(game.first, DVEC(2, 3 + i++ * 2), game.first == _currentGame, _index == i && _module == 0);
    i = 0;
    for (auto &display : _displays)
        displayOptions(display.first, DVEC(10, 3 + i++ * 2), display.first == _currentLib, _index == i && _module == 1);
    displayOptions("F3: Name", DVEC(2, 11), _module == 2, false);
    displayOptions("", DVEC(2, 13), false, _module == 2);

    _displays[_currentLib]->displayGame();
}

void Core::displayOptions(std::string name, Arcade::Displays::Vector2i pos, bool selected, bool hover)
{
    std::string text = name;

    if (hover)
        text = "> " + text;
    if (selected)
        DISPLAY->setText(text, DVEC(pos.x, pos.y), DCOL(WHITE));
    else
        DISPLAY->setText(text, DVEC(pos.x, pos.y), DCOL(DEFAULT));
}
