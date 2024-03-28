/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../IGameModule.hpp"

class Snake {
    public:
        Snake();
        ~Snake();

    protected:
    private:
};

extern "C" {

    Arcade::Games::IGameModule *gameEntryPoint(void) {
        return nullptr;
    }
}

#endif /* !SNAKE_HPP_ */
