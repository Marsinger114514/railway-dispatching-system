#include <iostream>
#include "Stack.h"
#include "Rail.h"
using namespace std;

int main() {
    try {
        int choice;
        do {
            cout << "1. �ֶ�����˳��\n";
            cout << "2. ������� n=100\n";
            cout << "3. �뿪\n";
            cout << "ѡ��һ��: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int n;
                cout << "���복����: ";
                cin >> n;
                Rail system(n);
                int* sequence = new int[n];
                cout << "�����վ˳��: ";
                for (int i = 0; i < n; ++i) {
                    cin >> sequence[i];
                }
                system.setInitialSequence(sequence);
                system.printProcess();
                delete[] sequence; // �ͷ��ڴ�
                break;
            }
            case 2: {
                break;
            }
            case 3:
                cout << "�˳�����." << endl;
                break;
            default:
                cout << "��Чѡ��." << endl;
            }
        } while (choice != 3);
    }
    catch (const std::exception& e) {
        cerr << "�����쳣: " << e.what() << endl;
    }
    return 0;
}
