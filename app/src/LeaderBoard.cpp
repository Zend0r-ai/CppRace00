#include "LeaderBoard.h"
#include <utility>
#include <vector>

bool comp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    return a.second < b.second;
}

void GetDataFromFile(std::vector<std::pair<std::string, int> >& m_scoreBoard) {
    std::ifstream FileInput ("app/resources/scores.txt");

    if (!FileInput.is_open())
        std::cout << "error while opening a file\n";
    std::string name;
    while(std::getline(FileInput, name)) {
        std::string score;
        getline(FileInput, score);
        m_scoreBoard.push_back(std::make_pair(name, std::stoi(score)));
        std::sort(m_scoreBoard.begin(), m_scoreBoard.end(), comp);
    }
}

LeaderBoardWindow::LeaderBoardWindow(float width, float height) {
    if (!font.loadFromFile("app/resources/font/Px437_IBM_Conv.ttf")) {
        //handle error
        std::cerr << "Error loading fonts for menu window: ./app/src/Menu.cpp\n";
    }
    Caption_label.setFont(font);
    Caption_label.setFillColor(sf::Color::Green);
    Caption_label.setString("Score Board");
    Caption_label.setCharacterSize((height / width) * 55);
    Caption_label.setPosition(sf::Vector2f(width / 2,
                        height / 14 * 1));
    Caption_label.setOrigin(Caption_label.getLocalBounds().width / 2.0f,
                            Caption_label.getLocalBounds().height / 2.0f);

    Hint_label.setFont(font);
    Hint_label.setFillColor(sf::Color::White);
    Hint_label.setString("-> Use Escape to Exit.");
    Hint_label.setCharacterSize((height / width) * 30);
    Hint_label.setPosition(sf::Vector2f(width / 2,
                        height / 14 * 12));
    Hint_label.setOrigin(Hint_label.getLocalBounds().width / 2.0f,
                            Hint_label.getLocalBounds().height / 2.0f);

    GetDataFromFile(m_scoreBoard);
    int count = 0;
    for (auto it = m_scoreBoard.rbegin(); it != m_scoreBoard.rend(); ++it) {
        if (count == 10 || count >= (int)m_scoreBoard.size())
            break;
        else {
            m_leaderBoard[count].setString(it->first + " " + std::to_string(it->second));
            m_leaderBoard[count].setFont(font);
            m_leaderBoard[count].setFillColor(sf::Color::Magenta);
            m_leaderBoard[count].setCharacterSize((height / width) * 30);
            m_leaderBoard[count].setPosition(sf::Vector2f(width / 2,
                        height / 14 * (count + 2)));
            m_leaderBoard[count].setOrigin(m_leaderBoard[count].getLocalBounds().width / 2.0f,
                            m_leaderBoard[count].getLocalBounds().height / 2.0f);
        }
        count++;
    }
    m_player_count = count;
}

LeaderBoardWindow::~LeaderBoardWindow() {
}

void LeaderBoardWindow::Draw(sf::RenderWindow &window) {
    window.draw(Caption_label);
    window.draw(Hint_label);
    for (int i = 0; i < m_player_count; i++)
        window.draw(m_leaderBoard[i]);
}
