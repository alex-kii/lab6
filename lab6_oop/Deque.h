#pragma once

#include "DequeBase.h"
#include "List.h"

template<typename T>
class Deque : public DequeBase<T>
{
private:

	List<T> list;

public:
	Deque();

	Deque(const Deque& other);

	Deque(Deque&& other);

	~Deque();

	int GetSize() const;

	void PushFront(const T& element);

	void PushBack(const T& element);

	T PopFront();

	T PopBack();

	T PeekFront() const;

	T PeekBack() const;

	Deque& operator=(const Deque& other);
	Deque& operator=(Deque&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Deque<T>& obj);
};

template<typename T>
Deque<T>::Deque()
{ }

template<typename T>
Deque<T>::Deque(const Deque& other)
{
	list = other.list;
}

template<typename T>
Deque<T>::Deque(Deque&& other)
{
	list = std::move(other.list);
}

template<typename T>
Deque<T>::~Deque() { }

template<typename T>
int Deque<T>::GetSize() const { return list.getsize(); }

template<typename T>
void Deque<T>::PushFront(const T& element)
{
	list.push_front(element);
}

template<typename T>
void Deque<T>::PushBack(const T& element)
{
	list.push_back(element);
}

template<typename T>
T Deque<T>::PopFront()
{
	return list.pop_front();
}

template<typename T>
T Deque<T>::PopBack()
{
	return list.pop_back();
}

template<typename T>
T Deque<T>::PeekFront() const { return list.sel_el(0); }

template<typename T>
T Deque<T>::PeekBack() const { return list.sel_el(list.getsize() - 1); }

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = other.list;
}

template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = std::move(other.list);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& obj)
{
	for (size_t i = 0; i < obj.list.getsize(); i++)
	{
		os << obj.list.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}