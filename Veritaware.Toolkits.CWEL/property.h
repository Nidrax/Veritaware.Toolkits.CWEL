#pragma once

template <class T>
class Property
{
public:
	Property();
	Property(T * field);
	~Property();

	friend Property& operator<<(Property& lhs, const T& rhs);
	friend Property& operator>>(Property& lhs, T& rhs);

	//ToDo: Changed event

private:
	bool _selfAloc;
	T* _field;
};