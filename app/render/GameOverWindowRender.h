#pragma once
#include "../src/GameOverWindow.h"
#include "GameWindow.h"
#include "OptionWindow.h"

void renderGameOverWindow(int score, const std::string& name,
                        sf::RenderWindow& gameOver_win);
