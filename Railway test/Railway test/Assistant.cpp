#include "Assistant.h"
#include"Stack.h"
void wirte(int a)
{
    cout << a << ' ';
}

void show(Stack& origin, Stack& serve, Stack& array)
{
    cout << "��߹��:";
    origin.Traverse(wirte);
    cout << endl;
    cout << "�������:";
    serve.Traverse(wirte);
    cout << endl;
    cout << "�ұ߹��:";
    array.Traverse(wirte);
    cout << endl;
}
