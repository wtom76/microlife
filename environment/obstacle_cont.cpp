#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "obstacle_cont.h"
#include "obstacle.h"
#include "food.h"

//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::populate()
{
	constexpr int rate{128};
	permanent_.clear();
	std::srand(std::time(nullptr));
	// borders
	for (std::size_t y{0}; y != cfg().field_.height_; ++y)
	{
		permanent_.emplace_back(std::make_unique<obstacle>(position{0, y}));
		permanent_.emplace_back(std::make_unique<obstacle>(position{config::field::width_ - 1, y}));
	}
	//~borders
	for (std::size_t x{1}; x != cfg().field_.width_ - 1; ++x)
	{
		// borders
		permanent_.emplace_back(std::make_unique<obstacle>(position{x, 0}));
		permanent_.emplace_back(std::make_unique<obstacle>(position{x, config::field::height_ - 1}));
		//~borders

		for (std::size_t y{1}; y != cfg().field_.height_ - 1; ++y)
		{
			if (std::rand() % rate == 0)
			{
				permanent_.emplace_back(std::make_unique<obstacle>(position{x, y}));
			}
		}
	}

	for (std::size_t x{1}; x != cfg().field_.width_ - 1; ++x)
	{
		for (std::size_t y{1}; y != cfg().field_.height_ - 1; ++y)
		{
			if (std::rand() % rate == 0)
			{
				expiring_.emplace_back(std::make_unique<food>(position{x, y}));
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::fill(field& dest) const
{
	for (const auto& ent : permanent_)
	{
		dest.set(ent->pos(), ent.get());
	}
	for (const auto& ent : expiring_)
	{
		dest.set(ent->pos(), ent.get());
	}
}
//---------------------------------------------------------------------------------------------------------
void microlife::environment::obstacle_cont::cycle(field& dest)
{
	buffer_t next;
	buffer_t dead;
	next.reserve(expiring_.size());
	dead.reserve(expiring_.size());

	for (auto& ent : expiring_)
	{
		if (ent->energy() > 0)
		{
			next.emplace_back(std::move(ent));
		}
		else
		{
			dead.emplace_back(std::move(ent));
		}
	}
	std::swap(next, expiring_);

	for (const auto& ent : dead)
	{
		dest.set(ent->pos(), nullptr);
	}
}
