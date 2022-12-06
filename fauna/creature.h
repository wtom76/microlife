#pragma once
#include "../entity.h"

namespace microlife::fauna
{
	//---------------------------------------------------------------------------------------------------------
	/// class creature
	//---------------------------------------------------------------------------------------------------------
	class creature : public entity
	{
		static constexpr render::rgba_t creature_color_{0xff00ffff};
	public:
		creature(std::size_t x, std::size_t y)
			: entity{x, y, creature_color_}
		{}
	};
}