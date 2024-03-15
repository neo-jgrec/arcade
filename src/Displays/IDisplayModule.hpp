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

    class BoxElement {
        public:
            BoxElement(std::string name, std::string value, bool selected);
            ~BoxElement();

            std::string name;
            std::string value;
            bool selected;
    };

    class Box {
        public:
            Box(std::string name, std::string value, bool selected);
            ~Box();

            std::string value;
            std::vector<BoxElement> elements;
    };

    class HeaderElement {
        public:
            HeaderElement(std::string name, std::string value, bool selected);
            ~HeaderElement();

            std::string name;
            std::string value;
            std::shared_ptr<ISprite> sprite;
    };

    class IDisplay {
        public:
            ~IDisplay();

            /**
            * @brief Get the Inputs object
            * @return std::map<KeyType, bool>
            */
            virtual std::map<KeyType, bool> getInputs() const = 0;

            /**
             * @brief Clear the display
             * @param inputs
             * @return void
             */
            virtual void clear() = 0;

            /**
             * @brief Set Header of the display
             * @param name
             * @param sprite
             * @param value
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
             * @param x
             * @param y
             * @return void
             */
            virtual void setMapSize(int x, int y) = 0;

            /**
             * @brief Display a tile
             * @param x
             * @param y
             * @param sprite
             * @return void
             */
            virtual void displayTile(int x, int y, ISprite sprite) = 0;

            virtual void setBox(Box box) = 0;
            virtual void displayBox(void) = 0;

            virtual bool clickedOnBoxElement(std::string name) = 0;

            /**
             * @brief Display the menu
             * @return void
             */
            virtual void displayMenu(void) = 0;

        protected:
        private:
    };
}


#endif /* !IDISPLAY_HPP_ */
