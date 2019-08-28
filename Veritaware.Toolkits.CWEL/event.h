#pragma once

#include <vector>
#include "hashing.h"
#include "streaming.h"

namespace veritaware
{
	class EventArgs : public IHashable, public IToString
	{
	public:
		// Inherited via IHashable
		virtual int32_t GetHashCode() const override;

		// Inherited via IToString
		virtual std::string ToString() const override;
	};

	typedef void(*callback)(void * sender, EventArgs& e);

	class EventHandler : public IHashable, public IToString
	{
	public:
		EventHandler() = default;

		void Invoke(void * sender, EventArgs& e);

		EventHandler& operator +=(callback delegate);
		EventHandler& operator -=(callback delegate);

	private:
		void * _sender;
		EventHandler& operator =(const EventHandler& e) {}; // non-re-assignable!
		std::vector<callback> _delegates{};

		// Inherited via IHashable
		virtual int32_t GetHashCode() const override;

		// Inherited via IToString
		virtual std::string ToString() const override;
	};
}