/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Arcade::Core::Core core;
    return core.Start(std::string(av[1]));
}
