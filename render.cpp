#include "pch.h"
#include "render.h"
#include "config.h"

//---------------------------------------------------------------------------------------------------------
microlife::render::render()
	: width_{cfg().field_.width_}
	, window_{std::make_unique<sf::RenderWindow>(sf::VideoMode{cfg().field_.width_, cfg().field_.height_}, "microlife")}
	, texture_{std::make_unique<sf::Texture>()}
	, buffer_(cfg().field_.width_ * cfg().field_.height_, 0)
{
	texture_->create(cfg().field_.width_, cfg().field_.height_);
}
//---------------------------------------------------------------------------------------------------------
bool microlife::render::is_open() const
{
	return window_->isOpen();
}
//---------------------------------------------------------------------------------------------------------
void microlife::render::clear()
{
	// clear the window with black color
	window_->clear(sf::Color::Black);
	std::memset(buffer_.data(), 0, buffer_.size() * sizeof(buffer_t::value_type));
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
	texture_->update(reinterpret_cast<unsigned char*>(buffer_.data()));
	window_->draw(sf::Sprite{*texture_});
	// end the current frame
	window_->display();
}
//---------------------------------------------------------------------------------------------------------
void microlife::render::set(std::size_t x, std::size_t y, rgba_t value) noexcept
{
	buffer_[y * width_ + x] = value;
}
