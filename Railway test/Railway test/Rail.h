#pragma once
#include"Stack.h"
#include"Rand.h"





class Rail {
private:
    Stack assistTrack;
    int* mainTrack;
    int n;
    int count;
    int maxLength;
public:
    Rail(int size);
    ~Rail();
    //����������ȹ���
    void printProcess();
    bool dispatch();
    //ֱ�ۻ�����
    bool dispatchAuto(void (*visit)(Stack& origin, Stack& serve, Stack& array));  //
    //����һ����ʼ���������
    void setInitialSequence(const int* sequence);
};
