#pragma once
#include "../entity.h"

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
		using buffer_t = std::vector<std::unique_ptr<entity>>;
	// data
		buffer_t data_;
	// methods
	public:
		void populate(field const& fld);
		void update(field& dest) const;
	};

}