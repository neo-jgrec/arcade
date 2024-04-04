/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ncurses
*/

#ifndef SFML_HPP_
#define SFML_HPP_


#include <SFML/Graphics.hpp>
#include "../IDisplayModule.hpp"
#include <time.h>

class SFML : public Arcade::Displays::IDisplayModule {
    public:
        SFML();
        ~SFML();

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
        sf::RenderWindow _window;
        Arcade::Displays::Vector2i _mapSize;
        clock_t _lastTime;
        float _deltaT;
        std::vector<std::tuple<Arcade::Displays::Vector2i, std::string, Arcade::Displays::Color>> _texts;
        std::vector<std::vector<Arcade::Displays::ISprite *>> _map;
        sf::Font _font;
        sf::Text _text;
        sf::RectangleShape _textBackground;
        std::map<sf::Keyboard::Key, int> _saveInputs;

        sf::RectangleShape _rect;
        sf::CircleShape _circle;
        sf::ConvexShape _triangle;

};

extern "C" {

    Arcade::Displays::IDisplayModule *displayEntryPoint(void) {
        return new SFML();
    }

}
#endif /* !SFML_HPP_ */
