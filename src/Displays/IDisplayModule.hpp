/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_
#include <map>
#include "ISprite.hpp"
#include <iostream>
#include <vector>
#include <memory>

enum class KeyType {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    ESCAPE,
    SPACE,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

namespace Arcade::Displays {
    class Box {
        public:
            Box(std::string name, std::string value, bool selected);
            ~Box();

            std::string name;
            std::string value;
            std::vector<Box> subBoxes;
    };

    class HeaderElement {
        public:
            HeaderElement(std::string name, std::string value, bool selected);
            ~HeaderElement();

            std::string name;
            std::string value;
            std::shared_ptr<ISprite> sprite;
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
            * @brief Get the Inputs object
            * @return std::map<KeyType, bool>
            */
            virtual std::map<KeyType, bool> getInputs(void) const = 0;

            /**
             * @brief Clear the display
             * @return void
             */
            virtual void clear(void) = 0;

            /**
             * @brief Set Header of the display
             * @param name the name of the header, if there is no sprite the name will be displayed
             * @param sprite the icon of the header
             * @param value string that correspond the value of the header
             * @return void
             */
            virtual void setHeader(std::string name, std::string value, ISprite sprite) = 0;

            /**
             * @brief Display the header
             * @return void
             */
            virtual void displayHeader(void) = 0;

            /**
             * @brief Set the Size of the map
             * @param x horizontal size
             * @param y vertical size
             * @return void
             */
            virtual void setMapSize(int x, int y) = 0;

            /**
             * @brief Display a tile
             * @param x horizontal position
             * @param y vertical position
             * @param sprite
             * @return void
             */
            virtual void displayTile(int x, int y, ISprite sprite) = 0;

            /**
             * @brief Add a box to the menu
             * @return void
             */
            virtual void setBox(Box box) = 0;

            /**
             * @brief Display the box
             * @return void
             */
            virtual void displayBox(void) = 0;

            /**
             * @brief Return a boolean if a box or a subbox is clicked
             * @param name the name of the box
             * @return void
             */
            virtual bool clickedOnBoxElement(std::string name) = 0;

            /**
             * @brief Display the menu
             * @return void
             */
            virtual void displayMenu(void) = 0;

            /**
             * @brief close, responsible to close the display, free all
             * @return void
             */
            virtual void close(void) = 0;

        protected:
        private:
    };
}


#endif /* !IDISPLAY_HPP_ */
