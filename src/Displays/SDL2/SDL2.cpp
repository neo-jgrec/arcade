/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"

#include <thread> // For std::this_thread::sleep_for
#include <chrono>

static std::map<Arcade::Displays::Color, SDL_Color> colorMap = {
    {Arcade::Displays::Color::DEFAULT, {255, 255, 255, 255}},
    {Arcade::Displays::Color::WHITE, {255, 255, 255, 255}},
    {Arcade::Displays::Color::RED, {255, 0, 0, 255}},
    {Arcade::Displays::Color::YELLOW, {255, 255, 0, 255}},
    {Arcade::Displays::Color::BLUE, {0, 0, 255, 255}},
    {Arcade::Displays::Color::MAGENTA, {255, 0, 255, 255}},
    {Arcade::Displays::Color::CYAN, {0, 255, 255, 255}},
    {Arcade::Displays::Color::GREEN, {0, 255, 0, 255}},
    {Arcade::Displays::Color::BLACK, {0, 0, 0, 255}},
};

SDL2::SDL2() : _mapSize(0, 0)
{
}

SDL2::~SDL2()
{
}

void SDL2::init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("Could not init SDL2");
    if (TTF_Init() != 0)
        throw std::runtime_error("Could not init SDL2 TTF");
    _window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        25 * 32,
        15 * 32,
        SDL_WINDOW_SHOWN
    );
    if (!_window)
        throw std::runtime_error("Could not create window");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        throw std::runtime_error("Could not create renderer");
    _font = TTF_OpenFont("gameAssets/ncurses/monogram.ttf", 24);
    if (!_font)
        throw std::runtime_error("Could not load font");
    _lastTime = clock();

    _texts.push_back(std::make_tuple(Arcade::Displays::Vector2i(0, 0), "Hello, SDL2!", Arcade::Displays::Color::WHITE));
}

void SDL2::close(void)
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_CloseFont(_font);
    TTF_Quit();
    SDL_Quit();
}

std::map<Arcade::Displays::KeyType, int> SDL2::getInputs(void)
{
    std::map<Arcade::Displays::KeyType, int> inputs;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::cout << "Window closed" << std::endl;
            inputs[Arcade::Displays::KeyType::QUIT] = 1;
            return inputs;
        }
    }
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_GetScancodeFromKey(SDLK_UP)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_UP)] == 0)
        inputs[Arcade::Displays::KeyType::VER] -= 1;
    if (state[SDL_GetScancodeFromKey(SDLK_DOWN)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_DOWN)] == 0)
        inputs[Arcade::Displays::KeyType::VER] += 1;
    if (state[SDL_GetScancodeFromKey(SDLK_LEFT)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_LEFT)] == 0)
        inputs[Arcade::Displays::KeyType::HOR] -= 1;
    if (state[SDL_GetScancodeFromKey(SDLK_RIGHT)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_RIGHT)] == 0)
        inputs[Arcade::Displays::KeyType::HOR] += 1;
    if (state[SDL_GetScancodeFromKey(SDLK_ESCAPE)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_ESCAPE)] == 0)
        inputs[Arcade::Displays::KeyType::ESC] = 1;
    if (state[SDL_GetScancodeFromKey(SDLK_a)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_a)] == 0)
        inputs[Arcade::Displays::KeyType::ACTION1] = 1;
    if (state[SDL_GetScancodeFromKey(SDLK_z)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_z)] == 0)
        inputs[Arcade::Displays::KeyType::ACTION2] = 1;
    if (state[SDL_GetScancodeFromKey(SDLK_e)] && _saveInputs[SDL_GetScancodeFromKey(SDLK_e)] == 0)
        inputs[Arcade::Displays::KeyType::ACTION3] = 1;
    _saveInputs = {
        {SDL_GetScancodeFromKey(SDLK_UP), state[SDL_GetScancodeFromKey(SDLK_UP)]},
        {SDL_GetScancodeFromKey(SDLK_DOWN), state[SDL_GetScancodeFromKey(SDLK_DOWN)]},
        {SDL_GetScancodeFromKey(SDLK_LEFT), state[SDL_GetScancodeFromKey(SDLK_LEFT)]},
        {SDL_GetScancodeFromKey(SDLK_RIGHT), state[SDL_GetScancodeFromKey(SDLK_RIGHT)]},
        {SDL_GetScancodeFromKey(SDLK_ESCAPE), state[SDL_GetScancodeFromKey(SDLK_ESCAPE)]},
        {SDL_GetScancodeFromKey(SDLK_a), state[SDL_GetScancodeFromKey(SDLK_a)]},
        {SDL_GetScancodeFromKey(SDLK_z), state[SDL_GetScancodeFromKey(SDLK_z)]},
        {SDL_GetScancodeFromKey(SDLK_e), state[SDL_GetScancodeFromKey(SDLK_e)]},
    };
    return inputs;
}

void SDL2::setMapSize(Arcade::Displays::Vector2i size)
{
    _mapSize = size;
    SDL_SetWindowSize(_window, _mapSize.x * 32, _mapSize.y * 32);
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(_mapSize.y, std::vector<Arcade::Displays::ISprite *>(_mapSize.x, nullptr));
}

void SDL2::updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _map[pos.y][pos.x] = sprite;
}

void SDL2::displayGame(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] != nullptr) {
            SDL_Rect rect = {x * 32, y * 32, 32, 32};

            SDL_Surface* surface = IMG_Load(_map[y][x]->getPath().c_str());
            if (surface) {
                SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
                SDL_RenderCopy(_renderer, texture, NULL, &rect);
                SDL_FreeSurface(surface);
                SDL_DestroyTexture(texture);
            } else {
                auto color = _map[y][x]->getColor();
                if(colorMap.find(color) != colorMap.end()) {
                    SDL_SetRenderDrawColor(_renderer, colorMap[color].r, colorMap[color].g, colorMap[color].b, colorMap[color].a);
                } else {
                    SDL_SetRenderDrawColor(_renderer, colorMap[Arcade::Displays::Color::DEFAULT].r, colorMap[Arcade::Displays::Color::DEFAULT].g, colorMap[Arcade::Displays::Color::DEFAULT].b, colorMap[Arcade::Displays::Color::DEFAULT].a);
                }
                SDL_RenderFillRect(_renderer, &rect);
            }
            }
        }
    }
    for (auto &text : _texts) {
        Arcade::Displays::Vector2i pos = std::get<0>(text);
        std::string str = std::get<1>(text);
        Arcade::Displays::Color color = std::get<2>(text);
        SDL_Color sdlColor = colorMap[color];
        SDL_Surface *surface = TTF_RenderText_Solid(_font, str.c_str(), sdlColor);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
        SDL_Rect rect = {pos.x * 32, pos.y * 32, surface->w, surface->h};
        SDL_RenderCopy(_renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
    SDL_RenderPresent(_renderer);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

}

void SDL2::clear(void)
{
    _texts.clear();
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(_mapSize.y, std::vector<Arcade::Displays::ISprite *>(_mapSize.x, nullptr));
}

void SDL2::setAnimationTime(float time)
{
    (void)time;
}

float SDL2::getDeltaT(void)
{
    clock_t currentTime = clock();
    float deltaTime = static_cast<float>(currentTime - _lastTime) / CLOCKS_PER_SEC;
    _lastTime = currentTime;
    return deltaTime / 4;
}

void SDL2::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _mapSize.x || pos.y >= _mapSize.y)
        return;
    _texts.push_back(std::make_tuple(pos, text, color));
}
