#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include "src/Snake.h"
#include "src/Engine.h"

sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"SNAKE");
sf::Clock chrono;
sf::Clock clear_chrono;
sf::Clock diff_chrono;
sf::Clock game_chrono;

int seconds=0;
int minutes=0;
unsigned int score=0;
std::string hscore;

bool loose=false;
bool pause=false;
float delay=0.09;

void getHIScore(std::string &new_hscore, int game_score,bool mode=0)
{
    std::string new_score;
    std::fstream reader;

    if(!mode)
    {
        reader.open("score");
        reader >> new_score;

        hscore=new_score;
    }
    else
    {
        new_score=std::to_string(game_score);
        reader.open("score");
        reader << new_score;
    }

    reader.close();
}

int main()
{
    sf::Font font;
    font.loadFromFile("font/Px437_IBM_Conv.ttf");

    sf::Text ui_score;
    ui_score.setFont(font);
    ui_score.setPosition(WIDTH-200,20);
    ui_score.setCharacterSize(15);
    ui_score.setOutlineThickness(1);
    ui_score.setOutlineColor(sf::Color::Blue);
    ui_score.setFillColor(sf::Color::Magenta);

    sf::Text text2;
    text2.setString("DO YOU WANNA PLAY AGAIN? [ PRESS SPACE ]");
    text2.setFont(font);
    text2.setPosition(WIDTH/2-300,WIDTH/2-20);
    text2.setCharacterSize(15);
    text2.setOutlineThickness(1);
    text2.setOutlineColor(sf::Color::Blue);
    text2.setFillColor(sf::Color::Green);

    sf::Text ui_time;
    ui_time.setFont(font);
    ui_time.setPosition(20,20);
    ui_time.setCharacterSize(15);
    ui_time.setOutlineThickness(1);
    ui_time.setOutlineColor(sf::Color::Blue);
    ui_time.setFillColor(sf::Color::Green);

    sf::Text ui_hscore;
    ui_hscore.setFont(font);
    ui_hscore.setPosition(WIDTH/2-100,20);
    ui_hscore.setCharacterSize(15);
    ui_hscore.setOutlineThickness(1);
    ui_hscore.setOutlineColor(sf::Color::Blue);
    ui_hscore.setFillColor(sf::Color::Yellow);

    srand(time(nullptr));
    Game game;
    getHIScore(hscore,score);
    Snake snake;

    game.generateFruit();


    while(window.isOpen())
    {
        ui_score.setString("SCORE : "+std::to_string(score));
        ui_hscore.setString("H-SCORE : "+hscore);


        if(std::to_string(minutes).length() < 2 && std::to_string(seconds).length() < 2)
            ui_time.setString("TIME 0"+std::to_string(minutes)+":0"+std::to_string(seconds));
        else if(std::to_string(minutes).length() < 2 && std::to_string(seconds).length() > 1)
            ui_time.setString("TIME 0"+std::to_string(minutes)+":"+std::to_string(seconds));
        else
            ui_time.setString("TIME "+std::to_string(minutes)+":"+std::to_string(seconds));

        if(!loose || snake.GetSnakeSize() >= 1)
        {
            game.getSnake(snake.getPosition());
            game.update(snake,score);
            loose=snake.check_collision();

            if(diff_chrono.getElapsedTime().asSeconds()  > 15)
            {
                if(delay > 0.02) delay-=0.01;
                diff_chrono.restart();
            }

            if(chrono.getElapsedTime().asSeconds() > delay)
            {
                if(!pause)snake.move();
                chrono.restart();
            }

            if(clear_chrono.getElapsedTime().asSeconds() > 0.2)
            {
                game.clearTrack();
                clear_chrono.restart();
            }

            if(game_chrono.getElapsedTime().asSeconds() > 1)
            {
                seconds+=1;
                if(seconds == 4)
                {
                    seconds=0;
                    snake.DeleteLastElem();
                }
                game_chrono.restart();
            }

            sf::Event event;
            while(window.pollEvent(event))
            {
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

            window.clear();
            window.draw(ui_score);
            window.draw(ui_hscore);
            window.draw(ui_time);
            game.draw(window);
            window.display();
        }
        else
        {
            sf::Event event;
            try{
                ui_score.setString("YOUR SCORE : " + std::to_string(score));
                if(score > static_cast<unsigned int>(std::stoi(hscore))) getHIScore(hscore,score,1);
                ui_score.setPosition(WIDTH/2-100,HEIGHT/2);


                while(window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed) window.close();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        snake.reset(32,64);
                        snake.shrink();
                        snake.setDirection(0);
                        score=0;
                        delay=0.09;
                        diff_chrono.restart();
                        ui_score.setPosition(WIDTH-400,20);
                        loose=false;
                        minutes=0;
                        seconds=0;
                        getHIScore(hscore,score);
                    }
                }
            } catch (std::invalid_argument& e) {
                window.clear();
                window.draw(ui_score);
                window.draw(text2);
                window.display();
            }

        }

    }

    return 0;
}
