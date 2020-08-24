#include "menuWindow.h"

int SwitchWindows(sf::RenderWindow& menu_window, Menu& menu) {
    switch (menu.GetPressedItem()) {
        case 1:
            menu_window.close();
            renderGameWindow(menu_window.getSize().x, menu_window.getSize().y,
                            menu.GetPlayerName());
            return 0;
            break;
        case 2:
            menu_window.close();
            renderLeaderBoard(menu_window.getSize().x, menu_window.getSize().y);
            return 1;
            break;
        case 3:
            menu_window.close();
            break;
    }
    return -1;
}

int CheckEvents(sf::RenderWindow& menu_window, Menu& menu) {
    sf::Event event;

    while (menu_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        return SwitchWindows(menu_window, menu);
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::Closed:
                menu_window.close();
            case sf::Event::TextEntered:
                menu.EnterName(event);
            default:
                break;
        }
    }
    return -1;
}

int renderMenuWindow(int width, int height) {
    sf::RenderWindow menu_window(sf::VideoMode(width, height),"SNAKE");
    Menu menu(menu_window.getSize().x, menu_window.getSize().y);
    int event = -1;
    
    while(menu_window.isOpen()) {
        event = CheckEvents(menu_window, menu);
        if (event != -1)
            return event;
        menu_window.clear();
        menu.Draw(menu_window);
        menu_window.display();
    }
    return -1;
}
