#include "lake.h"
#include <cstdlib>
#include <ctime>

Lake::Lake(int gridX, int gridY, int width, int height, int numBlocks)
    : gridX(gridX), gridY(gridY), width(width), height(height), numBlocks(numBlocks) {
    generate();
}

void Lake::generate() {
    blocks.clear();
    clump.clear();
    generateClump();
}

void Lake::generateClump() {
    if (numBlocks <= 0) return;

    // Start with a random block within the specified area
    int startX = rand() % width + gridX;
    int startY = rand() % height + gridY;

    // Use a queue to perform flood-fill
    std::vector<std::pair<int, int> > queue;
    queue.push_back(std::make_pair(startX, startY));
    clump.insert(std::make_pair(startX, startY));

    while (!queue.empty() && clump.size() < static_cast<size_t>(numBlocks)) {
        auto pos = queue.back();
        queue.pop_back();
        addBlock(pos.first, pos.second);

        for (auto neighbor : getNeighbors(pos.first, pos.second)) {
            int nx = neighbor.first;
            int ny = neighbor.second;
            if (nx >= gridX && nx < gridX + width && ny >= gridY && ny < gridY + height) {
                if (clump.find(neighbor) == clump.end()) {
                    clump.insert(neighbor);
                    queue.push_back(neighbor);
                }
            }
        }
    }
}

void Lake::addBlock(int x, int y) {
    sf::RectangleShape block(sf::Vector2f(8, 8));  // Assuming CELL_SIZE is 8
    block.setFillColor(sf::Color::Blue);
    block.setPosition((x - gridX) * 8, (y - gridY) * 8);  // Assuming CELL_SIZE is 8
    blocks.push_back(block);
}

std::vector<std::pair<int, int> > Lake::getNeighbors(int x, int y) const {
    return std::vector<std::pair<int, int> >{
        {x + 1, y}, {x - 1, y},
        {x, y + 1}, {x, y - 1}
    };
}

void Lake::draw(sf::RenderWindow& window) const {
    for (const auto& block : blocks) {
        window.draw(block);
    }
}
