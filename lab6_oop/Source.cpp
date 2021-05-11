#include <iostream>
#include "DequeBase.h"
#include "Deque.h"
#include "Deque2.h"

using namespace std;

template<typename T>
void MyFuncWithPointer(DequeBase<T>* s)
{
	cout << s->PeekFront() << endl;
	cout << s->PeekBack() << endl;
}

template<typename T>
void MyFuncWithReference(DequeBase<T>& s)
{
	cout << s.PeekFront() << endl;
	cout << s.PeekBack() << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Deque<int> d1;
	d1.PushFront(4);
	d1.PushBack(1);
	d1.PushFront(11);
	d1.PushBack(7);
	d1.PushBack(2);

	cout << d1;

	cout << "������ ������� c ������: " << d1.PeekFront() << "; ������ ������� � �����: " << d1.PeekBack() << ";  ����� ���������: " << d1.GetSize() << endl;

	Deque2<int> d2;
	d2.PushFront(4);
	d2.PushBack(1);
	d2.PushFront(11);
	d2.PushBack(7);
	d2.PushBack(2);

	cout << d2;

	cout << "������ ������� c ������: " << d2.PeekFront() << "; ������ ������� ������ : " << d2.PeekBack() << ";  ����� ���������: " << d2.GetSize() << endl;

	cout << endl;
	cout << "����� ������� � ���������� ���������" << endl;
	cout << "�������� �� ������ �������" << endl;
	MyFuncWithPointer(&d1);
	cout << "�������� �� ������ �������" << endl;
	MyFuncWithPointer(&d2);

	cout << endl;
	cout << "����� ������� � ���������� ������" << endl;
	cout << "�������� �� ������ �������" << endl;
	MyFuncWithReference(d1);
	cout << "�������� �� ������ �������" << endl;
	MyFuncWithReference(d2);

	return 0;
}