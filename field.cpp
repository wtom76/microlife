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
void microlife::field::update(render& dest) const
{
	for (const auto& ent : data_)
	{
		if (ent)
		{
			dest.set(ent->x(), ent->y(), ent->color());
		}
	}
}
