#pragma once
#include "render.h"

namespace microlife
{
	class field;

	//---------------------------------------------------------------------------------------------------------
	/// class entity
	//---------------------------------------------------------------------------------------------------------
	class entity
	{
	private:
		std::size_t x_{0};
		std::size_t y_{0};
		const render::rgba_t color_{0};
		
	protected:
		entity(render::rgba_t color)
			: color_{color}
		{}
		entity(std::size_t x, std::size_t y, render::rgba_t color)
			: x_{x}
			, y_{y}
			, color_{color}
		{}

	public:
		virtual ~entity(){}
		render::rgba_t color() const noexcept { return color_; }
		std::size_t x() const noexcept { return x_; }
		std::size_t y() const noexcept { return y_; }
	};
}