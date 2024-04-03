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

        void init(std::string args, size_t nb_args);
        void close(void);

        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT);

        std::string getGameName(void) { return _name; }

        Vector2i getMapSize(void) { return _mapSize; }

        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) { updateMap(); return _map; }

        std::string getScore(void) { return std::to_string(_score); }

        float getAnimationTime(void) { return _animationTime; }

        std::vector<IText *> getTexts(void);

        void loadRack(void);

        void updatePlayer(ISprite *tile);

        void updateMap();

        protected:
        private:
            int _rackIndex = 0;
            float _animationTime = 5;
            bool _pause = false;

            std::vector<Arcade::Games::ISprite *> _textures;
            std::vector<std::vector<Arcade::Games::ISprite *>> _map;
            std::vector<IText *> _texts;

            Vector2i _mapSize = Vector2i(20, 20);

            SnakePlayer _player;

            long int _score = 0;
            std::string _name = std::string("Snake");
    };
}

extern "C" {

    inline Arcade::Games::IGameModule *gameEntryPoint(void) {
        return nullptr;
    }
}

#endif /* !SNAKE_HPP_ */
