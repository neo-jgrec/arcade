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

class Ncurses : public Arcade::Displays::IDisplayModule {
    public:
        Ncurses();
        ~Ncurses();

        void init(void) override;
        void close(void) override;
        std::map<Arcade::Displays::KeyType, int> getInputs(void) const override;
        void setGameName(std::string name) override;
        void setMapSize(Arcade::Displays::Vector2i size) override;
        void clear(void) override;
        void updateTile(Arcade::Displays::Vector2i pos, Arcade::Displays::ISprite *sprite) override;
        void displayGame(void) override;
        void setAnimationTime(float time) override;
        float getDeltaT(void) override;
        void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) override;

    protected:
    private:
};

extern "C" {

    Arcade::Displays::IDisplayModule *displayEntryPoint(void) {
        return new Ncurses();
    }

}
#endif /* !NCURSES_HPP_ */
