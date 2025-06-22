#include "Game.h"

Game::Game() : window(sf::VideoMode(1600, 900), "SFML Demo") {
    backgroundTexture.loadFromFile("Images/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    float scaleX = static_cast<float>(1600) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(900) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);

    font.loadFromFile("Font/font.ttf");
    text.setFont(font);
    text.setString("Hello SFML!");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(20, 20);

    music.openFromFile("Music/music.ogg");
    music.setLoop(true);
    music.play();

    std::ofstream file("Data/data.txt", std::ios::app);
    file << "Game started.\n";
    file.close();
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(backgroundSprite);
        window.draw(text);
        window.display();
    }
}


//#include<iostream>
//
//
//using namespace std;
//int main() {
//	cout << "HELLO\n";
//}