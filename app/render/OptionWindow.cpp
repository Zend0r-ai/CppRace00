#include "OptionWindow.h"

void renderLeaderBoard(int width, int height) {
    sf::RenderWindow scores_window(sf::VideoMode(width, height),"SNAKE");
    LeaderBoardWindow board(width, height);

    while(scores_window.isOpen()) {
        sf::Event event;
        while(scores_window.pollEvent(event)) {
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Escape) {
                    scores_window.close();
                    renderMenuWindow(width, height);
                }
            }
        }
        scores_window.clear();
        board.Draw(scores_window);
        scores_window.display();
    }
}
