#pragma once
#include "creature.h"

namespace microlife
{
	class field;
}

namespace microlife::fauna
{
	//---------------------------------------------------------------------------------------------------------
	/// class population
	//---------------------------------------------------------------------------------------------------------
	class population
	{
	// types
		using buffer_t = std::vector<std::unique_ptr<creature>>;
	// data
		buffer_t data_;
	// methods
	public:
		void populate(field const& fld);
		void update(field& dest) const;

		void cycle(field& fld);
		void add(std::unique_ptr<creature>& ent);
	};

}