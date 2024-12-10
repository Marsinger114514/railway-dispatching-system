#pragma once
#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
class Stack {
private:
    int* data;
    int MaxIndex;
    int topIndex;

public:
    Stack(int size) : MaxIndex(size), topIndex(-1) {
        data = new int[MaxIndex];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (topIndex < MaxIndex - 1) {
            data[++topIndex] = value;
        }
        else {
            throw runtime_error("ջ���");
        }
    }

    int pop() {
        if (topIndex >= 0) {
            return data[topIndex--];
        }
        else {
            throw runtime_error("��ջ����");
        }
    }

    bool empty() const {
        return topIndex == -1;
    }

    //ȡ��ջ��
    int top() const {
        if (topIndex >= 0) {
            return data[topIndex];
        }
        else {
            throw runtime_error("ջΪ��");
        }
    }

    //��ȡ����
    int size() const {
        return topIndex + 1;
    }
};

#endif 