#pragma once

#include <iostream>

template<typename T>
class List2 // класс двусвязный список
{
private:

	class Node // класс хранилище
	{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pBack = nullptr); // конструктор хранилища

		Node* pNext, * pBack;
		T data;
	};

	Node* head; // объект голова хранилиша 
	Node* tail; // объект хвост хранилища 
	int size; // кол-во хранилищ

public:

	List2(); // консруктор

	~List2(); // деструктор 

	void push_front(T data); // добавить элемент в начало

	void insert(T data, int index); // добавить элемент в указанное место

	void push_back(T data); // добавить в элемент в конец

	T pop_front(); // удалить элемент из начала

	void removeAT(int index); // удалить указанный элемент 

	T pop_back(); // удалить элемент из конца

	void clear(); // удалить все элементы

	int Getsize() { return size; } // кол-во хранилищ 

	T sel_el(const int index) const; // возвращает элемент по индексу

};

template<typename T>
List2<T>::Node::Node(T data, Node* pNext, Node* pBack) : data(data), pNext(pNext), pBack(pBack)
{ }

template<typename T>
List2<T>::List2() : size(0), head(nullptr), tail(nullptr) // конструктор 
{ }

template<typename T>
List2<T>::~List2() 
{
	clear(); // удаление всех хранилищ
}

template<typename T> 
void List2<T>::push_front(T data) // добавить элемент в начало
{
	if (size == 0)
	{
		Node* p = new Node(data);
		head = p;
		tail = p;
	}
	else
	{
		Node* current = this->head;
		head = new Node(data, head, nullptr);
		current->pBack = head;
	}
	size++;
}

template<typename T> 
void List2<T>::insert(T data, int index) // добавить элемент в указанное место
{
	int indexmax = size - 1, indexmin = 0, resmax = size - 1, resmin = 0; // крайние возможные индексы данного массива
	resmax -= index; // мин. кол-во шагов, прежде чем добрать до хранилища из хвоста
	resmin += index; // мин. кол-во шагов, прежде чем добрать до хранилища из головы

	if (index == indexmin || index == indexmax)
	{
		if (index == indexmin)
		{
			push_front(data);
		} // если индекс первого хранилиша, выполняем метод добавить в начало
		else
		{
			push_back(data);
		} // если индекс последнего хранилиша, выполняем метод добавить в конце
	}
	else if (resmin < resmax || resmin == resmax)
	{
		int counter = 0; // номер хранилище, в котором находимся
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				current = new Node<T>(data, current, current->pBack);
				(current->pNext)->pBack = current; // старое хранлище в пред. указетеле указываем на новое хранилище
				(current->pBack)->pNext = current; 
				break;
			}
			current = current->pNext;
			counter++;
		}
		size++;
	}
	else if (resmin > resmax)
	{
		int counter = size - 1; // номер хранилища, в котором находимся
		Node* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				current = new Node<T>(data, current, current->pBack);
				(current->pNext)->pBack = current;
				(current->pBack)->pNext = current;
				break;
			}
			current = current->pBack;
			counter--;
		}
		size++;
	}
}

template<typename T> 
void List2<T>::push_back(T data) // добавить в элемент в конец
{
	if (size > 1) // если более 1 хранилища
	{
		Node* temp = tail;
		tail = new Node(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (size == 1) // если 1 хранилще
	{
		tail = new Node(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else // если хранилищ нет
	{
		Node* p = new Node(data);
		head = p;
		tail = p;
	}
	size++;
}

template<typename T> 
T List2<T>::pop_front() // удалить элемент из начала
{
	Node* current = head;

	T data = head->data;

	head = current->pNext;

	delete current;

	if (size > 1)
		head->pBack = nullptr; // обнуляем указатель на пред. хранилище у головы
	else
		tail = head;  // обнуляем хвост, чтобы там не было мусора

	size--;

	return data;
}

template<typename T>  
void List2<T>::removeAT(int index) // удалить указанный элемент 
{
	int indexmax = size - 1, indexmin = 0, resmax = size - 1, resmin = 0; // крайние индексы данного массива
	resmax -= index;
	resmin += index;

	if (index == indexmin || index == indexmax)
	{
		if (index == indexmin)
			pop_front();
		else
			pop_back();
	}
	else if (resmin < resmax || resmin == resmax)
	{
		int counter = 0; // номер хранилища, в котором находимся
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				(current->pBack)->pNext = current->pNext;
				(current->pNext)->pBack = current->pBack;
				delete current;
				break;
			}
			current = current->pNext;
			counter++;
		}
		size--;
	}
	else if (resmin > resmax)
	{
		int counter = size - 1; // номер хранилища, в котором находимся
		Node* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				(current->pBack)->pNext = current->pNext;
				(current->pNext)->pBack = current->pBack;
				break;
			}
			current = current->pBack;
			counter--;
		}
		size--;
	}
}

template<typename T>
T List2<T>::pop_back() // удалить элемент из конца
{
	Node* current = tail;

	T data = tail->data;

	tail = current->pBack;

	delete current;

	if (size > 1)
		tail->pNext = nullptr; // обрубаем конец хвоста, т.е. указатель на след. хранилише
	else
		head = tail; // обнуляем голову, чтобы там не было мусора

	size--;

	return data;
}

template<typename T> 
void List2<T>::clear() // удалить все элементы
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T List2<T>::sel_el(const int index) const
{
	int indexmax = size - 1, indexmin = 0; // крайние индексы данного массива
	indexmax -= index; // мин. кол-во шагов, прежде чем добрать до хранилища из хвоста
	indexmin += index; // мин. кол-во шагов, прежде чем добрать до хранилища из головы

	if (indexmin < indexmax || indexmin == indexmax)
	{
		int counter = 0; // номер хранилища, в котором находимся
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else if (indexmin > indexmax)
	{
		int counter = size - 1; // номер хранилища, в котором находимся
		Node* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pBack;
			counter--;
		}
	}
}