#pragma once
#include "render.h"
#include "types.hpp"

namespace microlife
{
	class field;

	//---------------------------------------------------------------------------------------------------------
	/// class entity
	//---------------------------------------------------------------------------------------------------------
	class entity
	{
	protected:
		render::rgba_t	color_{0};
		std::int64_t	energy_{0};
		position		pos_;
		
	protected:
		entity(render::rgba_t color, std::int64_t energy, position pos)
			: color_{color}
			, energy_{energy}
			, pos_{pos}
		{}

	public:
		virtual ~entity(){}
		render::rgba_t color() const noexcept { return color_; }
		std::int64_t energy() const noexcept { return energy_; }
		const position& pos() const noexcept { return pos_; }

		virtual std::int64_t get_bitten(entity* by) noexcept = 0;
	};
}