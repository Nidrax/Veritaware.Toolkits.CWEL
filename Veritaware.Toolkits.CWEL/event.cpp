#include "event.h"

int veritaware::EventArgs::GetHashCode() const
{
	return (int32_t)this;
}

std::string veritaware::EventArgs::ToString() const
{
	return std::string("veritaware::EventArgs");
}

void veritaware::EventHandler::Invoke(void * sender, veritaware::EventArgs& e)
{
	for (auto& d : _delegates)
	{
		(*d)(sender, e);
	}
}

veritaware::EventHandler & veritaware::EventHandler::operator+=(veritaware::callback delegate)
{
	_delegates.push_back(delegate);
	return *this;
}

veritaware::EventHandler & veritaware::EventHandler::operator-=(veritaware::callback delegate)
{
	int i = 0;
	
	for(auto & d : _delegates)
	{
		if (d == delegate)
			break;

		++i;
	}

	if (i < _delegates.size())
		_delegates.erase(_delegates.begin() + i);

	return *this;
}

int32_t veritaware::EventHandler::GetHashCode() const
{
	return int32_t();
}

std::string veritaware::EventHandler::ToString() const
{
	return std::string("veritaware::EventHandler");
}
