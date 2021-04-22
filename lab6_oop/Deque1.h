#pragma once

#include "DequeBase.h"
#include "List.h"

template<typename T>
class Deque1 : public DequeBase<T>
{
private:

	List<T>* list;
	int size;

public:
	Deque1();

	Deque1(const Deque1& other);

	Deque1(Deque1&& other);

	~Deque1();

	int GetSize() const;

	void PushFront(const T& element);

	void PushBack(const T& element);

	T PopFront();

	T PopBack();

	T PeekFront() const;

	T PeekBack() const;

	Deque1& operator=(const Deque1& other);
	Deque1& operator=(Deque1&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Deque1<T>& obj);
};

template<typename T>
Deque1<T>::Deque1()
{
	list = new List<T>();
	size = 0;
}

template<typename T>
Deque1<T>::Deque1(const Deque1& other)
{
	list = new List<T>();
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list->push_back(other.list->sel_el(i));
	}
}

template<typename T>
Deque1<T>::Deque1(Deque1&& other)
{
	size = other.size;
	list = other.list;
	other.size = NULL;
	other.list = nullptr;
}

template<typename T>
Deque1<T>::~Deque1() {
	delete list;
	size = 0;
}

template<typename T>
int Deque1<T>::GetSize() const { return size; }

template<typename T>
void Deque1<T>::PushFront(const T& element)
{
	list->push_front(element);
	++size;
}

template<typename T>
void Deque1<T>::PushBack(const T& element)
{
	list->push_back(element);
	++size;
}

template<typename T>
T Deque1<T>::PopFront()
{
	--size;
	return list->pop_front();
}

template<typename T>
T Deque1<T>::PopBack()
{
	--size;
	return list->pop_back();
}

template<typename T>
T Deque1<T>::PeekFront() const { return list->sel_el(0); }

template<typename T>
T Deque1<T>::PeekBack() const { return list->sel_el(size - 1); }

template<typename T>
Deque1<T>& Deque1<T>::operator=(const Deque1<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list->clear();

	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list->push_back(other.list->sel_el(i));
	}
}

template<typename T>
Deque1<T>& Deque1<T>::operator=(Deque1<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	size = other.size;
	list = other.list;
	other.size = NULL;
	other.list = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque1<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list->sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}