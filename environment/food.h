#pragma once
#include "../entity.h"

namespace microlife::environment
{
	class food : public entity
	{
		static constexpr render::rgba_t food_color_{0xffff0000};

		static constexpr std::int64_t bite_energy_taken_{200ll};	/// energy taken from bite
	public:
		static constexpr std::int64_t initial_energy_{10000ll};		/// creature energy when field is seeded 
	// data
	public:
		food(position const& pos)
			: entity{food_color_, initial_energy_, pos}
		{}
		std::int64_t get_bitten(entity*) noexcept override
		{
			const std::int64_t energy_taken{std::max<std::int64_t>(std::min<std::int64_t>(energy_, bite_energy_taken_), 0ll)};
			energy_ -= energy_taken;
			return energy_taken;
		}
	};
}