/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu() : _mapSize(0, 0), _deltaT(0)
{
}

Menu::~Menu()
{
}

void Menu::init(std::string args, size_t nb_args)
{

}

void Menu::close(void)
{
}

bool Menu::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    return false;
}

std::string Menu::getGameName(void)
{
    return "Menu";
}

Arcade::Games::Vector2i Menu::getMapSize(void)
{
    return Arcade::Games::Vector2i(0, 0);
}

std::vector<std::vector<Arcade::Games::ISprite *>> Menu::getMap(void)
{
    return std::vector<std::vector<Arcade::Games::ISprite *>>();
}

std::string Menu::getScore(void)
{
    return "0";
}

float Menu::getAnimationTime(void)
{
    return 0;
}

std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> Menu::getTexts(void)
{
    std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> texts;
    texts.push_back(std::make_tuple("Menu", Arcade::Games::Vector2i(0, 0), Arcade::Games::Color::WHITE));

    return texts;
}


