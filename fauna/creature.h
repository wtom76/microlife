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
	// types
	public:
		using buffer_t = std::vector<std::unique_ptr<creature>>;
	public:
		creature(std::size_t x, std::size_t y)
			: entity{x, y, creature_color_}
		{}
		bool cycle(field& fld, buffer_t& children);
	};
}