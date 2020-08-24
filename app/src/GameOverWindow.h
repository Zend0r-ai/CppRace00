#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphics.hpp"

class GameOverWindow {
public:
    GameOverWindow(int width, int height, int score);
    ~GameOverWindow(){};

    void Draw(sf::RenderWindow& window);
    int GetPressedItem() { return m_selectedItem; }
    void MoveUp();
    void MoveDown();
private:
    int m_selectedItem;
    sf::Font m_font;
    sf::Text m_score[2];
    sf::Text m_menu[3];
};
