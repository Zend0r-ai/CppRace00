#include "GameWindow.h"

GameWindow::GameWindow(int width, int height) {
    m_font.loadFromFile("app/resources/font/Px437_IBM_Conv.ttf");

    m_ui_score.setFont(m_font);
    m_ui_score.setPosition(width-200,20);
    m_ui_score.setCharacterSize(15);
    m_ui_score.setOutlineThickness(1);
    m_ui_score.setOutlineColor(sf::Color::Blue);
    m_ui_score.setFillColor(sf::Color::Magenta);

    m_ui_time.setFont(m_font);
    m_ui_time.setPosition(20,20);
    m_ui_time.setCharacterSize(15);
    m_ui_time.setOutlineThickness(1);
    m_ui_time.setOutlineColor(sf::Color::Blue);
    m_ui_time.setFillColor(sf::Color::Green);

    m_ui_hscore.setFont(m_font);
    m_ui_hscore.setPosition(width/2-100,20);
    m_ui_hscore.setCharacterSize(15);
    m_ui_hscore.setOutlineThickness(1);
    m_ui_hscore.setOutlineColor(sf::Color::Blue);
    m_ui_hscore.setFillColor(sf::Color::Yellow);
}

void GameWindow::UpdateTime(int minutes, int seconds) {
    if(std::to_string(minutes).length() < 2 && std::to_string(seconds).length() < 2)
        m_ui_time.setString("TIME 0"+std::to_string(minutes)+":0"+std::to_string(seconds));
    else if(std::to_string(minutes).length() < 2 && std::to_string(seconds).length() > 1)
        m_ui_time.setString("TIME 0"+std::to_string(minutes)+":"+std::to_string(seconds));
    else
        m_ui_time.setString("TIME "+std::to_string(minutes)+":"+std::to_string(seconds));
}

void GameWindow::Draw(sf::RenderWindow& window) {
    window.draw(m_ui_hscore);
    window.draw(m_ui_score);
    window.draw(m_ui_time);
}
