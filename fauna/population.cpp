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
				data_.emplace_back(std::make_unique<creature>(x, y, creature::initial_energy_));
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
//---------------------------------------------------------------------------------------------------------
void microlife::fauna::population::cycle(field& fld)
{
	buffer_t next;
	buffer_t dead;
	next.reserve(data_.size());
	dead.reserve(data_.size());

    std::random_device rd;
	std::shuffle(std::begin(data_), std::end(data_), std::mt19937{rd()});

	for (auto& ent : data_)
	{
		if (ent->cycle(fld, next))
		{
			next.emplace_back(std::move(ent));
		}
		else
		{
			dead.emplace_back(std::move(ent));
		}
	}
	std::swap(next, data_);

	for (const auto& ent : dead)
	{
		fld.set(ent->x(), ent->y(), nullptr);
	}
}
