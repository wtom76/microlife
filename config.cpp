#include "pch.h"
#include "config.h"

//---------------------------------------------------------------------------------------------------------
const microlife::config& microlife::cfg() noexcept
{
	static config cfg;
	return cfg;
}
