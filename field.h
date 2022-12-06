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

		void set(std::size_t x, std::size_t y, entity* ent) noexcept;
		entity* get(std::size_t x, std::size_t y) const noexcept;
		void update(render& dest) const;
	};
}