/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses() : _mapSize(0, 0)
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
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>();
    _mapSize = Arcade::Displays::Vector2i(0, 0);
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

void Ncurses::setMapSize(Arcade::Displays::Vector2i size)
{
    _mapSize = size;
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(size.y, std::vector<Arcade::Displays::ISprite *>(size.x, nullptr));
}

void Ncurses::clear(void)
{
    refresh();
}

void Ncurses::updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _map[pos.y][pos.x] = sprite;
}

void Ncurses::displayGame(void)
{
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] != nullptr) {
                mvprintw(y, x, "##");
            }
        }
    }
    refresh();
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


