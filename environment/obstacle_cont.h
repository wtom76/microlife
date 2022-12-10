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
		buffer_t permanent_;
		buffer_t expiring_;
	// methods
	public:
		void populate();
		void fill(field& dest) const;
		void cycle(field& dest);
	};
}
