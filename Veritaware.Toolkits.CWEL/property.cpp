#include "stdafx.h"
#include "property.h"


template<class T>
Property<T>::Property()
{
	_field = new T();
	_selfAloc = true;
}

template<class T>
Property<T>::Property(T * field)
{
	_field = field;
	_selfAloc = false;
}

template<class T>
Property<T>::~Property()
{
	if (_selfAloc)
		delete _field;
}

template<class T>
Property<T> & operator<<(Property<T> & lhs, const T & rhs)
{
	lhs.*_field = value;
	//ToDo: Raise Changed event
	return lhs;
}

template<class T>
Property<T> & operator>>(Property<T> & lhs, T & rhs)
{
	rhs = lhs.*_field;
	return lhs;
}