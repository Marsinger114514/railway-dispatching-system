#pragma once
#include<iostream>
#include<windows.h>
using namespace std;

#define SIZE 64
using namespace std;




class Stack
{
private:
	int size;//ջ�д洢����
	int* num;//�洢������
	int maxSize;//�洢����

private:
	void resize();//���ڲ����ã����洢������������

public:
	Stack();
	Stack(int _size, int array[]);
	~Stack();

public:
	void push(int next);//ѹջ����
	void pop();//��ջ����
	int checkTop();//�鿴ջ����ֵ
	int getTop();//��ȡջ����ֵ����ջ
	int getLength();//��ȡ�洢����
	bool isEmpty();//���ջ�Ƿ�Ϊ��
	void clear();//����洢
	void Traverse(void (*visit)(int a));//��������



};

