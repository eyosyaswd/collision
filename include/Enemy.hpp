#include <SFML/Graphics.hpp>

	class Enemy
	{
	public:
		Enemy(float startX, float startY);
		sf::FloatRect getPosition();
		sf::RectangleShape getShape();
		void move(float secs);
		void update();
    sf::Vector2f position;
    sf::Vector2f direction;

	private:
		sf::RectangleShape spaceship;
		float velocity = 30.f;


	};
