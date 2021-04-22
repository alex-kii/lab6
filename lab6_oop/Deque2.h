#pragma once

#include "DequeBase.h"
#include "List2.h"

template<typename T>
class Deque2 : public DequeBase<T>
{
private:

	List2<T>* list2;
	int size;

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
{
	list2 = new List2<T>();
	size = 0;
}

template<typename T>
Deque2<T>::Deque2(const Deque2& other)
{
	list2 = new List2<T>();
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list2->push_back(other.list2->sel_el(i));
	}
}

template<typename T>
Deque2<T>::Deque2(Deque2&& other)
{
	size = other.size;
	list2 = other.list2;
	other.size = NULL;
	other.list2 = nullptr;
}

template<typename T>
Deque2<T>::~Deque2() {
	delete list2;
	size = 0;
}

template<typename T>
int Deque2<T>::GetSize() const { return size; }

template<typename T>
void Deque2<T>::PushFront(const T& element)
{
	list2->push_front(element);
	++size;
}

template<typename T>
void Deque2<T>::PushBack(const T& element)
{
	list2->push_back(element);
	++size;
}

template<typename T>
T Deque2<T>::PopFront()
{
	--size;
	return list2->pop_front();
}

template<typename T>
T Deque2<T>::PopBack()
{
	--size;
	return list2->pop_back();
}

template<typename T>
T Deque2<T>::PeekFront() const { return list2->sel_el(0); }

template<typename T>
T Deque2<T>::PeekBack() const { return list2->sel_el(size - 1); }

template<typename T>
Deque2<T>& Deque2<T>::operator=(const Deque2<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2->clear();

	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list2->push_back(other.list2->sel_el(i));
	}
}

template<typename T>
Deque2<T>& Deque2<T>::operator=(Deque2<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2.clear();

	size = other.size;
	list2 = other.list2;
	other.size = NULL;
	other.list2 = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque2<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list2->sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}