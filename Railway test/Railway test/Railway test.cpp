

#include <iostream>
#include"Rand.h"
#include"Stack.h"
#include"Rail.h"
#include"Assistant.h"
using namespace std;
int main()
{
    char x;
    int* a = createSituation(5);
    Rail r(5);
    r.setInitialSequence(a);
    r.printProcess();
    cout << "输入数字继续" << endl;
    cin>>x;
    r.dispatchAuto(show);
}
//目前执行操作需要先建立一个Rail的对象，初始化参数为轨道的长度，即初始车厢数
//建立完对象后通过setInitialSequence函数对初始车厢顺序进行赋值
//createSituation函数为外部函数，功能是随机生成乱序的车厢顺序，参数为长度
//printProcess函数为Rail类的成员函数 功能为文字输出调动操作以及调动次数，辅助轨道长度等参数
//dispatchAuto函数为逐帧输出调动过程，参数为每一帧创建逻辑的函数指针

