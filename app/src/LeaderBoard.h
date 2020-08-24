#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include "Graphics.hpp"

class LeaderBoardWindow {
public:
    LeaderBoardWindow(float width, float height);
    ~LeaderBoardWindow();

    void Draw(sf::RenderWindow &window);

private:
    std::vector<std::pair<std::string, int> > m_scoreBoard;
    sf::Text Caption_label;
    sf::Text Hint_label;
    sf::Font font;
    int m_player_count = 0;
    sf::Text m_leaderBoard [10];
};
