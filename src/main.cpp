#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"  // Include the Player header

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int GRID_SIZE = 100;
const int CELL_SIZE = 8;
const int NUM_PLAYERS = 10;

int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Random Moving Players");

    std::vector<Player> players;
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        int gridX = rand() % GRID_SIZE;
        int gridY = rand() % GRID_SIZE;
        players.emplace_back(gridX, gridY);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (auto& player : players) {
            player.moveRandomly();
        }

        window.clear();
        for (const auto& player : players) {
            window.draw(player.shape);
        }
        window.display();

        sf::sleep(sf::milliseconds(100));  // Adjust the speed of the simulation
    }

    return 0;
}
