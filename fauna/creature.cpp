#include "../pch.h"
#include "../config.h"
#include "../field.h"
#include "population.h"
#include "creature.h"

//---------------------------------------------------------------------------------------------------------
void microlife::fauna::creature::_check_neighb(std::size_t x, std::size_t y, field& fld, buffer_t& children)
{
	entity* neighb{fld.get(x, y)};
	if (!neighb)
	{
		std::unique_ptr<creature> child{std::make_unique<creature>(x, y, energy_ / 2)};
		children.emplace_back(std::move(child));
		energy_ /= 2;
	}
}
//---------------------------------------------------------------------------------------------------------
bool microlife::fauna::creature::cycle(field& fld, buffer_t& children)
{
	// make children
	if (energy_ > cycle_energy_ + cycle_energy_)
	{
		_check_neighb(x() - 1, y() - 1, fld, children);
		_check_neighb(x() - 1, y(), fld, children);
		_check_neighb(x() - 1, y() + 1, fld, children);

		_check_neighb(x(), y() - 1, fld, children);
		_check_neighb(x(), y() + 1, fld, children);
		
		_check_neighb(x() + 1, y() - 1, fld, children);
		_check_neighb(x() + 1, y(), fld, children);
		_check_neighb(x() + 1, y() + 1, fld, children);
	}

	return (energy_ -= cycle_energy_) >= 0ll;
}
