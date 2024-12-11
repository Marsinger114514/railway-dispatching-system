#include "Rand.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;
//生成一个随机int型
static int UniformRand_int(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    double result = dist(gen);
    return result;
}
//生成10位随机数作为打乱种子
static int seed()
{
    int seed = 0;
    for (int i = 0; i < 10; i++)
    {
        seed *= 10;
        seed += UniformRand_int(0, 10);
    }
    if (seed < 0)
        return -seed;
    return seed;
}
int* createSituation(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
    int key = seed();
    while (key != 0) {
        int step = key % 10;
        key /= 10;
        for (int i = 0; i < size; i++)
        {
            int temp = array[i];
            array[i] = array[(i * step) % size];
            array[(i * step) % size] = temp;
        }
    }
    return array;
}