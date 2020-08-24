#include "Snake.h"

Snake::Snake(int new_w, int new_h) {
    int pos_x = new_w / 32 * 16;
    int pos_y = new_h / 32 * 16;
    for(int i = 0; i < 4; i++) {
        this->_snake.push_back(sf::Vector2f(pos_x + (16 * i), pos_y));
    }
}
Snake::~Snake() {
    while(_snake.size() != 0)
        _snake.erase(_snake.end() - 1);
}

std::vector<sf::Vector2f> Snake::getPosition() {
    return this->_snake;
}

void Snake::setDirection(short direction){
    this->_direction=direction;
}

short Snake::getDirection() {
    return this->_direction;
}

void Snake::move() {
    sf::Vector2f old_pos_head=this->_snake.at(0);
    sf::Vector2f old_pos;
    sf::Vector2f tmp_pos;

    if(this->_direction == 0)this->_snake.at(0).x += CELL_W;
    if(this->_direction == 1)this->_snake.at(0).x -= CELL_W;
    if(this->_direction == 2)this->_snake.at(0).y -= CELL_W;
    if(this->_direction == 3)this->_snake.at(0).y += CELL_W;
        for(auto part=this->_snake.begin()+1; part != this->_snake.end(); part++){
            if(part == this->_snake.begin()+1) {
                old_pos=(*part);
                (*part)=old_pos_head;
            } else {
                tmp_pos=(*part);
                (*part)=old_pos;
                old_pos=tmp_pos;
            }
        }
}

void Snake::shrink() {
    this->_snake.resize(2);
}

void Snake::reset(int x, int y) {
    this->_snake.at(0).x=x;
    this->_snake.at(0).y=y;
}

bool Snake::check_collision() {
    sf::Vector2f headXY=this->_snake.at(0);
    for(auto part=this->_snake.begin() + 1; part != this->_snake.end();  ++part) {
        if ((*part).x == headXY.x && (*part).y == headXY.y)
            return true;
    }
    return false;
}

void Snake::grow() {
    if(this->_snake.size() < 100) {
        sf::Vector2f snake_part(this->_snake.back().x,this->_snake.back().y);
        this->_snake.push_back(snake_part);
    }
}

int Snake::GetSnakeSize() const {
    return _snake.size();
}

void Snake::DeleteLastElem() {
    _snake.erase(_snake.end() - 1);
}
