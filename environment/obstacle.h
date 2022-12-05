#pragma once
#include "../entity.h"

namespace microlife::environment
{
	class obstacle : public entity
	{
		static constexpr render::rgba_t obstacle_color_{0xffffffff};
	public:
		obstacle(std::size_t x, std::size_t y)
			: entity{x, y, obstacle_color_}
		{}
	};
}