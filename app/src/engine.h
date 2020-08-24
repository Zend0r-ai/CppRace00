#pragma once
#include "Graphics.hpp"
#include "Snake.h"
#define CELL_W 16
#define CELL_H 16

class Game
{
public:
    Game(int width, int height);

    void getSnake(std::vector<sf::Vector2f> snake);
    void generateFruit();
    void update_delay(Snake &snake, float& delay);
    bool update(Snake &snake,unsigned int &score, int& seconds);
    void clearTrack();
    void draw(sf::RenderWindow &window);

private:
    int m_width = 0;
    int m_height = 0;
    std::vector<sf::RectangleShape> _grid;
    std::vector<sf::Vector2f> _snake;
    sf::Vector2f _fruit;

    
};
