/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <dirent.h>

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
    _currentGame = std::string("./lib/arcade_menu.so");
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
    Arcade::Displays::IDisplayModule *display = _displays[_currentLib];
    Arcade::Games::IGameModule *game = _games[_currentGame];
    std::map<Arcade::Displays::KeyType, int> inputs;
    float deltaT = 0;
    bool running = true;

    std::cout << "Starting game loop..." << std::endl;
    display->init();
    display->setMapSize(Arcade::Displays::Vector2i(15, 15));
    display->updateTile(Arcade::Displays::Vector2i(0, 0), new Sprite());
    game->init("", 0);
    while (running)
    {
        display->clear();
        inputs = display->getInputs();
        if (inputs[Arcade::Displays::KeyType::ESC] == 1)
            running = false;
        display->displayGame();
        // display->draw(game->getMap());
        // display->drawText(game->getTexts());
        // display->display();
        // running = game->update(inputs, deltaT);
    }
    display->close();
    game->close();
}

Arcade::Displays::ISprite &getSprite(Arcade::Games::ISprite &sprite) {
    Sprite newSprite;
    newSprite.setPath(sprite.getPath());
    Arcade::Games::Shape shape = sprite.getShape();
    Arcade::Games::Color color = sprite.getColor();
    Arcade::Games::Vector2i dir = sprite.getDirection();
    switch (color)
    {
    case Arcade::Games::Color::BLACK:
        newSprite.setColor(Arcade::Displays::Color::BLACK);
        break;
    case Arcade::Games::Color::BLUE:
        newSprite.setColor(Arcade::Displays::Color::BLUE);
        break;
    case Arcade::Games::Color::CYAN:
        newSprite.setColor(Arcade::Displays::Color::CYAN);
        break;
    default:
        break;
    }
    switch (shape)
    {
    case Arcade::Games::Shape::CIRCLE:
        newSprite.setShape(Arcade::Displays::Shape::CIRCLE);
        break;
    case Arcade::Games::Shape::RECTANGLE:
        newSprite.setShape(Arcade::Displays::Shape::RECTANGLE);
        break;
    case Arcade::Games::Shape::TRIANGLE:
        newSprite.setShape(Arcade::Displays::Shape::TRIANGLE);
        break;
    }
    newSprite.setRotation(sprite.getRotation());
    newSprite.setDirection(Arcade::Displays::Vector2i(dir.x, dir.y));
    return newSprite;
}