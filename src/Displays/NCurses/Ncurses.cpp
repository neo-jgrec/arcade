/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void Ncurses::init(void)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void Ncurses::close(void)
{
    endwin();
}

std::map<Arcade::Displays::KeyType, int> Ncurses::getInputs(void) const
{
    std::map<Arcade::Displays::KeyType, int> inputs;
    int ch = 0;
    std::vector<int> keys;
    while (ch != ERR) {
        ch = getch();
        keys.push_back(ch);
    }
    if (keys.size() > 1) {
            std::cout << keys[0] << std::endl;
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] == 27) {
                inputs[Arcade::Displays::KeyType::ESC] = 1;
            }
            if (keys[i] == 10) {
                inputs[Arcade::Displays::KeyType::ACTION1] = 1;
            }
        }
    }

                // inputs[Arcade::Displays::KeyType::ESC] = 1;
    return inputs;
}

void Ncurses::setGameName(std::string name)
{
}

void Ncurses::setMapSize(Arcade::Displays::Vector2i size)
{
}

void Ncurses::clear(void)
{
    refresh();
}

void Ncurses::updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite)
{
}

void Ncurses::displayGame(void)
{
}

void Ncurses::setAnimationTime(float time)
{
}

float Ncurses::getDeltaT(void)
{
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
}


