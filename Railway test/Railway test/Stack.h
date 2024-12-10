#pragma once
#include<iostream>
#include<windows.h>
using namespace std;

#define SIZE 64
using namespace std;




class Stack
{
private:
	int size;//栈中存储数量
	int* num;//存储的数组
	int maxSize;//存储容量

private:
	void resize();//（内部调用）将存储容量扩大到两倍

public:
	Stack();
	Stack(int _size, int array[]);
	~Stack();

public:
	void push(int next);//压栈操作
	void pop();//出栈操作
	int checkTop();//查看栈顶数值
	int getTop();//获取栈顶数值并出栈
	int getLength();//获取存储长度
	bool isEmpty();//检测栈是否为空
	void clear();//清除存储
	void Traverse(void (*visit)(int a));//遍历操作



};

