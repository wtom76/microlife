#pragma once
#include "../entity.h"

namespace microlife
{
	class field;
}

namespace microlife::environment
{
	//---------------------------------------------------------------------------------------------------------
	/// class obstacle_cont
	//---------------------------------------------------------------------------------------------------------
	class obstacle_cont
	{
	// types
		using buffer_t = std::vector<std::unique_ptr<entity>>;
	// data
		buffer_t data_;
	// methods
	public:
		void populate();
		void update(field& dest) const;
	};
}
