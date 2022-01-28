#pragma once
#include "SFML/Graphics.hpp"

class Bat {
protected:
	sf::RectangleShape rect;
	int width = 20;
	int height = 100;
	float speedy = 5.f;
public:
	Bat(float startx, float starty) {
		rect.setSize(sf::Vector2f(width,height));
        rect.setPosition(startx, starty);
		rect.setFillColor(sf::Color::Yellow);
	}
	sf::RectangleShape getShape() { return rect; }
    void update() {
        int currentx = rect.getPosition().x;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            rect.move(0, -speedy);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rect.move(0, speedy);
        }
        if (rect.getPosition().y <= 0) {
            rect.setPosition(currentx, 0);
        }
        if (rect.getPosition().y >= SCREEN_HEIGHT - height) {
            rect.setPosition(currentx, SCREEN_HEIGHT - height);
        }
    }
   
    sf::FloatRect getHitBox() { return rect.getGlobalBounds(); }


};
