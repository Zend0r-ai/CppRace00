#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("app/resources/font/Px437_IBM_Conv.ttf")) {
        //handle error
        std::cerr << "Error loading fonts for menu window: ./app/src/Menu.cpp\n";
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString(">. New Player");
    menu[0].setCharacterSize((height / width) * 50);
    menu[0].setPosition(sf::Vector2f(width / 2,
                        height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    menu[0].setOrigin(menu[0].getLocalBounds().width / 2.0f,
                        menu[0].getLocalBounds().height / 2.0f);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Red);
    menu[1].setString("Play");
    menu[1].setCharacterSize((height / width) * 50);
    menu[1].setPosition(sf::Vector2f(width / 2,
                        height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    menu[1].setOrigin(menu[1].getLocalBounds().width / 2.0f,
                        menu[1].getLocalBounds().height / 2.0f);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Scores");
    menu[2].setCharacterSize((height / width) * 50);
    menu[2].setPosition(sf::Vector2f(width / 2,
                        height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    menu[2].setOrigin(menu[2].getLocalBounds().width / 2.0f,
                        menu[2].getLocalBounds().height / 2.0f);

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize((height / width) * 50);
    menu[3].setPosition(sf::Vector2f(width / 2,
                        height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
    menu[3].setOrigin(menu[3].getLocalBounds().width / 2.0f,
                        menu[3].getLocalBounds().height / 2.0f);

    m_selectedItem = 1;
}

Menu::~Menu() {
}

void Menu::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveDown() {
    if (m_selectedItem + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[m_selectedItem].setFillColor(sf::Color::White);
        m_selectedItem++;
        if (m_selectedItem == 0)
            menu[m_selectedItem].setFillColor(sf::Color::Green);
        else
            menu[m_selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveUp() {
    if (m_selectedItem - 1 >= 0) {
        menu[m_selectedItem].setFillColor(sf::Color::White);
        m_selectedItem--;
        if (m_selectedItem == 0)
            menu[m_selectedItem].setFillColor(sf::Color::Green);
        else
            menu[m_selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::EnterName(sf::Event event) {
    sf::String playerInput;

    if (menu[0].getString() == ">. New Player")
        menu[0].setString(">. ");
    if (event.text.unicode == 8 && menu[0].getString().getSize() > 3) {
        menu[0].setString(menu[0].getString().substring(0, menu[0].getString().getSize() - 1));
    } else if (menu[0].getString().getSize() < 10 && event.text.unicode != 8
                && !std::isspace(event.text.unicode)) {
        playerInput += event.text.unicode;
        menu[0].setString(menu[0].getString() + playerInput);
    }
}

std::string Menu::GetPlayerName() {
    return menu[0].getString().substring(3, menu[0].getString().getSize());
}
