/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../IGameModule.hpp"

class Menu : public Arcade::Games::IGameModule {

    public:
        Menu();
        ~Menu();

        void init(std::string args, size_t nb_args);
        void close(void);

        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT);
        std::string getGameName(void);

        Arcade::Games::Vector2i getMapSize(void);

        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void);

        std::string getScore(void);

        float getAnimationTime(void);

        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);

    protected:
    private:
        std::vector<std::vector<Arcade::Games::ISprite *>> _map;
        std::vector<std::string> _displays;
        std::vector<std::string> _games;
        std::vector<std::string> _name;
        int _selectedGame;
        int _selectedDisplay;
        Arcade::Games::Vector2i _mapSize;
        float _deltaT;
};

extern "C" {

    Arcade::Games::IGameModule *gameEntryPoint(void) {
        return new Menu();
    }
}

#endif /* !Menu_HPP_ */
