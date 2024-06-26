/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <map>
#include "DLLoader/DLLoader.hpp"
#include "../Displays/IDisplayModule.hpp"
#include "../Games/IGameModule.hpp"
#include "Sprite.hpp"
#include "Score.hpp"

/**
 * @namespace Arcade::Core
 * @brief Contains classes and functions related to the core functionality of the arcade game.
 */
namespace Arcade::Core
{
    class Core
    {
        public:
            /**
             * @brief Default constructor for the Core class.
             */
            Core();

            /**
             * @brief Destructor for the Core class.
             */
            ~Core();

            /**
             * @brief Starts the core of the arcade game.
             */
            int Start(std::string displayLib);
        private:
            void addLibraries(const std::string &path);
            void displayLibraries(void);
            void Loop(void);

            std::map<std::string, Arcade::Displays::IDisplayModule *> _displays;
            std::map<std::string, Arcade::Games::IGameModule *> _games;
            DLLoader<Arcade::Displays::IDisplayModule> _displayLoader;
            DLLoader<Arcade::Games::IGameModule> _gameLoader;
            std::string _currentLib;
            std::string _currentGame;

            void getInputs(void);
            Arcade::Displays::ISprite *getSprite(Arcade::Games::ISprite &sprite);
            void setTexts(void);
            void setTiles(void);
            void handleName(void);

            void displayMenu(void);
            void displayScores(void);
            std::string removeUnderScore(std::string name);
            void displayOptions(std::string name, Arcade::Displays::Vector2i pos, bool selected, bool hover);
            char switchChar(char c, bool up);

            std::map<Arcade::Games::KeyType, int> _inputs;
            float _deltaT;
            bool _inGame;
            int _index;
            int _module;

            std::string _name = "__________";
            bool _inName = false;
            float _time = 0;
            int _indexName = 0;
            bool _flipflop = false;

            Score _score;

            void checkSwitch(void);
    };
}

#endif /* !CORE_HPP_ */
