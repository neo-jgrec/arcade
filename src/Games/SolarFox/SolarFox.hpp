/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

    #include "../IGameModule.hpp"
    #include "Fuzors.hpp"
    #include "SolarText.hpp"
    #include "Enemy.hpp"
    #include "Macro.hpp"
    #include "Player.hpp"

    #include <functional>
    #include <tuple>
    #include <vector>

    #define BACKGROUND_TILE _textures[0]
    #define B _textures[0]
    #define ENEMY_TILE _textures[1]
    #define E _textures[1]
    #define ENEMY_LASER_TILE _textures[2]
    #define PLAYER_lASER_TILE _playerLaser.getSprite()
    #define WALL_TILE _textures[3]
    #define I _textures[3]
    #define _ _textures[9]
    #define FUZOR_TILE _textures[4]
    #define CORNER_0_TILE _textures[5]
    #define C0 _textures[5]
    #define CORNER_90_TILE _textures[6]
    #define C9 _textures[6]
    #define CORNER_180_TILE _textures[7]
    #define C18 _textures[7]
    #define CORNER_270_TILE _textures[8]
    #define C27 _textures[8]
    #define PLAYER_TILE _player.getSprite()

    #define BACKGROUND 1
    #define ENEMY 2
    #define ENEMY_LASER 3
    #define WALL 4
    #define FUZOR 5
    #define PLAYER 6

namespace Arcade::Games {

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
                std::string getGameName(void) { return _name; }

                /**
                 * @brief Get the size of the map
                 * @return Vector2i
                 */
                Vector2i getMapSize(void);
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
                 * @brief load the current map
                 * @return void
                 */
                void loadRack(void);

                /**
                 * @brief Get the texts of the game
                 * @return std::vector<IText *>
                 */
                std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);

                /**
                 * @brief update the map
                 * @return void
                 */
                void updateMap();

                /**
                 * @brief update the colisions
                 * @return void
                 */
                void updateColisions(void);

                void restart(void);

        protected:
        private:
            int _rackIndex = 0;
            float _animationTime = 5;
            bool _pause = false;

            std::vector<Arcade::Games::ISprite *> _textures;
            std::vector<std::vector<std::vector<int>>> _rack;
            std::vector<std::vector<Arcade::Games::ISprite *>> _map;
            std::vector<IText *> _texts;

            Vector2i _mapSize = Vector2i(18, 18);

            Fuzors _fuzors;
            Player _player;

            std::vector<Entity> _entities;

            float _time = 0;
            float _laserTime = 0;

            long int _score = 0;
            std::string _name = std::string("SolarFox");

            std::vector<std::tuple<Arcade::Games::KeyType, int, std::function<void()>>> _functs;
    };
}

extern "C" {

    Arcade::Games::IGameModule *gameEntryPoint(void) {
        return new Arcade::Games::SolarFox();
    }
}

#endif /* !SOLARFOX_HPP_ */
