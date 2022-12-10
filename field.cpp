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
void microlife::field::set(position const& pos, entity* ent) noexcept
{
	data_[pos.field_idx()] = ent;
}
//---------------------------------------------------------------------------------------------------------
microlife::entity* microlife::field::get(position const& pos) const noexcept
{
	return data_[pos.field_idx()];
}
//---------------------------------------------------------------------------------------------------------
void microlife::field::update(render& dest) const
{
	dest.clear();
	for (const auto& ent : data_)
	{
		if (ent)
		{
			dest.set(ent->pos(), ent->color());
		}
	}
}
