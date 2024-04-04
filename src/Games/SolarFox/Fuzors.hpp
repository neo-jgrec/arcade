/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Fuzors
*/

#ifndef FUZORS_HPP_
#define FUZORS_HPP_

    #include "../IGameModule.hpp"

namespace Arcade::Games {

    class Fuzors {
        public:
            Fuzors();
            ~Fuzors();

            void addFuzor(Vector2i position) { _fuzors.push_back(position); }
            void removeFuzor(Vector2i fuzor);
            void clearFuzors(void) { _fuzors.clear(); }
            std::vector<Vector2i> getFuzors(void) const { return _fuzors; }

            unsigned short int getValue(void) const { return _value; }
            void setValue(unsigned int newValue);

        private:
            std::vector<Vector2i> _fuzors;
            unsigned short int _value = 30;
    };

};

#endif /* !FUZORS_HPP_ */
