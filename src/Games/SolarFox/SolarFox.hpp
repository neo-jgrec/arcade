/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

    #include "../IGameModule.hpp"

namespace Arcade::Games {

    class sentinel {
        public:
            sentinel();
            ~sentinel();

            Vector2i getPostion(void);
            void setPosition(Vector2i newPostion);
        private:
            Vector2i _position;
    };

    class SolarFox : public IGameModule {
        public:
            SolarFox();
            ~SolarFox();

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
                std::string getGameName(void);

                Vector2i getMapSize(void);

                /**
                * @brief Get the map of the game
                * @return std::vector<std::string>
                */
                std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void);

                /**
                 * @brief Get the score of the game
                 * @return std::string
                 */
                std::string getScore(void);

                /**
                 * @brief Get the animation time of the game
                 * @return float
                 */
                float getAnimationTime(void);

                /**
                 * @brief Get the texts of the game
                 * @return std::vector<IText *>
                 */
                std::vector<IText *> getTexts(void);


        protected:
        private:
            short unsigned int _rack = 0;
            short unsigned int _lives = 3;
            short unsigned int _cellValue = 30;
            bool _turbo = false;
            Vector2i _playerPosition = Vector2i(5, 5);
            Vector2i _mapSize = Vector2i(9, 9);
            std::string _score = std::string("");
            sentinel enemy_up;
            sentinel enemy_down;
    };
};

#endif /* !SOLARFOX_HPP_ */
