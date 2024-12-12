#include "Rail.h"
#include<algorithm>

Rail::Rail(int size) : n(size), count(0), maxLength(0), assistTrack() {
    mainTrack = new int[n];
    for (int i = 0; i < n; ++i) {
        mainTrack[i] = 0;
    }
}

Rail::~Rail()
{
    delete[] mainTrack;
}

//����������ȹ���
void Rail::printProcess()
{
    cout << "��ʼ����: ";
    for (int i = 0; i < n; ++i) {
        cout << mainTrack[i] << " ";
    }
    cout << endl;
    cout << "��ʼ���ȹ���..." << endl;
    bool result = dispatch();
    if (result) {
        cout << "���ȳɹ�!" << endl;
    }
    else {
        cout << "����ʧ��!" << endl;
    }
    cout << "��ջ��������: " << count << endl;
    cout << "������������: " << maxLength << endl;
    count = maxLength = 0;//���ñ���Ӱ���´�ͳ��
}

bool Rail::dispatch()
{
    int target = 1;
    for (int i = n-1; i >=0; --i) {
        if (mainTrack[i] == target) {
            cout << "���� " << target << " ����ȷλ�ã��ƶ�����һ����" << endl;
            ++target;
        }
        else {
            cout << "���� " << mainTrack[i] << " ˳��������븨�������" << endl;
            assistTrack.push(mainTrack[i]);
            ++count;
            maxLength = max(maxLength, assistTrack.getLength());
        }
        while (!assistTrack.isEmpty() && assistTrack.checkTop() == target) {
            cout << "������������ĳ��� " << assistTrack.checkTop() << " ����һ��˳�򣬵�����" << endl;
            assistTrack.pop();
            ++target;
            ++count;
        }
    }
    return target == n + 1;
}
//ֱ�ۻ�����
bool Rail::dispatchAuto(void (*visit)(Stack& origin, Stack& serve, Stack& array))
{
    assistTrack.clear();
    Stack origin(n, mainTrack);
    Stack array;
    int target = 1;
    for (int i = n-1; i>=0; --i) {
        if (mainTrack[i] == target) {
            array.push(origin.getTop());
            system("cls");
            visit(origin, assistTrack, array);
            Sleep(1000);
            ++target;
        }
        else {
            assistTrack.push(origin.getTop());
            system("cls");
            visit(origin, assistTrack, array);
            Sleep(1000);
            ++count;
            maxLength = max(maxLength, assistTrack.getLength());
        }
        while (!assistTrack.isEmpty() && assistTrack.checkTop() == target) {
            array.push(assistTrack.getTop());
            system("cls");
            visit(origin, assistTrack, array);
            Sleep(1000);
            ++target;
            ++count;
        }
    }

    return target == n + 1;
}


//���ó�ʼ���� 
void Rail::setInitialSequence(const int* sequence)
{
    count = maxLength = 0;
    for (int i = 0; i < n; ++i) {
        mainTrack[i] = sequence[i];
    }
}
