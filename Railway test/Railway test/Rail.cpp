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

void Rail::printProcess()
{
    cout << "初始序列: ";
    for (int i = 0; i < n; ++i) {
        cout << mainTrack[i] << " ";
    }
    cout << endl;
    cout << "开始调度过程..." << endl;
    bool result = dispatch();
    if (result) {
        cout << "调度成功!" << endl;
    }
    else {
        cout << "调度失败!" << endl;
    }
    cout << "总栈操作次数: " << count << endl;
    cout << "最大辅助轨道长度: " << maxLength << endl;
}

bool Rail::dispatch()
{
    int target = 1;
    for (int i = 0; i < n; ++i) {
        if (mainTrack[i] == target) {
            cout << "车厢 " << target << " 在正确位置，移动到下一个。" << endl;
            ++target;
        }
        else {
            cout << "车厢 " << mainTrack[i] << " 顺序错误，推入辅助轨道。" << endl;
            assistTrack.push(mainTrack[i]);
            ++count;
            maxLength = max(maxLength, assistTrack.getLength());
        }
        while (!assistTrack.isEmpty() && assistTrack.checkTop() == target) {
            cout << "辅助轨道顶部的车厢 " << assistTrack.checkTop() << " 是下一个顺序，弹出。" << endl;
            assistTrack.pop();
            ++target;
            ++count;
        }
    }
    return target == n + 1;
}

bool Rail::dispatchAuto(void (*visit)(LinkStackC& origin, LinkStackC& serve, LinkStackC& array))
{
    LinkStackC origin(n, mainTrack);
    LinkStackC array;
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



void Rail::setInitialSequence(const int* sequence)
{
    for (int i = 0; i < n; ++i) {
        mainTrack[i] = sequence[i];
    }
}
