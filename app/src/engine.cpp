#include "engine.h"

Game::Game(int width, int height) {
    m_height = height;
    m_width = width;

    for(int y = 0; y < height/CELL_H; y++) {
        for(int x = 0; x < width/CELL_W; x++) {
            sf::RectangleShape cell(sf::Vector2f(CELL_W,CELL_H));
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::White);
            cell.setFillColor(sf::Color::Transparent);
            cell.setPosition(x * CELL_W,y * CELL_H);
            this->_grid.push_back(cell);
        }
    }
}

void Game::getSnake(std::vector<sf::Vector2f> snake) {
    this->_snake=snake;
}

void Game::generateFruit() {
    int w_pos = (m_width / CELL_W) - 1;
    int h_pos = (m_height / CELL_H) - 1;

    this->_fruit.x=(rand()%w_pos+1)*16;
    this->_fruit.y=(rand()%h_pos+1)*16;
}

void Game::update_delay(Snake &snake, float& delay) {
    delay = 0.04 + ((snake.GetSnakeSize() - 1) * (0.005));
}

bool Game::update(Snake &snake,unsigned int &score, int& seconds) {
    for(auto &cell : this->_grid) {
        for(auto &snake_part : this->_snake) {
            if(cell.getPosition().x == snake_part.x
                && cell.getPosition().y == snake_part.y) {
                    cell.setFillColor(sf::Color::Green);
                    break;
            } else if(this->_fruit.x == snake.getPosition().at(0).x
                        && this->_fruit.y == snake.getPosition().at(0).y) {
                            snake.grow();
                            generateFruit();
                            score += 1;
                            seconds = 0;
            } else if(this->_fruit.x == cell.getPosition().x
                        && this->_fruit.y == cell.getPosition().y) {
                            cell.setOutlineThickness(1);
                            cell.setOutlineColor(sf::Color::Blue);
                            cell.setFillColor(sf::Color::Red);
            } else if(snake_part.x > m_width - CELL_W || snake_part.x < 0
                        || snake_part.y > m_height - CELL_H || snake_part.y < 0) {
                            return true;
            } else {
                cell.setFillColor(sf::Color::Transparent);
            }
        }
    }
    return false;
}

void Game::clearTrack() {
    for(auto &cell : this->_grid)
        if(cell.getOutlineThickness() != 0)
            cell.setOutlineThickness(0);
}

void Game::draw(sf::RenderWindow &window) {
    for(auto  &cell : this->_grid) window.draw(cell);
}
