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
    }

    bool dispatch() {
        int target = 1;
        for (int i = 0; i < n; ++i) {
            if (mainTrack[i] == target) {
                cout << "���� " << target << " ����ȷλ�ã��ƶ�����һ����" << endl;
                ++target;
            }
            else {
                cout << "���� " << mainTrack[i] << " ˳��������븨�������" << endl;
                assistTrack.push(mainTrack[i]);
                ++count;
                maxLength = max(maxLength, assistTrack.size());
            }
            while (!assistTrack.empty() && assistTrack.top() == target) {
                cout << "������������ĳ��� " << assistTrack.top() << " ����һ��˳�򣬵�����" << endl;
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
