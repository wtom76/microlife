#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "population.h"
#include "creature.h"

//---------------------------------------------------------------------------------------------------------
void microlife::fauna::creature::_check_neighb(position const& pos, field& fld, buffer_t& children)
{
	entity* neighb{fld.get(pos)};
	if (!neighb)
	{
		// make child
		std::unique_ptr<creature> child{std::make_unique<creature>(energy_ / 2, pos)};
		children.emplace_back(std::move(child));
		energy_ /= 2;
	}
	else
	{
		_bite(neighb);
	}
}
//---------------------------------------------------------------------------------------------------------
bool microlife::fauna::creature::cycle(field& fld, buffer_t& children)
{
	// make children
	if (energy_ > cycle_energy_ + cycle_energy_)
	{
		_check_neighb(pos_.north(), fld, children);
		_check_neighb(pos_.north_west(), fld, children);
		_check_neighb(pos_.north_east(), fld, children);

		_check_neighb(pos_.west(), fld, children);
		_check_neighb(pos_.east(), fld, children);
		
		_check_neighb(pos_.south(), fld, children);
		_check_neighb(pos_.south_west(), fld, children);
		_check_neighb(pos_.south_east(), fld, children);
	}

	return (energy_ -= cycle_energy_) >= 0ll;
}
//---------------------------------------------------------------------------------------------------------
void microlife::fauna::creature::_bite(entity* victim)
{
	if (energy_ > bite_energy_spent_ && energy_ < initial_energy_)
	{
		energy_ -= bite_energy_spent_;
		energy_ += victim->get_bitten(this);
	}
}
//---------------------------------------------------------------------------------------------------------
std::int64_t microlife::fauna::creature::get_bitten(entity* by) noexcept
{
	const std::int64_t energy_taken{std::max<std::int64_t>(std::min<std::int64_t>(energy_, bite_energy_taken_), 0ll)};
	energy_ -= energy_taken;
	if (by && energy_ > 0)
	{
		energy_ += by->get_bitten(nullptr);
	}
	return energy_taken;
}
