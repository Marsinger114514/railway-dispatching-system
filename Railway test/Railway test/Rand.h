#pragma once
#include <random>
#ifndef RAND
//随机生成包含1~size连续自然数的乱序数组
int* createSituation(int size);
//随机生成长度为1~size的必定能完成调动的乱序数组
int* createCertainSituation(int size);
#endif // !RAND


