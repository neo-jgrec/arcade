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
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>();
    _mapSize = Arcade::Displays::Vector2i(0, 0);

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_WHITE);
    init_pair(5, COLOR_BLUE, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);

    _lastTime = clock();
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
            if (keys[i] == KEY_UP) {
                inputs[Arcade::Displays::KeyType::VER] -= 1;
            }
            if (keys[i] == KEY_DOWN) {
                inputs[Arcade::Displays::KeyType::VER] += 1;
            }
            if (keys[i] == KEY_LEFT) {
                inputs[Arcade::Displays::KeyType::HOR] -= 1;
            }
            if (keys[i] == KEY_RIGHT) {
                inputs[Arcade::Displays::KeyType::HOR] += 1;
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
    _texts.clear();
}

void Ncurses::updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _map[pos.y][pos.x] = sprite;
}

void Ncurses::displayResize(void)
{
    attron(A_BOLD);
    mvprintw(LINES / 2 - 2, COLS / 2 - 12, "Terminal size too small:");

    mvprintw(LINES / 2 - 1, COLS / 2 - 11, "Width =");
    attron(COLOR_PAIR((COLS < 80) ? 1 : 2));
    mvprintw(LINES / 2 - 1, COLS / 2 - 3, "%s", std::to_string(COLS).c_str());
    attroff(COLOR_PAIR(1));

    mvprintw(LINES / 2 - 1, COLS / 2 , "Height = ");
    attron(COLOR_PAIR((LINES < 24) ? 1 : 2));
    mvprintw(LINES / 2 - 1, COLS / 2 + 9, "%s", std::to_string(LINES).c_str());
    attroff(COLOR_PAIR(2));

    mvprintw(LINES / 2 + 1, COLS / 2 - 13, "%s", "Needed for current config:");
    mvprintw(LINES / 2 + 2, COLS / 2 - 11, "%s", ("Width = " + std::to_string(_mapSize.x * 3) + " Height = " + std::to_string(_mapSize.y)).c_str());
    attroff(A_BOLD);
}

void Ncurses::displayGame(void)
{
    erase();
    if (LINES < _mapSize.y || COLS < _mapSize.x * 3) {
        displayResize();
        _lastTime = clock() - _lastTime;
        refresh();
        return;
    }
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] != nullptr) {
                if (_map[y][x]->getColor() == Arcade::Displays::Color::DEFAULT)
                    attron(COLOR_PAIR(1));
                else if (_map[y][x]->getColor() == Arcade::Displays::Color::YELLOW)
                    attron(COLOR_PAIR(2));
                else if (_map[y][x]->getColor() == Arcade::Displays::Color::BLACK)
                    attron(COLOR_PAIR(3));
                else if (_map[y][x]->getColor() == Arcade::Displays::Color::RED)
                    attron(COLOR_PAIR(4));
                else if (_map[y][x]->getColor() == Arcade::Displays::Color::BLUE)
                    attron(COLOR_PAIR(5));
                else if (_map[y][x]->getColor() == Arcade::Displays::Color::WHITE)
                    attron(COLOR_PAIR(6));
                mvprintw(y, x * 3, "###");
            }
        }
    }
    attron(COLOR_PAIR(1));
    for (auto text : _texts) {
        Arcade::Displays::Vector2i pos = std::get<0>(text);
        std::string str = std::get<1>(text);
        Arcade::Displays::Color color = std::get<2>(text);
        if (color == Arcade::Displays::Color::DEFAULT)
            attron(COLOR_PAIR(1));
        else if (color == Arcade::Displays::Color::YELLOW)
            attron(COLOR_PAIR(2));
        else if (color == Arcade::Displays::Color::BLACK)
            attron(COLOR_PAIR(3));
        else if (color == Arcade::Displays::Color::RED)
            attron(COLOR_PAIR(4));
        else if (color == Arcade::Displays::Color::BLUE)
            attron(COLOR_PAIR(5));
        else if (color == Arcade::Displays::Color::WHITE)
            attron(COLOR_PAIR(6));
        mvprintw(pos.y, pos.x * 3, str.c_str());
    }
    _lastTime = clock() - _lastTime;
    refresh();
}

void Ncurses::setAnimationTime(float time)
{
}

float Ncurses::getDeltaT(void)
{
    return ((float)_lastTime / CLOCKS_PER_SEC);
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _texts.push_back(std::make_tuple(pos, text, color));
}
