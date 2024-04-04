/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "../IDisplayModule.hpp"
#include <time.h>

class Ncurses : public Arcade::Displays::IDisplayModule {
    public:
        Ncurses();
        ~Ncurses();

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

        void displayResize();
    protected:
    private:
        std::vector<std::vector<Arcade::Displays::ISprite *>> _map;
        Arcade::Displays::Vector2i _mapSize;
        float _deltaT;
        clock_t _lastTime;
        std::vector<std::tuple<Arcade::Displays::Vector2i, std::string, Arcade::Displays::Color>> _texts;
};

extern "C" {

    Arcade::Displays::IDisplayModule *displayEntryPoint(void) {
        return new Ncurses();
    }

}
#endif /* !NCURSES_HPP_ */
