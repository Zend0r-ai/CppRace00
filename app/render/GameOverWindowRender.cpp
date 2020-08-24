#include "GameOverWindowRender.h"

void SwitchWindows(sf::RenderWindow& gameOver_window, GameOverWindow& gameOver,
                    const std::string& name) {
    switch (gameOver.GetPressedItem()) {
        case 0:
            gameOver_window.close();
            renderMenuWindow(gameOver_window.getSize().x, gameOver_window.getSize().y);
            break;
        case 1:
            gameOver_window.close();
            renderLeaderBoard(gameOver_window.getSize().x, gameOver_window.getSize().y);
            break;
        case 2:
            gameOver_window.close();
            break;
    }
}

void renderGameOverWindow(int score, const std::string& name,
                        sf::RenderWindow& gameOver_win) {
    GameOverWindow gameOver(gameOver_win.getSize().x, gameOver_win.getSize().y, score);
    // gameOver_win.clear();
    while(gameOver_win.isOpen()) {
        sf::Event event;
    
        while (gameOver_win.pollEvent(event)) {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            gameOver.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            gameOver.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            SwitchWindows(gameOver_win, gameOver, name);
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    gameOver_win.close();
                default:
                    break;
            }
        }
        gameOver_win.clear();
        gameOver.Draw(gameOver_win);
        gameOver_win.display();
    }

}
