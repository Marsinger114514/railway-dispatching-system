#include "Stack.h"

void Stack::resize()
{
	int* temp = new int[maxSize * 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = num[i];
	}
	maxSize *= 2;
	num = temp;
}

Stack::Stack()
{
	maxSize = SIZE;
	size = 0;
	num = new int[SIZE];
}

Stack::Stack(int _size, int array[])
{
	maxSize = SIZE;
	size = _size;
	num = new int[SIZE];
	while (_size>maxSize)
	{
		resize();
	}
	for (int i = 0; i < size; i++)
	{
		num[i] = array[i];
	}
}

Stack::~Stack()
{
	delete []num;
}

void Stack::push(int next)
{
	size += 1;
	if (size> maxSize)
		resize();
	num[size - 1] = next;

}

void Stack::pop()
{
	if (size > 0)
		size -= 1;
	else
		size = 0;
}

int Stack::checkTop()
{
	if(!isEmpty())
		return num[size-1];
	return -1;
}

int Stack::getTop()
{
	if (isEmpty())
		return -1;
	else
	{
		int temp = checkTop();
		pop();

		return temp;
	}
	
}

int Stack::getLength()
{
	return size;
}

bool Stack::isEmpty()
{
	if (size == 0)
		return true;

	return false;
}

void Stack::clear()
{
	size = 0;
}

void Stack::Traverse(void (*visit)(int a))
{
	for (int i = size-1; i>=0; i--)
		visit(num[i]);
}
