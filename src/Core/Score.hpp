/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <iostream>
#include <list>
#include <utility>

class GameScores {
    public:
        GameScores(std::string name) : _name(name)
        {
            _scores = std::list<std::pair<std::string, int>>();
        };
        ~GameScores() {};
        void addScore(std::string name, int score) {
            _scores.push_back(std::make_pair(name, score));
        }
        void sortScores() {
            _scores.sort([](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
                return a.second > b.second;
            });
        }
        std::string _name;
        std::list<std::pair<std::string, int>> _scores;
    protected:
    private:
};

class Score {
    public:
        Score() {};
        ~Score() {};
        void addGame(std::string name) {
            _gameScores.push_back(GameScores(name));
        }
        void addScore(std::string gameName, std::string name, int score) {
            for (auto &game : _gameScores) {
                if (game._name == gameName) {
                    std::cout << name << " " << score << std::endl;
                    game.addScore(name, score);
                    // game.sortScores();
                    return;
                }
            }
        }
        std::list<std::pair<std::string, int>> getScores(std::string gameName) {
            for (auto &game : _gameScores) {
                if (game._name == gameName) {
                    game.sortScores();
                    return game._scores;
                }
            }
            return std::list<std::pair<std::string, int>>();
        }
    protected:
    private:
        std::list<GameScores> _gameScores;

};

#endif /* !SCORE_HPP_ */
