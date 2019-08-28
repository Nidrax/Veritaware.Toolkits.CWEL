#include "stdafx.h"
#include "property.h"

template<class T>
veritaware::Property<T>::Property()
{

	_field = new T();
	_selfAloc = true;
}

template<class T>
veritaware::Property<T>::Property(T * field)
{
	_field = field;
	_selfAloc = false;
}

template<class T>
veritaware::Property<T>::~Property()
{
	if (_selfAloc)
		delete _field;
}

template<class T>
veritaware::Property<T> & operator<<(veritaware::Property<T> & lhs, const T & rhs)
{
	*(lhs._field) = rhs;
	lhs.Changed.Invoke(&lhs, veritaware::EventArgs());
	return lhs;
}

template<class T>
veritaware::Property<T> & operator>>(veritaware::Property<T> & lhs, T & rhs)
{
	rhs = *(lhs._field);
	return lhs;
}