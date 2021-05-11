#pragma once

#include "DequeBase.h"
#include "List2.h"

template<typename T>
class Deque2 : public DequeBase<T>
{
private:

	List2<T> list2;

public:
	Deque2();

	Deque2(const Deque2& other);

	Deque2(Deque2&& other);

	~Deque2();

	int GetSize() const;

	void PushFront(const T& element);

	void PushBack(const T& element);

	T PopFront();

	T PopBack();

	T PeekFront() const;

	T PeekBack() const;

	Deque2& operator=(const Deque2& other);
	Deque2& operator=(Deque2&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Deque2<T>& obj);
};

template<typename T>
Deque2<T>::Deque2()
{ }

template<typename T>
Deque2<T>::Deque2(const Deque2& other)
{
	list2 = other.list2;
}

template<typename T>
Deque2<T>::Deque2(Deque2&& other)
{
	list2 = std::move(other.list2);
}

template<typename T>
Deque2<T>::~Deque2() { }

template<typename T>
int Deque2<T>::GetSize() const { return list2.getsize(); }

template<typename T>
void Deque2<T>::PushFront(const T& element)
{
	list2.push_front(element);
}

template<typename T>
void Deque2<T>::PushBack(const T& element)
{
	list2.push_back(element);
}

template<typename T>
T Deque2<T>::PopFront()
{
	return list2.pop_front();
}

template<typename T>
T Deque2<T>::PopBack()
{
	return list2.pop_back();
}

template<typename T>
T Deque2<T>::PeekFront() const { return list2.sel_el(0); }

template<typename T>
T Deque2<T>::PeekBack() const { return list2.sel_el(list2.getsize() - 1); }

template<typename T>
Deque2<T>& Deque2<T>::operator=(const Deque2<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2.clear();

	list2 = other.list2;
}

template<typename T>
Deque2<T>& Deque2<T>::operator=(Deque2<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2.clear();

	list2 = std::move(other.list2);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque2<T>& obj)
{
	for (size_t i = 0; i < obj.list2.getsize(); i++)
	{
		os << obj.list2.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}