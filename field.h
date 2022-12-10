#pragma once
#include "render.h"

namespace microlife
{
	class entity;
	class render;

	//---------------------------------------------------------------------------------------------------------
	/// class field
	//---------------------------------------------------------------------------------------------------------
	class field
	{
	// types
	private:
		using buffer_t = std::vector<entity*>;

	// data
	private:
		const std::size_t	width_;
		buffer_t			data_;

	// methods
	public:
		field();

		void set(position const& pos, entity* ent) noexcept;
		entity* get(position const& pos) const noexcept;
		void update(render& dest) const;
	};
}