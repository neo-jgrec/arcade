/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "ISprite.hpp"

namespace Arcade::Displays {

    enum class KeyType {
        VER,
        HOR,
        ACTION1,
        ACTION2,
        ACTION3,
        ACTION4,
        QUIT,
        ESC,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        RESTART
    };

    class IBox {
        public:
            virtual ~IBox() = default;

            virtual std::string getName() const = 0;
            virtual std::string getValue() const = 0;
            virtual ISprite &getSprite() const = 0;
            virtual bool isSelected() const = 0;
            virtual void setSelected(bool selected) = 0;
            virtual void setValue(std::string value) = 0;
            virtual void addSubBox(IBox box) = 0;
            virtual std::vector<IBox> &getSubBoxes() const = 0;
    };

    class IDisplayModule {
        public:
            ~IDisplayModule();

            /**
             * @brief Init the display
             * @return void
             */
            virtual void init(void) = 0;
            /**
             * @brief close, responsible to close the display, free all
             * @return void
             */
            virtual void close(void) = 0;
            /**
             * @brief Get the Inputs object
             * @return std::map<KeyType, int>
             */
            virtual std::map<Arcade::Displays::KeyType, int> getInputs(void) const = 0;
            /**
             * @brief Set the name of the game
             * @param name the name of the game
             * @return void
             */
            virtual void setGameName(std::string name) = 0;

            /**
             * @brief Add a box to the menu or modify it if it already exists
             * @return void
             */
            virtual void setHeader(Arcade::Displays::IBox *box) = 0;

            /**
             * @brief Add a box to the menu or modify it if it already exists
             * @return void
             */
            virtual void setMenu(Arcade::Displays::IBox *box) = 0;

            /**
             * @brief Return a boolean if a box or a subbox is clicked
             * @param name the name of the box
             * @return void
             */
            virtual bool clickedOnBoxElement(std::string name) = 0;

            /**
             * @brief Set the Size of the map
             * @param x horizontal size
             * @param y vertical size
             * @return void
             */
            virtual void setMapSize(Arcade::Displays::Vector2i size) = 0;

            /**
             * @brief Clear the display
             * @return void
             */
            virtual void clear(void) = 0;

            /**
             * @brief Display a tile / update a tile
             * @param x horizontal position
             * @param y vertical position
             * @param sprite
             * @return void
             */
            virtual void updateTile(Arcade::Displays::Vector2i position, Arcade::Displays::ISprite *sprite, int layer = 0) = 0;


            /**
             * @brief Update the display of the game after drawing the map with displayTile
             * @return void
             */
            virtual void displayGame(void) = 0;

            /**
             * @brief Display the menu
             * @return void
             */
            virtual void displayMenu(void) = 0;

            /**
             * @brief Set the time of the animation
             * @return void
             */
            virtual void setAnimationTime(float time) = 0;

            /**
             * @brief Get the delta time
             * @return float
             */
            virtual float getDeltaT(void) = 0;

        protected:
        private:
    };
}


#endif /* !IDISPLAY_HPP_ */
