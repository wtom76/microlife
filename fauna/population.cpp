#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "population.h"
#include "creature.h"

//---------------------------------------------------------------------------------------------------------
void microlife::fauna::population::populate(field const& fld)
{
	constexpr int rate{1024};
	data_.clear();
	std::srand(std::time(nullptr));
	for (std::size_t x{0}; x != cfg().field_.width_; ++x)
	{
		for (std::size_t y{0}; y != cfg().field_.height_; ++y)
		{
			if (!fld.get(x, y) && std::rand() % rate == 0)
			{
				data_.emplace_back(std::make_unique<creature>(x, y));
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------
void microlife::fauna::population::update(field& dest) const
{
	for (const auto& ent : data_)
	{
		dest.set(ent->x(), ent->y(), ent.get());
	}
}