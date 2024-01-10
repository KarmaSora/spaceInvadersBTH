#include "Menu.h"

Menu::Menu()
    : window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Space Invaders Menu", sf::Style::Close, sf::ContextSettings(0, 0, 8)),
    startGame(false)
{
    window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	window.setMouseCursorVisible(true);
	window.setMouseCursorGrabbed(false);
	window.setActive(true);
	window.requestFocus();
	window.clear(sf::Color::Black);

    if (!font.loadFromFile("../Fonts/space_invaders.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (!font2.loadFromFile("../Fonts/MachineStd-Bold.otf")) {
        std::cerr << "Error loading font file" << std::endl;
        std::exit(EXIT_FAILURE);
    }



    //title: 
    setTextProperties(title, "SPACE INVADERS", 45,
        sf::Color::Green, WINDOWWIDTH / 2 - 150, WINDOWHEIGHT / 4);
    //start:
    setTextProperties(start, "Start Game", 30, sf::Color::Green, WINDOWWIDTH / 2 - 80, WINDOWHEIGHT / 2);
    //middle:
    setTextProperties(middle, "You get 3 lives, use them well..", 30, sf::Color::Red, WINDOWWIDTH / 2 - 100, WINDOWHEIGHT / 2 + 50);
    //exit:
    setTextProperties(exit, "Quit", 30, sf::Color::Green, WINDOWWIDTH / 2 - 30, WINDOWHEIGHT / 2 + 50);

	/*window.draw(*this);

	window.display();*/
}

Menu::Menu(int xPos, int yPos, sf::Color color, sf::Text title,
    sf::Text start, sf::Text exit, sf::Font font)

    : title(title), start(start),
    exit(exit), font(font)

{
    
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(title);
    target.draw(start);
    target.draw(exit);
}

void Menu::setTextProperties(sf::Text& text, const std::string& string, int characterSize, sf::Color color, float xPos, float yPos)
{
    text.setFont(font);
	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(color);
	text.setStyle(sf::Text::Bold);
	text.setPosition(xPos, yPos);
}

int Menu::handleInput(sf::Event event)
{

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

void Menu::run()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption = (selectedOption - 1 + 2) % 2;
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedOption = (selectedOption + 1) % 2;
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedOption == 0) {
                        window.close();
                        startGame = true;
                    }
                    else if (selectedOption == 1) {
                        window.close();
                    }
                }
                break;
            default:
                break;
            }
        }
        window.clear(sf::Color(0, 0, 0));

        //Highlight the selected option
        start.setFillColor(selectedOption == 0 ? sf::Color::Yellow : sf::Color::Green);
        exit.setFillColor(selectedOption == 1 ? sf::Color::Yellow : sf::Color::Green);

        window.draw(start);
        window.draw(middle);
        window.draw(exit);

        window.draw(title);
        window.display();

    }

}

bool Menu::getStartGame()
{
	return startGame;
}
