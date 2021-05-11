#pragma once
#include <iostream>

template<typename T>
class List // класс односвязный список
{
private:

	class Node // класс хранилище
	{
	public:
		Node(T data = T(), Node* pNext = nullptr); // конструктор

		Node* pNext; // переменная адреса
		T data; // переменная информ
	};

	int size; // кол-во эл
	Node* head; // указатель на начало списка
	Node* tail; // указатель на конец списка

public:

	List(); // конструктор

	List(const List& other);

	List(const List&& other);

	~List(); // деструктор

	void push_front(const T& data); // добавляет элемент в начало

	void push_back(const T& data); //добавляем элемент в конец

	T pop_front(); // удаляет самый первый элемент

	T removeAT(const int index); // удаляет элемент в указываемом месте

	T pop_back(); // удаляет последний элемент

	void clear(); // удаляет все элементы

	int getsize() const; // получаем кол-во эл

	T& sel_el(const int index) const; // возвращает элемент по индексу

	List& operator=(const List& other);

	List& operator=(List&& other);
};

template<typename T>
List<T>::Node::Node(T data, Node* pNext) : data(data), pNext(pNext) { }

template<typename T>
List<T>::List() : size(0), head(nullptr), tail(nullptr) { }

template<typename T>
List<T>::List(const List& other)
{
	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List<T>::List(const List&& other) : size(other.size), head(other.head), tail(other.tail)
{
	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
List<T>::~List() { clear(); }

template<typename T>
void List<T>::push_front(const T& data)
{
	if (head == nullptr) // если ещё нет ни одного хранилища
	{
		Node* p = new Node(data);// создаём первое хранилище
		head = p;
		tail = p;
	}
	else
	{
		head = new Node(data, head);
	}
	size++;
}

template<typename T>
void List<T>::push_back(const T& data)
{
	if (head == nullptr) // если ещё нет ни одного хранилища
	{
		head = tail = new Node(data); // создаём первое хранилище
	}
	else
	{
		Node* current = this->tail;
		current->pNext = new Node(data);
		tail = current->pNext;
	}
	size++;
}

template<typename T>
T List<T>::pop_front()
{
	Node* temp = head;

	T data = temp->data;

	if (size > 1)
		head = head->pNext;
	else
		tail = head = nullptr;

	delete temp;
	size--;

	return data;
}

template<typename T>
T List<T>::removeAT(const int index)
{
	if (index > this->size - 1) // Если указанный индекс находится вне границ списка
	{
		std::cout << "Указанный индекс находится вне границ!" << std::endl;
		return T();
	}
	else if (index == 0) // если индекс 0, то пользуемся уже готовым методом
	{
		return pop_front();
	}
	else
	{
		Node* previous = this->head;  // вызываем все имеющиеся хранилища в объект всех хранилищей (this избыточен)

		for (int i = 0; i < index - 1; i++) //ищем хранилише, которое стоит до того хранилища, которое мы хотим удалить
		{
			previous = previous->pNext;

		}
		Node* toDelete = previous->pNext; // создаём указатель на хранилище, которое мы хотим удалить

		if (toDelete->pNext == nullptr)
			tail = previous;

		previous->pNext = toDelete->pNext; // на место хранилища, которое хотим удалить ставим следующее соседнее
		T data = toDelete->data;
		delete toDelete; // удаляем хранилище, на которое указали
		size--;

		return data;
	}
}

template<typename T>
T List<T>::pop_back() {
	return removeAT(size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (size) // пока не равно 0
	{
		pop_front();
	}
}

template<typename T>
int List<T>::getsize() const { return size; }

template<typename T>
T& List<T>::sel_el(const int index) const
{
	if (index > this->size - 1) // Если указанный индекс находится вне границ списка
	{
		std::cout << "Указанный индекс находится вне границ! Аварийное заверешение программы!" << std::endl;
		abort();
	}

	if (index == 0)
		return head->data;
	else if (index == this->size - 1)
		return tail->data;
	else
	{
		Node* current = head;

		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}

		return current->data;
	}
}

template<typename T>
List<T>& List<T>::operator=(const List& other)
{
	size = 0;
	head = nullptr;
	tail = nullptr;

	if (this == &other)
	{
		return *this;
	}

	clear();

	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List<T>& List<T>::operator=(List&& other)
{
	if (this == &other)
	{
		return *this;
	}

	clear();

	size = other.size;
	this->head = other.head;
	this->tail = other.tail;

	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}