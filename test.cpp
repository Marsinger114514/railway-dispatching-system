#include <iostream>
#include "Stack.h"
#include "Rail.h"
using namespace std;

int main() {
    try {
        int choice;
        do {
            cout << "1. 手动输入顺序\n";
            cout << "2. 随机测试 n=100\n";
            cout << "3. 离开\n";
            cout << "选择一项: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int n;
                cout << "输入车厢数: ";
                cin >> n;
                Rail system(n);
                int* sequence = new int[n];
                cout << "输入出站顺序: ";
                for (int i = 0; i < n; ++i) {
                    cin >> sequence[i];
                }
                system.setInitialSequence(sequence);
                system.printProcess();
                delete[] sequence; // 释放内存
                break;
            }
            case 2: {
                break;
            }
            case 3:
                cout << "退出程序." << endl;
                break;
            default:
                cout << "无效选择." << endl;
            }
        } while (choice != 3);
    }
    catch (const std::exception& e) {
        cerr << "发生异常: " << e.what() << endl;
    }
    return 0;
}
