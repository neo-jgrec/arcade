/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "../IGameModule.hpp"
    #include "Player/SnakePlayer.hpp"

namespace Arcade::Games {
    class Snake : public IGameModule {
        public:
            Snake();
            ~Snake();

        void init(std::string args, size_t nb_args) override;
        void close(void) override;

        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;

        std::string getGameName(void) override { return _name; }

        Vector2i getMapSize(void) override { return _mapSize; }

        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) override { return _map; }

        std::string getScore(void) override { return std::to_string(_score); }

        float getAnimationTime(void) override { return _animationTime; }

        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void) override { return _texts; }

        protected:
        private:
            int _rackIndex = 0;
            float _animationTime = 5;
            bool _pause = false;

            std::vector<Arcade::Games::ISprite *> _textures;
            std::vector<std::vector<Arcade::Games::ISprite *>> _map;
            std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> _texts;

            Vector2i _mapSize = Vector2i(21, 21);

            SnakePlayer _player;

            long int _score = 0;
            std::string _name = std::string("Snake");
    };
}

#endif /* !SNAKE_HPP_ */
