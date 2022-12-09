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
		static constexpr std::ptrdiff_t initial_energy_{1000ll};	/// creature energy when field is seeded 
		static constexpr std::ptrdiff_t cycle_energy_{10ll};		/// energy spent every cycle
	// types
	public:
		using buffer_t = std::vector<std::unique_ptr<creature>>;
	// data
	private:
		std::ptrdiff_t energy_{0};
	// methods
	private:
		void _check_neighb(std::size_t x, std::size_t y, field& fld, buffer_t& children);
	public:
		creature(std::size_t x, std::size_t y, std::ptrdiff_t energy)
			: entity{x, y, creature_color_}
			, energy_{energy}
		{}
		bool cycle(field& fld, buffer_t& children);
	};
}