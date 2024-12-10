#ifndef RAIL_H
#define RAIL_H

#include <iostream>
#include "Stack.h"

using namespace std;

class Rail {
private:
    Stack assistTrack;
    int* mainTrack;
    int n;
    int count;
    int maxLength;

public:
    Rail(int size) : n(size), count(0), maxLength(0), assistTrack(size) {
        mainTrack = new int[n];
        for (int i = 0; i < n; ++i) {
            mainTrack[i] = 0;
        }
    }

    ~Rail() {
        delete[] mainTrack;
    }

    void printProcess() {
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

    bool dispatch() {
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
                maxLength = max(maxLength, assistTrack.size());
            }
            while (!assistTrack.empty() && assistTrack.top() == target) {
                cout << "辅助轨道顶部的车厢 " << assistTrack.top() << " 是下一个顺序，弹出。" << endl;
                assistTrack.pop();
                ++target;
                ++count;
            }
        }
        return target == n + 1;
    }


    void setInitialSequence(const int* sequence) {
        for (int i = 0; i < n; ++i) {
            mainTrack[i] = sequence[i];
        }
    }
};

#endif
