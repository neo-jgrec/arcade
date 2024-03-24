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
    class IBox {
        public:
            IBox(std::string name, std::string value, bool selected);
            ~IBox();

            // std::string name;
            // std::string value;
            // std::vector<Box> subBoxes;
            // std::shared_ptr<ISprite> sprite;
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
             * @return std::map<KeyType, bool>
             */
            virtual std::map<KeyType, bool> getInputs(void) const = 0;

            /**
             * @brief Set the name of the game
             * @param name the name of the game
             * @return void
             */
            virtual void setGameName(std::string name) = 0;

            /**
             * @brief reset the list of boxes
             * @return void
             */
            virtual void resetHeaders(void) = 0;
            /**
             * @brief Add a box to the menu or modify it if it already exists
             * @return void
             */
            virtual void setHeader(IBox box) = 0;

            /**
             * @brief reset the list of boxes
             * @return void
             */
            virtual void resetMenu(void) = 0;
            /**
             * @brief Add a box to the menu or modify it if it already exists
             * @return void
             */
            virtual void setMenu(IBox box) = 0;

            /**
             * @brief Set the Size of the map
             * @param x horizontal size
             * @param y vertical size
             * @return void
             */
            virtual void setMapSize(int x, int y) = 0;

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
            virtual void displayTile(int x, int y, ISprite sprite) = 0;

            /**
             * @brief Return a boolean if a box or a subbox is clicked
             * @param name the name of the box
             * @return void
             */
            virtual bool clickedOnBoxElement(std::string name) = 0;

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
