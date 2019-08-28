#pragma once

#include "hashing.h"
#include "streaming.h"

#define object veritaware::Object

namespace veritaware
{
	class Object : public IHashable, public IToString
	{
		// Inherited via IHashable
		virtual int32_t GetHashCode() const override
		{
			return (int32_t)this;
		}

		// Inherited via IToString
		virtual std::string ToString() const override
		{
			return std::string("veritaware::Object");
		}
	};
}
