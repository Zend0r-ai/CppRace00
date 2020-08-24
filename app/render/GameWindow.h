#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include "../src/Snake.h"
#include "../src/engine.h"
#include "../src/GameWindow.h"
#include "GameOverWindowRender.h"

void renderGameWindow(int width, int height, const std::string& PlayerName);
