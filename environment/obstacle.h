#pragma once
#include "../entity.h"

namespace microlife::environment
{
	class obstacle : public entity
	{
		static constexpr render::rgba_t obstacle_color_{0xffffffff};
	public:
		obstacle(position const& pos)
			: entity{obstacle_color_, 0, pos}
		{}
		std::int64_t get_bitten(entity*) noexcept override { return 0; }
	};
}