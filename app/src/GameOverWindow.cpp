#include "GameOverWindow.h"


GameOverWindow::GameOverWindow(int width, int height, int score) {
    if (!m_font.loadFromFile("app/resources/font/Px437_IBM_3270pc.ttf")) {
        //handle error
        std::cerr << "Error loading fonts for menu window: ./app/src/Menu.cpp\n";
    }
    m_score[0].setFont(m_font);
    m_score[0].setFillColor(sf::Color::Green);
    m_score[0].setString("Your Score");
    m_score[0].setCharacterSize((width / height) * 50);
    m_score[0].setPosition(sf::Vector2f(width / 2,
                        (height / 6) * 1));
    m_score[0].setOrigin(m_score[0].getLocalBounds().width / 2.0f,
                        m_score[0].getLocalBounds().height / 2.0f);

    m_score[1].setFont(m_font);
    m_score[1].setFillColor(sf::Color::Magenta);
    m_score[1].setString(std::to_string(score));
    m_score[1].setCharacterSize((width / height) * 50);
    m_score[1].setPosition(sf::Vector2f(width / 2,
                        (height / 6) * 2));
    m_score[1].setOrigin(m_score[1].getLocalBounds().width / 2.0f,
                        m_score[1].getLocalBounds().height / 2.0f);

    m_menu[0].setFont(m_font);
    m_menu[0].setFillColor(sf::Color::Red);
    m_menu[0].setString("Menu");
    m_menu[0].setCharacterSize((width / height) * 30);
    m_menu[0].setPosition(sf::Vector2f(width / 2,
                        (height / 6) * 3));
    m_menu[0].setOrigin(m_menu[0].getLocalBounds().width / 2.0f,
                        m_menu[0].getLocalBounds().height / 2.0f);

    m_menu[1].setFont(m_font);
    m_menu[1].setFillColor(sf::Color::White);
    m_menu[1].setString("Scores");
    m_menu[1].setCharacterSize((width / height) * 30);
    m_menu[1].setPosition(sf::Vector2f(width / 2,
                        (height / 6) * 4));
    m_menu[1].setOrigin(m_menu[1].getLocalBounds().width / 2.0f,
                        m_menu[1].getLocalBounds().height / 2.0f);

    m_menu[2].setFont(m_font);
    m_menu[2].setFillColor(sf::Color::White);
    m_menu[2].setString("Exit");
    m_menu[2].setCharacterSize((width / height) * 30);
    m_menu[2].setPosition(sf::Vector2f(width / 2,
                        (height / 6) * 5));
    m_menu[2].setOrigin(m_menu[2].getLocalBounds().width / 2.0f,
                        m_menu[2].getLocalBounds().height / 2.0f);

    m_selectedItem = 0;
}

void GameOverWindow::Draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(m_menu[i]);
    }
    for (int i = 0; i < 2; i++) {
        window.draw(m_score[i]);
    }
}

void GameOverWindow::MoveUp() {
    if (m_selectedItem - 1 >= 0) {
        m_menu[m_selectedItem].setFillColor(sf::Color::White);
        m_selectedItem--;
        m_menu[m_selectedItem].setFillColor(sf::Color::Red);
    }
}

void GameOverWindow::MoveDown() {
    if (m_selectedItem + 1 < 3) {
        m_menu[m_selectedItem].setFillColor(sf::Color::White);
        m_selectedItem++;
        m_menu[m_selectedItem].setFillColor(sf::Color::Red);
    }
}
