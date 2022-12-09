#pragma once

namespace microlife
{
	class config;
	
	const config& cfg() noexcept;

	//---------------------------------------------------------------------------------------------------------
	/// class config
	//---------------------------------------------------------------------------------------------------------
	class config
	{
	// types
	public:
		struct field
		{
			static constexpr unsigned int width_{256};
			static constexpr unsigned int height_{256};

			static_assert(width_ > 2);
			static_assert(height_ > 2);
		};
	// data
	public:
		field field_;

	// methods
	private:
		static config& _cfg() noexcept
		{
			return const_cast<config&>(cfg());
		}
	};
}