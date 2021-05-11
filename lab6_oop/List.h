#pragma once
#include <iostream>

template<typename T>
class List // ����� ����������� ������
{
private:

	class Node // ����� ���������
	{
	public:
		Node(T data = T(), Node* pNext = nullptr); // �����������

		Node* pNext; // ���������� ������
		T data; // ���������� ������
	};

	int size; // ���-�� ��
	Node* head; // ��������� �� ������ ������
	Node* tail; // ��������� �� ����� ������

public:

	List(); // �����������

	List(const List& other);

	List(const List&& other);

	~List(); // ����������

	void push_front(const T& data); // ��������� ������� � ������

	void push_back(const T& data); //��������� ������� � �����

	T pop_front(); // ������� ����� ������ �������

	T removeAT(const int index); // ������� ������� � ����������� �����

	T pop_back(); // ������� ��������� �������

	void clear(); // ������� ��� ��������

	int getsize() const; // �������� ���-�� ��

	T& sel_el(const int index) const; // ���������� ������� �� �������

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
	if (head == nullptr) // ���� ��� ��� �� ������ ���������
	{
		Node* p = new Node(data);// ������ ������ ���������
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
	if (head == nullptr) // ���� ��� ��� �� ������ ���������
	{
		head = tail = new Node(data); // ������ ������ ���������
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
	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������!" << std::endl;
		return T();
	}
	else if (index == 0) // ���� ������ 0, �� ���������� ��� ������� �������
	{
		return pop_front();
	}
	else
	{
		Node* previous = this->head;  // �������� ��� ��������� ��������� � ������ ���� ���������� (this ���������)

		for (int i = 0; i < index - 1; i++) //���� ���������, ������� ����� �� ���� ���������, ������� �� ����� �������
		{
			previous = previous->pNext;

		}
		Node* toDelete = previous->pNext; // ������ ��������� �� ���������, ������� �� ����� �������

		if (toDelete->pNext == nullptr)
			tail = previous;

		previous->pNext = toDelete->pNext; // �� ����� ���������, ������� ����� ������� ������ ��������� ��������
		T data = toDelete->data;
		delete toDelete; // ������� ���������, �� ������� �������
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
	while (size) // ���� �� ����� 0
	{
		pop_front();
	}
}

template<typename T>
int List<T>::getsize() const { return size; }

template<typename T>
T& List<T>::sel_el(const int index) const
{
	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������! ��������� ����������� ���������!" << std::endl;
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