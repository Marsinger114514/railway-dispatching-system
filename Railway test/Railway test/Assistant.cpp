#include "Assistant.h"
#include"Stack.h"
void wirte(int a)
{
    cout << a << ' ';
}

void show(Stack& origin, Stack& serve, Stack& array)
{
    cout << "左边轨道(序列右边为出口):";
    origin.Traverse(wirte);
    cout << endl;
    cout << "辅助轨道(序列左代表栈顶为出/入口):";
    serve.Traverse(wirte);
    cout << endl;
    cout << "右边轨道(序列左边为入口):";
    array.Traverse(wirte);
    cout << endl;
}
