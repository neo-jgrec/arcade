/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

static std::map<Arcade::Displays::Color, int> colorMap = {
    {Arcade::Displays::Color::DEFAULT, 1},
    {Arcade::Displays::Color::WHITE, 2},
    {Arcade::Displays::Color::RED, 3},
    {Arcade::Displays::Color::YELLOW, 4},
    {Arcade::Displays::Color::BLUE, 5},
    {Arcade::Displays::Color::MAGENTA, 6},
    {Arcade::Displays::Color::CYAN, 7},
    {Arcade::Displays::Color::GREEN, 8},
    {Arcade::Displays::Color::BLACK, 9},
};

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
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // default
    init_pair(2, COLOR_BLACK, COLOR_WHITE); // white
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_GREEN);
    init_pair(9, COLOR_WHITE, COLOR_BLACK);

    _lastTime = clock();
}

void Ncurses::close(void)
{
    endwin();
}

std::map<Arcade::Displays::KeyType, int> Ncurses::getInputs(void)
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
            if (keys[i] == 27)
                inputs[Arcade::Displays::KeyType::ESC] = 1;
            if (keys[i] == KEY_UP)
                inputs[Arcade::Displays::KeyType::VER] -= 1;
            if (keys[i] == KEY_DOWN)
                inputs[Arcade::Displays::KeyType::VER] += 1;
            if (keys[i] == KEY_LEFT)
                inputs[Arcade::Displays::KeyType::HOR] -= 1;
            if (keys[i] == KEY_RIGHT)
                inputs[Arcade::Displays::KeyType::HOR] += 1;
            // std::cout << keys[i] << std::endl;
            if (keys[i] == 97) {
                inputs[Arcade::Displays::KeyType::ACTION1] = 1;
                std::cout << "ACTION1" << std::endl;
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
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(_mapSize.y, std::vector<Arcade::Displays::ISprite *>(_mapSize.x, nullptr));
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
    ::clear();
    // std::string str = "Ncurses" + std::to_string(_mapSize.x) + " " + std::to_string(_mapSize.y);
    // mvprintw(15, 15, str.c_str());
    if (LINES < _mapSize.y || COLS < _mapSize.x * 3) {
        displayResize();
        _lastTime = clock() - _lastTime;
        refresh();
        return;
    }
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] != nullptr) {
                attron(COLOR_PAIR(colorMap[_map[y][x]->getColor()]));
                mvprintw(y, x, " ");
            }
        }
    }
    attron(COLOR_PAIR(1));
    for (auto text : _texts) {
        Arcade::Displays::Vector2i pos = std::get<0>(text);
        std::string str = std::get<1>(text);
        Arcade::Displays::Color color = std::get<2>(text);
        attron(COLOR_PAIR(colorMap[color]));
        mvprintw(pos.y, pos.x * 3, str.c_str());
    }
    refresh();
    usleep(10000);
}

void Ncurses::setAnimationTime(float time)
{
}

float Ncurses::getDeltaT(void)
{
    clock_t currentTime = clock();
    float deltaTime = static_cast<float>(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
    return deltaTime;
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _texts.push_back(std::make_tuple(pos, text, color));
}
