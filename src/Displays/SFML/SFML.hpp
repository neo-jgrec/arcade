/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../IDisplayModule.hpp"

class SFML : public Arcade::Displays::IDisplayModule {
    public:
        SFML();
        ~SFML();

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
        return new SFML();
    }

}

#endif /* !SFML_HPP_ */
