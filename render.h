#pragma once
#include <SFML/Graphics.hpp>

namespace microlife
{
	//---------------------------------------------------------------------------------------------------------
	/// class render
	/// graphical output
	//---------------------------------------------------------------------------------------------------------
	class render
	{
	// types
	public:
		using rgba_t = uint32_t;
	private:
		using buffer_t = std::vector<rgba_t>;

	// data
	private:
		const std::size_t					width_;
	    std::unique_ptr<sf::RenderWindow>	window_;
	    std::unique_ptr<sf::Texture>		texture_;
		buffer_t							buffer_;

	// methods
	public:
		render();

		void clear();
		void draw();

		void set(std::size_t x, std::size_t y, rgba_t value) noexcept;
	};
}