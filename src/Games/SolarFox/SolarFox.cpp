/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

Arcade::Games::SolarFox::SolarFox()
{
}

Arcade::Games::SolarFox::~SolarFox()
{
}

void Arcade::Games::SolarFox::init(std::string args, size_t nb_args)
{
    if (nb_args != 0)
    {
        std::cerr << "Solar Fox: init: Wrong number of arguments, expected 0 args" << std::endl;
        exit(84);
    }
}

bool Arcade::Games::SolarFox::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    Arcade::Games::KeyType vertical = Arcade::Games::KeyType::VER;
    Arcade::Games::KeyType horizontal = Arcade::Games::KeyType::HOR;

    if (inputs.at(vertical) == -1) {
    }
    if (deltaT > 5) {
        
    }
    return true;
}

std::string Arcade::Games::SolarFox::getScore(void)
{
    return _score;
}
