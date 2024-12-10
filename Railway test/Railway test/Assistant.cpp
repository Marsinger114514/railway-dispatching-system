#include "Assistant.h"
#include"Stack.h"
void wirte(int a)
{
    cout << a << ' ';
}

void show(Stack& origin, Stack& serve, Stack& array)
{
    cout << "×ó±ß¹ìµÀ:";
    origin.Traverse(wirte);
    cout << endl;
    cout << "¸¨Öú¹ìµÀ:";
    serve.Traverse(wirte);
    cout << endl;
    cout << "ÓÒ±ß¹ìµÀ:";
    array.Traverse(wirte);
    cout << endl;
}
