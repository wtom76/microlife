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
		static constexpr unsigned int width{1024};
		static constexpr unsigned int height{1024};

	// types
	public:
		using rgba_t = uint32_t;
	private:
		using buffer_t = std::array<rgba_t, width * height>;

	// data
	private:
	    std::unique_ptr<sf::RenderWindow>	window_;
	    std::unique_ptr<sf::Texture>		texture_;
		std::unique_ptr<buffer_t>			buffer_;

	// methods
	public:
		render();

		void clear();
		void draw();
	};
}