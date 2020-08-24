#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include "../src/Snake.h"
#include "../src/engine.h"

class GameWindow {
public:
    GameWindow(int width, int height);

    void UpdateTime(int minutes, int seconds);
    void Draw(sf::RenderWindow& window);
private:
    sf::Font m_font;
    sf::Text m_ui_score;
    sf::Text m_ui_time;
    sf::Text m_ui_hscore;
};
