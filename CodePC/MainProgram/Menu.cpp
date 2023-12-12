#include "Menu.h"

Menu::Menu(float windowWidth, float windowHeight)
{
    sf::Font font;
    if (!font.loadFromFile("../Fonts/AeogoProTry-Bold.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    //title: 
    setTextProperties(title, "Space Invaders", 40,
        sf::Color::White, windowHeight / 2 - 150, windowHeight / 4);
    //start:
    setTextProperties(start, "Start Game", 30, sf::Color::White, windowWidth / 2 - 80, windowHeight / 2);
    //exit:
    setTextProperties(exit, "Exit", 30, sf::Color::White, windowWidth / 2 - 30, windowHeight / 2 + 50);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(title);
    target.draw(start);
    target.draw(exit);
}

int Menu::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::FloatRect startBounds = start.getGlobalBounds();
                if (startBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                    return 1; //starting the game
                }
                sf::FloatRect exitBounds = exit.getGlobalBounds();
                if (exitBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                    window.close();
                }
            }
            break;
        default:
            break;
        }
    }
    return 0; //stays at menu
}

void Menu::setTextProperties(sf::Text& text, const std::string& content, unsigned int size, const sf::Color& color, float x, float y)
{
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(x, y);
}
