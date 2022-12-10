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

		static constexpr std::int64_t cycle_energy_{10ll};			/// energy spent every cycle
		static constexpr std::int64_t bite_energy_taken_{10ll};		/// energy taken from bite
		static constexpr std::int64_t bite_energy_spent_{5ll};		/// energy spent to bite
		static constexpr std::int64_t initial_energy_{1000ll};	/// creature energy when field is seeded 
	// types
	public:
		using buffer_t = std::vector<std::unique_ptr<creature>>;
	// data
	// methods
	private:
		void _check_neighb(position const& pos, field& fld, buffer_t& children);
		void _bite(entity* victim);
	public:
		creature(position const& pos)
			: entity{creature_color_, initial_energy_, pos}
		{}
		creature(std::int64_t energy, position const& pos)
			: entity{creature_color_, energy, pos}
		{}
		bool cycle(field& fld, buffer_t& children);
		std::int64_t get_bitten(entity* by) noexcept override;
	};
}