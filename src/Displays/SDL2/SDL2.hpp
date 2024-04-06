/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class SDL2 : public Arcade::Displays::IDisplayModule {
    public:
        SDL2();
        ~SDL2();

        void init(void) override;
        void close(void) override;
        std::map<Arcade::Displays::KeyType, int> getInputs(void) override;
        void setMapSize(Arcade::Displays::Vector2i size) override;
        void clear(void) override;
        void updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite) override;
        void displayGame(void) override;
        void setAnimationTime(float time) override;
        float getDeltaT(void) override;
        void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) override;

    protected:
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        Arcade::Displays::Vector2i _mapSize;
        clock_t _lastTime;
        float _deltaT;

        std::vector<std::tuple<Arcade::Displays::Vector2i, std::string, Arcade::Displays::Color>> _texts;
        std::vector<std::vector<Arcade::Displays::ISprite *>> _map;
        std::map<SDL_Keycode, int> _saveInputs;
        std::map<Arcade::Displays::Color, SDL_Color> _colorMap;

        TTF_Font *_font;
        SDL_Texture *_textTexture;

        SDL_Rect _rect;
        SDL_Rect _circle;
        SDL_Rect _triangle;
        SDL_Rect _textBackground;
        SDL_Rect _text;
};

extern "C" {
    Arcade::Displays::IDisplayModule *displayEntryPoint(void) {
        return new SDL2();
    }
}

#endif /* !SDL2_HPP_ */
