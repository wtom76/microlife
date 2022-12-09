#include "pch.h"
#include "field.h"
#include "config.h"
#include "render.h"
#include "entity.h"

//---------------------------------------------------------------------------------------------------------
microlife::field::field()
	: width_{cfg().field_.width_}
	, data_(cfg().field_.width_ * cfg().field_.height_, nullptr)
{}
//---------------------------------------------------------------------------------------------------------
void microlife::field::set(std::size_t x, std::size_t y, entity* ent) noexcept
{
	data_[y * width_ + x] = ent;
}
//---------------------------------------------------------------------------------------------------------
microlife::entity* microlife::field::get(std::size_t x, std::size_t y) const noexcept
{
	return data_[y * width_ + x];
}
//---------------------------------------------------------------------------------------------------------
void microlife::field::update(render& dest) const
{
	dest.clear();
	for (const auto& ent : data_)
	{
		if (ent)
		{
			dest.set(ent->x(), ent->y(), ent->color());
		}
	}
}
