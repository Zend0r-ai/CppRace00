#include "Snake.h"

void Snake::ExecuteWay(const Direction dir) {
    if(dir == Direction::Up){
        m_dir = Direction::Up;
    }else if(dir == Direction::Down){
        m_dir = Direction::Down;
    }else if(dir == Direction::Left){
        m_dir = Direction::Left;
    }else if(dir == Direction::Right){
        m_dir = Direction::Right;
    }
}

Snake::Direction Snake::get_dir() const {
    return m_dir;
}