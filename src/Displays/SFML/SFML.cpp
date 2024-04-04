/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#include "SFML.hpp"

static std::map<Arcade::Displays::Color,sf::Color> colorMap = {
    {Arcade::Displays::Color::DEFAULT, sf::Color::White},
    {Arcade::Displays::Color::WHITE, sf::Color::White},
    {Arcade::Displays::Color::RED, sf::Color::Red},
    {Arcade::Displays::Color::YELLOW, sf::Color::Yellow},
    {Arcade::Displays::Color::BLUE, sf::Color::Blue},
    {Arcade::Displays::Color::MAGENTA, sf::Color::Magenta},
    {Arcade::Displays::Color::CYAN, sf::Color::Cyan},
    {Arcade::Displays::Color::GREEN, sf::Color::Green},
    {Arcade::Displays::Color::BLACK, sf::Color::Black},
};

SFML::SFML() : _mapSize(0, 0)
{
    if (!_font.loadFromFile("gameAssets/ncurses/monogram.ttf"))
        throw std::runtime_error("Could not load font");
    _text.setFont(_font);
    _text.setString("Hello, SFML!");
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold);

    _lastTime = clock();
}

SFML::~SFML()
{
}

void SFML::init(void)
{
   _window.create(sf::VideoMode(25 * 32, 15 * 32), "Arcade", sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(60);
}

void SFML::close(void)
{
    _window.close();
}

std::map<Arcade::Displays::KeyType, int> SFML::getInputs(void)
{
    std::map<Arcade::Displays::KeyType, int> inputs;

    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            std::cout << "Window closed" << std::endl;
            inputs[Arcade::Displays::KeyType::QUIT] = 1;
            return inputs;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _saveInputs[sf::Keyboard::Up] == 0)
        inputs[Arcade::Displays::KeyType::VER] -= 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _saveInputs[sf::Keyboard::Down] == 0)
        inputs[Arcade::Displays::KeyType::VER] += 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _saveInputs[sf::Keyboard::Left] == 0)
        inputs[Arcade::Displays::KeyType::HOR] -= 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _saveInputs[sf::Keyboard::Right] == 0)
        inputs[Arcade::Displays::KeyType::HOR] += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && _saveInputs[sf::Keyboard::Escape] == 0)
        inputs[Arcade::Displays::KeyType::ESC] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _saveInputs[sf::Keyboard::A] == 0)
        inputs[Arcade::Displays::KeyType::ACTION1] = 1;
    _saveInputs = {
        {sf::Keyboard::Up, sf::Keyboard::isKeyPressed(sf::Keyboard::Up)},
        {sf::Keyboard::Down, sf::Keyboard::isKeyPressed(sf::Keyboard::Down)},
        {sf::Keyboard::Left, sf::Keyboard::isKeyPressed(sf::Keyboard::Left)},
        {sf::Keyboard::Right, sf::Keyboard::isKeyPressed(sf::Keyboard::Right)},
        {sf::Keyboard::Escape, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)},
        {sf::Keyboard::A, sf::Keyboard::isKeyPressed(sf::Keyboard::A)},
    };
    return inputs;
}

void SFML::setMapSize(Arcade::Displays::Vector2i size)
{
    _mapSize = size;
    _window.create(sf::VideoMode(size.x * 32, size.y * 32), "Arcade", sf::Style::Titlebar | sf::Style::Close);
    _window.setSize(sf::Vector2u(size.x * 32, size.y * 32));
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(_mapSize.y, std::vector<Arcade::Displays::ISprite *>(_mapSize.x, nullptr));
}

void SFML::clear(void)
{
    _texts.clear();
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(_mapSize.y, std::vector<Arcade::Displays::ISprite *>(_mapSize.x, nullptr));

}

void SFML::updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _map[pos.y][pos.x] = sprite;
}

void SFML::displayGame(void)
{
    _window.clear();
    for (auto &text : _texts) {
        _text.setString(std::get<1>(text));
        _text.setPosition(std::get<0>(text).x * 32, std::get<0>(text).y * 32);
        _text.setFillColor(sf::Color::White);
        if (std::get<2>(text) != Arcade::Displays::Color::DEFAULT) {
            _textBackground.setSize(sf::Vector2f(_text.getLocalBounds().width + 3, _text.getLocalBounds().height + 12));
            _textBackground.setPosition(std::get<0>(text).x * 32, std::get<0>(text).y * 32 + 10);
            _textBackground.setFillColor(colorMap[std::get<2>(text)]);
            _text.setFillColor(sf::Color::Black);
            _window.draw(_textBackground);
        }
        _window.draw(_text);
    }
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] != nullptr) {
                _rect.setSize(sf::Vector2f(32, 32));
                _rect.setPosition(x * 32, y * 32);
                _rect.setFillColor(colorMap[_map[y][x]->getColor()]);
                _window.draw(_rect);
            }
        }
    }
    _window.display();
    usleep(10000);
}

void SFML::setAnimationTime(float time)
{
}

float SFML::getDeltaT(void)
{
    clock_t currentTime = clock();
    float deltaTime = static_cast<float>(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
    return deltaTime;
}

void SFML::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _texts.push_back(std::make_tuple(pos, text, color));
}
