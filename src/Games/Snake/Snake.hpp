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

            /**
                 * @brief init the game
                 * @return void
                 */
                void init(std::string args, size_t nb_args);
                void close(void);

                /**
                 * @brief update the game with inputs
                 * @param inputs map of inputs
                 * @return void
                 */
                bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT);

                /**
                 * @brief Get the name of the game
                 * @return std::string
                 */
                std::string getGameName(void) { return _name; }

                /**
                 * @brief Get the size of the map
                 * @return Vector2i
                 */
                Vector2i getMapSize(void) { return _mapSize; }
                /**
                * @brief Get the map of the game
                * @return std::vector<std::string>
                */
                std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) { return _map; }

                /**
                 * @brief Get the score of the game
                 * @return std::string
                 */
                std::string getScore(void) { return std::to_string(_score); }

                /**
                 * @brief Get the animation time of the game
                 * @return float
                 */
                float getAnimationTime(void) { return _animationTime; }

                /**
                 * @brief Get the texts of the game
                 * @return std::vector<IText *>
                 */
                std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);

                void bonusApples(float deltaT);

        protected:
        private:
            int _rackIndex = 0;
            float _animationTime = 5;
            bool _pause = false;

            std::vector<Arcade::Games::ISprite *> _textures;
            std::vector<std::vector<Arcade::Games::ISprite *>> _map;
            std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> _texts;

            Vector2i _mapSize = Vector2i(26, 26);

            SnakePlayer _player;

            long int _score = 0;
            std::string _name = std::string("Snake");

            int _appleOnMap = 0;
            std::vector<Vector2i> _applesPos;

            int _bonusAppleOnMap = 0;
            std::vector<std::tuple<Vector2i, int>> _bonusApplesPos;
            double _bonusAppleSpawnCooldown = 0;
            double _bonusAppleSpawnRate = 10.0f;
    };
}

extern "C" {
    Arcade::Games::IGameModule *gameEntryPoint(void) {
        return new Arcade::Games::Snake();
    }
}

#endif /* !SNAKE_HPP_ */
