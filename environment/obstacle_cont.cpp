#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "obstacle_cont.h"
#include "obstacle.h"

//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::populate()
{
	constexpr int rate{RAND_MAX / 100 * 25};
	data_.clear();
	std::srand(std::time(nullptr));
	for (std::size_t x{0}; x != cfg().field_.width_; ++x)
	{
		for (std::size_t y{0}; y != cfg().field_.height_; ++y)
		{
			if (std::rand() % rate == 0)
			{
				data_.emplace_back(std::make_unique<obstacle>(x, y));
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::update(field& dest) const
{
	for (const auto& ent : data_)
	{
		dest.set(ent->x(), ent->y(), ent.get());
	}
}
