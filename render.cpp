#include "render.h"

//---------------------------------------------------------------------------------------------------------
microlife::render::render()
	: window_{std::make_unique<sf::RenderWindow>(sf::VideoMode{width, height}, "microlife")}
	, texture_{std::make_unique<sf::Texture>()}
	, buffer_{std::make_unique<buffer_t>()}
{
	texture_->create(width, height);
}
//---------------------------------------------------------------------------------------------------------
void microlife::render::clear()
{
	// clear the window with black color
	window_->clear(sf::Color::Black);
}
//---------------------------------------------------------------------------------------------------------
void microlife::render::draw()
{
	if (!window_->isOpen())
	{
		return;
	}

	sf::Event event;
	while (window_->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window_->close();
			return;
		}
	}

	// clear the window with black color
	window_->clear(sf::Color::Black);

	// Update screen
	texture_->update(reinterpret_cast<unsigned char*>(buffer_->data()));
	window_->draw(sf::Sprite{*texture_});
	// end the current frame
	window_->display();
}
