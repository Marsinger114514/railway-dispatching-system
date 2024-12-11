

#include <iostream>
#include<conio.h>
#include"Rand.h"
#include"Stack.h"
#include"Rail.h"
#include"Assistant.h"
#include<Windows.h>
#include<WinBase.h>
using namespace std;

//缓冲区清除
static void clearcin() {
    std::cin.clear(); // 清除错误状态
    rewind(stdin);		//防止多输入从而影响其它测试进程。
}
int main()
{   
    char x;
    int a[5]={2,1,3,5,4};
    Rail r(5);
    r.setInitialSequence(a);
    char c='1';
    while (c != '0') {
        clearcin();
        cout << "1. 启动调度原理演示." << endl;
        cout << "2. 启动随机调度测试." << endl;
        cout << "3. 启动手动调度测试." << endl;
        cin >> c;
        clearcin();
        switch (c) {
        case '1': {
            cout << "序列21354成功示范" << endl;
            r.printProcess();
            cout << "按任意键启动过程模拟" << endl;
            char gogogo=_getch();
            r.dispatchAuto(show);
            break;
        }
        case '2':
            break;
        case '3':
            break;
        default:
            break;
        }
    }

}
//目前执行操作需要先建立一个Rail的对象，初始化参数为轨道的长度，即初始车厢数
//建立完对象后通过setInitialSequence函数对初始车厢顺序进行赋值
//createSituation函数为外部函数，功能是随机生成乱序的车厢顺序，参数为长度
//printProcess函数为Rail类的成员函数 功能为文字输出调动操作以及调动次数，辅助轨道长度等参数
//dispatchAuto函数为逐帧输出调动过程，参数为每一帧创建逻辑的函数指针

