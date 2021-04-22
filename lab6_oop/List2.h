#pragma once

#include <iostream>

template<typename T>
class List2 // ����� ���������� ������
{
private:

	class Node // ����� ���������
	{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pBack = nullptr); // ����������� ���������

		Node* pNext, * pBack;
		T data;
	};

	Node* head; // ������ ������ ��������� 
	Node* tail; // ������ ����� ��������� 
	int size; // ���-�� ��������

public:

	List2(); // ����������

	~List2(); // ���������� 

	void push_front(T data); // �������� ������� � ������

	void insert(T data, int index); // �������� ������� � ��������� �����

	void push_back(T data); // �������� � ������� � �����

	T pop_front(); // ������� ������� �� ������

	void removeAT(int index); // ������� ��������� ������� 

	T pop_back(); // ������� ������� �� �����

	void clear(); // ������� ��� ��������

	int Getsize() { return size; } // ���-�� �������� 

	T sel_el(const int index) const; // ���������� ������� �� �������

};

template<typename T>
List2<T>::Node::Node(T data, Node* pNext, Node* pBack) : data(data), pNext(pNext), pBack(pBack)
{ }

template<typename T>
List2<T>::List2() : size(0), head(nullptr), tail(nullptr) // ����������� 
{ }

template<typename T>
List2<T>::~List2() 
{
	clear(); // �������� ���� ��������
}

template<typename T> 
void List2<T>::push_front(T data) // �������� ������� � ������
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
void List2<T>::insert(T data, int index) // �������� ������� � ��������� �����
{
	int indexmax = size - 1, indexmin = 0, resmax = size - 1, resmin = 0; // ������� ��������� ������� ������� �������
	resmax -= index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������
	resmin += index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������

	if (index == indexmin || index == indexmax)
	{
		if (index == indexmin)
		{
			push_front(data);
		} // ���� ������ ������� ���������, ��������� ����� �������� � ������
		else
		{
			push_back(data);
		} // ���� ������ ���������� ���������, ��������� ����� �������� � �����
	}
	else if (resmin < resmax || resmin == resmax)
	{
		int counter = 0; // ����� ���������, � ������� ���������
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				current = new Node<T>(data, current, current->pBack);
				(current->pNext)->pBack = current; // ������ �������� � ����. ��������� ��������� �� ����� ���������
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
		int counter = size - 1; // ����� ���������, � ������� ���������
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
void List2<T>::push_back(T data) // �������� � ������� � �����
{
	if (size > 1) // ���� ����� 1 ���������
	{
		Node* temp = tail;
		tail = new Node(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (size == 1) // ���� 1 ��������
	{
		tail = new Node(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else // ���� �������� ���
	{
		Node* p = new Node(data);
		head = p;
		tail = p;
	}
	size++;
}

template<typename T> 
T List2<T>::pop_front() // ������� ������� �� ������
{
	Node* current = head;

	T data = head->data;

	head = current->pNext;

	delete current;

	if (size > 1)
		head->pBack = nullptr; // �������� ��������� �� ����. ��������� � ������
	else
		tail = head;  // �������� �����, ����� ��� �� ���� ������

	size--;

	return data;
}

template<typename T>  
void List2<T>::removeAT(int index) // ������� ��������� ������� 
{
	int indexmax = size - 1, indexmin = 0, resmax = size - 1, resmin = 0; // ������� ������� ������� �������
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
		int counter = 0; // ����� ���������, � ������� ���������
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
		int counter = size - 1; // ����� ���������, � ������� ���������
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
T List2<T>::pop_back() // ������� ������� �� �����
{
	Node* current = tail;

	T data = tail->data;

	tail = current->pBack;

	delete current;

	if (size > 1)
		tail->pNext = nullptr; // �������� ����� ������, �.�. ��������� �� ����. ���������
	else
		head = tail; // �������� ������, ����� ��� �� ���� ������

	size--;

	return data;
}

template<typename T> 
void List2<T>::clear() // ������� ��� ��������
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T List2<T>::sel_el(const int index) const
{
	int indexmax = size - 1, indexmin = 0; // ������� ������� ������� �������
	indexmax -= index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������
	indexmin += index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������

	if (indexmin < indexmax || indexmin == indexmax)
	{
		int counter = 0; // ����� ���������, � ������� ���������
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
		int counter = size - 1; // ����� ���������, � ������� ���������
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