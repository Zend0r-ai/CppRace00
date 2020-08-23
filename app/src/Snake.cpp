#include "Snake.h"
//#include <iostream>
//
//Snake::Snake() {
//    m_dir = Snake::Direction::Up;
//    Snake::snake_elems.insert(Snake::snake_elems.begin(), {200, 200});
////    for(int i = 0; i < 3; i++){
////        Snake::snake_elems.insert(Snake::snake_elems.end(),{Snake::snake_elems.begin()->m_x + 50, Snake::snake_elems.begin()->m_y + 0});
////    }
//}
//
//void Snake::ExecuteWay(const Direction dir) {
//    if(dir == Direction::Up){
//        std::cout << "up";
//        m_dir = Direction::Up;
//    }else if(dir == Direction::Down){
//            std::cout << "Down";
//        m_dir = Direction::Down;
//    }else if(dir == Direction::Left){
//                std::cout << "Left";
//        m_dir = Direction::Left;
//    }else if(dir == Direction::Right){
//                    std::cout << "Right";
//        m_dir = Direction::Right;
//    }
//}
//
//void Snake::AddPart(int x, int y) {
//    Snake::snake_elems.insert(Snake::snake_elems.begin(),{Snake::snake_elems.begin()->m_x + x, Snake::snake_elems.begin()->m_y + y});
//}
//
//std::vector<Snake_pos> Snake::PrintSnake() {
//    return snake_elems;
//}
//
//void Snake::DeleteLastPart() {
//    snake_elems.erase(Snake::snake_elems.end() - 1);
//}
//Snake::Direction Snake::get_dir() const {
//    return m_dir;
//}}