#pragma once
#include <Graphics.hpp>


#define WIDTH 640
#define HEIGHT 480
#define CELL_W 16
#define CELL_H 16


class Snake
{
public:
    Snake()
    {
//        int pos_x = (rand()%35+4)*16;
//        int pos_y = (rand()%35+4)*16;
//        for(int i = 0; i < 4; i++)
//            this->_snake.push_back(sf::Vector2f(pos_x + (16 * 0),pos_y));
        this->_snake.push_back(sf::Vector2f(32,64));
        this->_snake.push_back(sf::Vector2f(48,64));
        this->_snake.push_back(sf::Vector2f(64,64));
        this->_snake.push_back(sf::Vector2f(78,64));
    }

    std::vector<sf::Vector2f> getPosition()
    {
        return this->_snake;
    }

    void setDirection(short direction)
    {
        this->_direction=direction;
    }

    short getDirection()
    {
        return this->_direction;
    }


    void move()
    {
        sf::Vector2f old_pos_head=this->_snake.at(0);
        sf::Vector2f old_pos;
        sf::Vector2f tmp_pos;

        if(this->_direction == 0)this->_snake.at(0).x += CELL_W;
        if(this->_direction == 1)this->_snake.at(0).x -= CELL_W;
        if(this->_direction == 2)this->_snake.at(0).y -= CELL_W;
        if(this->_direction == 3)this->_snake.at(0).y += CELL_W;

        for(auto part=this->_snake.begin()+1; part != this->_snake.end(); part++)
        {
            if(part == this->_snake.begin()+1)
            {
                old_pos=(*part);
                (*part)=old_pos_head;
            }
            else
            {
                tmp_pos=(*part);
                (*part)=old_pos;
                old_pos=tmp_pos;
            }
        }
    }

    void shrink()
    {
        this->_snake.resize(2);
    }

    void reset(int x, int y)
    {
        this->_snake.at(0).x=x;
        this->_snake.at(0).y=y;
    }

    bool check_collision()
    {
        sf::Vector2f headXY=this->_snake.at(0);

        for(auto part=this->_snake.begin(); part != this->_snake.end();  ++part)
            if((*part).x == headXY.x && (*part).y == headXY.y)
                return true;
        return false;
    }

    void grow()
    {
        if(this->_snake.size() < 100)
        {
            sf::Vector2f snake_part(this->_snake.back().x,this->_snake.back().y);
            this->_snake.push_back(snake_part);
        }

    }
    int GetSnakeSize() const{
        return _snake.size();
    }
    void DeleteLastElem(){
        _snake.erase(_snake.end() - 1);
    }
private:
    sf::Clock _chrono;
    short _direction=0;
    std::vector<sf::Vector2f> _snake;
};
