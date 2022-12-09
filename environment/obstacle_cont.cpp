#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "obstacle_cont.h"
#include "obstacle.h"

//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::populate()
{
	constexpr int rate{1024};
	data_.clear();
	std::srand(std::time(nullptr));
	// borders
	for (std::size_t y{0}; y != cfg().field_.height_; ++y)
	{
		data_.emplace_back(std::make_unique<obstacle>(0, y));
		data_.emplace_back(std::make_unique<obstacle>(cfg().field_.width_ - 1, y));
	}
	//~borders
	for (std::size_t x{1}; x != cfg().field_.width_ - 1; ++x)
	{
		// borders
		data_.emplace_back(std::make_unique<obstacle>(x, 0));
		data_.emplace_back(std::make_unique<obstacle>(x, cfg().field_.height_ - 1));
		//~borders

		for (std::size_t y{1}; y != cfg().field_.height_ - 1; ++y)
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
