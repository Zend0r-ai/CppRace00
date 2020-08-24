#pragma once
#include "Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return m_selectedItem; }
    void EnterName(sf::Event event);
    std::string GetPlayerName();

private:
    int m_selectedItem = 1;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
