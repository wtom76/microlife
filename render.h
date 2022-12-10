#pragma once
#include <SFML/Graphics.hpp>
#include "types.hpp"

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
	public:
		static constexpr rgba_t null_color_{0};

	private:
		const std::size_t					width_;
	    std::unique_ptr<sf::RenderWindow>	window_;
	    std::unique_ptr<sf::Texture>		texture_;
		buffer_t							buffer_;

	// methods
	public:
		render();

		bool is_open() const;
		void clear();
		void draw();

		void set(position const& pos, rgba_t value) noexcept;
	};
}