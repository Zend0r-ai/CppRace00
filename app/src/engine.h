#pragma once
#define WIDTH 640
#define HEIGHT 480
#define CELL_W 16
#define CELL_H 16

class Game
{
public:
    Game()
    {
        for(int y=0; y < HEIGHT/CELL_H; y++)
        {
            for(int x=0; x < WIDTH/CELL_W; x++)
            {
                sf::RectangleShape cell(sf::Vector2f(CELL_W,CELL_H));
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color::White);
                cell.setFillColor(sf::Color::Transparent);
                cell.setPosition(x * CELL_W,y * CELL_H);
                this->_grid.push_back(cell);
            }
        }
    }

    void getSnake(std::vector<sf::Vector2f> snake)
    {
        this->_snake=snake;
    }

    void generateFruit()
    {
        this->_fruit.x=(rand()%39+1)*16;
        this->_fruit.y=(rand()%29+1)*16;
    }

    bool update(Snake &snake,unsigned int &score, int& seconds)
    {

        for(auto &cell : this->_grid)
        {
            for(auto &snake_part : this->_snake)
            {
                if(cell.getPosition().x == snake_part.x && cell.getPosition().y == snake_part.y)
                {
//                    cell.setOutlineThickness(1);
//                    cell.setOutlineColor(sf::Color::Blue);
                    cell.setFillColor(sf::Color::Green);
                    break;
                }

                else if(this->_fruit.x == snake.getPosition().at(0).x && this->_fruit.y == snake.getPosition().at(0).y)
                {
                    snake.grow();
                    generateFruit();
                    score += 1;
                    seconds = 0;
                }
                else if(this->_fruit.x == cell.getPosition().x && this->_fruit.y == cell.getPosition().y)
                {
                    cell.setOutlineThickness(1);
                    cell.setOutlineColor(sf::Color::Blue);
                    cell.setFillColor(sf::Color::Red);
                }
                else if(snake_part.x > 624 || snake_part.x < 0 || snake_part.y > 464 || snake_part.y < 0)
                    return true;
                else
                {
                    cell.setFillColor(sf::Color::Transparent);
                }
            }
        }
        return false;
    }

    void clearTrack()
    {
        for(auto &cell : this->_grid)
            if(cell.getOutlineThickness() != 0)
                cell.setOutlineThickness(0);
    }

    void draw(sf::RenderWindow &window)
    {
        for(auto  &cell : this->_grid) window.draw(cell);
    }
private:
    std::vector<sf::RectangleShape> _grid;
    std::vector<sf::Vector2f> _snake;
    sf::Vector2f _fruit;
};