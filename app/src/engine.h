#pragma once

bool checkCollision(const sf::RectangleShape&, const sf::RectangleShape& );

	/* Returns a rectangle at the specified coordinates */
	sf::RectangleShape getRectangleAt(sf::Vector2f location, sf::Color);