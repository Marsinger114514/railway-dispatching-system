#include "Assistant.h"
#include"Stack.h"
void wirte(int a)
{
    cout << a << ' ';
}

void show(Stack& origin, Stack& serve, Stack& array)
{
    cout << "��߹��(�����ұ�Ϊ����):";
    origin.Traverse(wirte);
    cout << endl;
    cout << "�������(���������ջ��Ϊ��/���):";
    serve.Traverse(wirte);
    cout << endl;
    cout << "�ұ߹��(�������Ϊ���):";
    array.Traverse(wirte);
    cout << endl;
}
