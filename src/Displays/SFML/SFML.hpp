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

    protected:
    private:
};

extern "C" {

    Arcade::Displays::IDisplayModule *displayEntryPoint() {
        return new SFML();
    }

}

#endif /* !SFML_HPP_ */
