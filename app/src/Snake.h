#pragma once
#include <Graphics.hpp>
#include <iostream>
#define CELL_W 16
#define CELL_H 16


class Snake {
public:
    Snake(int new_w, int new_h);
    ~Snake();
    std::vector<sf::Vector2f> getPosition();
    void setDirection(short direction);
    short getDirection();
    void move();
    void shrink();
    void reset(int x, int y);
    bool check_collision();
    void grow();
    int GetSnakeSize() const;
    void DeleteLastElem();
private:
    sf::Clock _chrono;
    short _direction=2;
    std::vector<sf::Vector2f> _snake;
};
