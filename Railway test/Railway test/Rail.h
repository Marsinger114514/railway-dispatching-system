#pragma once
#include"LinkStackC.h"
#include"Rand.h"





class Rail {
private:
    LinkStackC assistTrack;
    int* mainTrack;
    int n;
    int count;
    int maxLength;
public:
    Rail(int size);
    ~Rail();
    void printProcess();
    bool dispatch();
    bool dispatchAuto(void (*visit)(LinkStackC& origin, LinkStackC& serve, LinkStackC& array));
    void setInitialSequence(const int* sequence);
};
