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
    #include "Player.hpp"
    #include "SolarText.hpp"

    #define NEUTRAL 0

    #define UP -1
    #define DOWN 1
    #define RIGHT 1
    #define LEFT -1

    #define ROTATION_UP 270
    #define ROTATION_DOWN 90
    #define ROTATION_RIGHT 180
    #define ROTATION_LEFT 0

    #define BACKGROUND_TILE _textures[0]
    #define ENEMY_TILE _textures[1]
    #define ENEMY_LASER_TILE _textures[2]
    #define PLAYER_lASER_TILE _textures[3]
    #define WALL_TILE _textures[4]
    #define FUZOR_TILE _textures[5]
    #define PLAYER_TILE _player.getSprite()

    #define BACKGROUND 1
    #define ENEMY 2
    #define ENEMY_LASER 3
    #define PLAYER_LASER 4
    #define WALL 5
    #define FUZOR 6
    #define PLAYER 7


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
                Vector2i getMapSize(void) { return _mapSize; }

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
                 * @brief Get the texts of the game
                 * @return std::vector<IText *>
                 */
                std::vector<IText *> getTexts(void);

                /**
                 * @brief load the current map
                 * @return void
                 */
                void loadRack(void);

                /**
                 * @brief update the player
                 * @param tile the tile where the player is headed to
                 * @return void
                 */
                void updatePlayer(ISprite *tile);

                /**
                 * @brief update the map
                 * @return void
                 */
                void updateMap();

                void restart(void);
                void moveUP(void);
                void moveDown(void);
                void moveRight(void);
                void moveLeft(void);



        protected:
        private:
            int _rackIndex = 0;
            float _animationTime = 5;
            bool _pause = false;

            std::vector<Arcade::Games::ISprite *> _textures;
            std::vector<std::vector<std::vector<int>>> _rack;
            std::vector<std::vector<Arcade::Games::ISprite *>> _map;
            std::vector<IText *> _texts;

            Vector2i _mapSize = Vector2i(9, 9);

            Fuzors _fuzors;
            Player _player;

            long int _score = 0;
            std::string _name = std::string("SolarFox");
    };
};

#endif /* !SOLARFOX_HPP_ */
