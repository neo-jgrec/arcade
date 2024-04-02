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

            Arcade::Displays::ISprite &getSprite(Arcade::Games::ISprite &sprite);
    };
}

#endif /* !CORE_HPP_ */
