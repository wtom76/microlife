#pragma once
#include "config.h"

namespace microlife
{
	class position
	{
		std::size_t x_{0};
		std::size_t y_{0};
		std::size_t field_idx_{0};

	public:
		position(std::size_t x, std::size_t y)
			: x_{x}
			, y_{y}
			, field_idx_{y * config::field::width_ + x}
		{} 
		position(std::size_t field_idx)
			: x_{field_idx % config::field::width_}
			, y_{field_idx / config::field::width_}
			, field_idx_{field_idx}
		{} 
		std::size_t x() const noexcept { return x_; }
		std::size_t y() const noexcept { return y_; }
		std::size_t field_idx() const noexcept { return field_idx_; }

		position north() const noexcept { return {x_, y_ - 1}; }
		position south() const noexcept { return {x_, y_ + 1}; }
		position west() const noexcept { return {x_ - 1, y_}; }
		position east() const noexcept { return {x_ + 1, y_}; }
		position north_west() const noexcept { return {x_ - 1, y_ - 1}; }
		position north_east() const noexcept { return {x_ + 1, y_ - 1}; }
		position south_west() const noexcept { return {x_ - 1, y_ + 1}; }
		position south_east() const noexcept { return {x_ + 1, y_ + 1}; }
	};
}
