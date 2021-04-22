#pragma once

template <typename T>
class DequeBase
{
public:
	virtual int GetSize() const = 0; 
	virtual void PushFront(const T& element) = 0; 
	virtual T PopFront() = 0; 
	virtual void PushBack(const T& element) = 0; 
	virtual T PopBack() = 0; 
	virtual T PeekFront() const = 0; 
	virtual T PeekBack() const = 0; 
};