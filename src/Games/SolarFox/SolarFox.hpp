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
    #include "Lasers.hpp"
    #include "Quasar.hpp"

    #include <functional>
    #include <tuple>
    #include <vector>

    #define BACKGROUND_TILE _textures[0]
    #define B _textures[0]
    #define ENEMY_LASER_TILE _textures[1]
    #define PLAYER_lASER_TILE _playerLaser.getSprite()
    #define WALL_TILE _textures[2]
    #define W _textures[2]
    #define FUZOR_TILE _textures[3]
    #define PLAYER_TILE _player.getSprite()
    #define QUASAR_TILE _textures[10]

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
                std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) { updateMap(); return _map; }

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
                 * @brief compute all the colisions and do things accordingly
                 * @return void
                 */
                void updateColisions(void);

                /**
                 * @brief restart the game
                 * @return void
                 */
                void restart(void);

                /**
                 * @brief initialize enemies
                 * @return void
                 */
                void initEnemies(void);

                /**
                 * @brief creates a laser comming from an enemy
                 * @return void
                 */
                void createEnemyLaser(Vector2i pos);

                /**
                 * @brief creates a laser comming from the player
                 * @return void
                 */
                void shoot(void);

        protected:
        private:
            float _animationTime = 5;
            bool _pause = false;

            /**
             * @brief list of all Textures of the game
            */
            std::vector<ISprite *> _textures;
            /**
             * @brief map of the game
            */
            std::vector<std::vector<ISprite *>> _map;
            /**
             * @brief list of all Texts of the game
            */
            std::vector<IText *> _texts;

            /**
             * @brief size of the map
            */
            Vector2i _mapSize = Vector2i(18, 18);

            /**
             * @brief Fuzors are the collectable objects in the game
            */
            Fuzors _fuzors;
            Quasar _quasars;
            Player _player;
            Lasers _playerLaser;

            /**
             * @brief list of all enemies
            */
            std::vector<Enemy> _enemies;
            /**
             * @brief list of all enemies lasers
            */
            std::vector<Lasers> _enemiesLasers;

            long int _score = 0;
            std::string _name = std::string("SolarFox");

            std::vector<std::tuple<KeyType, int, std::function<void()>>> _functs;
    };
}

extern "C" {

    Arcade::Games::IGameModule *gameEntryPoint(void) {
        return new Arcade::Games::SolarFox();
    }
}

#endif /* !SOLARFOX_HPP_ */
