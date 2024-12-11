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
    //文字输出调度过程
    void printProcess();
    bool dispatch();
    //直观化调度
    bool dispatchAuto(void (*visit)(Stack& origin, Stack& serve, Stack& array));  //
    //设置一个初始随机化序列
    void setInitialSequence(const int* sequence);
};
