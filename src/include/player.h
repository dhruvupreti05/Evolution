#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

struct Player {
    sf::RectangleShape shape;
    int x, y;

    Player(int gridX, int gridY);
    void moveRandomly();
};

#endif // PLAYER_H
