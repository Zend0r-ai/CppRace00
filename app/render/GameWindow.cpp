#include "GameWindow.h"

sf::Clock chrono;
sf::Clock clear_chrono;
sf::Clock diff_chrono;
sf::Clock game_chrono;

int seconds = 0;
int minutes = 0;
std::string hscore;

bool pause = false;
float delay = 0.04;

void getHIScore(std::string &new_hscore, int game_score,bool mode=0) {
    std::string new_score;
    std::fstream reader;

    if(!mode) {
        reader.open("score");
        reader >> new_score;

        hscore=new_score;
    } else {
        new_score=std::to_string(game_score);
        reader.open("score");
        reader << new_score;
    }
    reader.close();
}

void SaveScore(const int& sscore, const std::string& PlayerName) {
    std::ofstream FileWithScores("app/resources/scores.txt",
                                    std::ios_base::app);

    FileWithScores << PlayerName << "\n" << sscore << "\n";
}

void EventTracker(sf::RenderWindow& window, Snake& snake) {
    sf::Event event;

    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            if(snake.getDirection() != 3)snake.setDirection(2);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            if(snake.getDirection() != 2)snake.setDirection(3);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            if(snake.getDirection() != 0) snake.setDirection(1);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            if(snake.getDirection() != 1)snake.setDirection(0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            pause=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            pause=false;
    }
}

void renderGameWindow(int width, int height, const std::string& PlayerName) {
    sf::RenderWindow window(sf::VideoMode(width, height),"SNAKE");
    GameWindow game_window(width, height);

    unsigned int score = 0;
    srand(time(nullptr));
    Game game(width, height);
    getHIScore(hscore,score);
    Snake snake(width, height);
    game.generateFruit();
    bool loose = false;

    while(window.isOpen()) {
        game_window.UpdateTime(minutes, seconds);
        if(!loose && snake.GetSnakeSize() > 1) {
            game.getSnake(snake.getPosition());
            if(snake.check_collision() || game.update(snake, score, seconds))
                loose = true;
            if(delay < 0.5)
                game.update_delay(snake, delay);
            if(chrono.getElapsedTime().asSeconds() > delay) {
                if(!pause)snake.move();
                chrono.restart();
            }
            if(clear_chrono.getElapsedTime().asSeconds() > 0.2) {
                game.clearTrack();
                clear_chrono.restart();
            }
            if(game_chrono.getElapsedTime().asSeconds() > 1) {
                seconds+=1;
                if(seconds == 4) {
                    seconds=0;
                    snake.DeleteLastElem();
                }
                game_chrono.restart();
            }
            EventTracker(window, snake);
            window.clear();
            game_window.Draw(window);
            game.draw(window);
            window.display();
        }
        else {
            SaveScore(score, PlayerName);
            // window.close();
            break;
        }

    }
    renderGameOverWindow(score, PlayerName, window);
}
