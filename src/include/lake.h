#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <utility>

class Lake {
public:
    Lake(int gridX, int gridY, int width, int height, int numBlocks);

    void generate();
    void draw(sf::RenderWindow& window) const;

private:
    int gridX, gridY;
    int width, height;
    int numBlocks;
    std::vector<sf::RectangleShape> blocks;

    void generateClump();
    void addBlock(int x, int y);
    std::vector<std::pair<int, int> > getNeighbors(int x, int y) const;

    std::set<std::pair<int, int> > clump;
};
