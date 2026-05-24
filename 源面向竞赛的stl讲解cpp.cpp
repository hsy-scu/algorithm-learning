#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// vector变长数组（往后压进 往后删除）
// vector<类型> 数组名(元素个数，初始值)
// 访问方法 数组名[下标]  数组名.at(下标)
// 添加元素  数组名.push_back(元素)  通过此方法可以在数组末尾添加一个元素 实现扩容
// 创建空数组   vector<类型> 数组名   然后使用 数组名.resize(n) 就创建了一个大小为n的数组
// 数组.front() = 数组.v[0]  就是取出首元素
// 数组.back() =  数组.v[v.size()-1]   在使用这个函数之前一定保证v.size()>0 它是uint类型
// vector变长数组支持长度为变量


// stack 栈  （先进后出）
// stack<类型> 栈名sta;
// 进栈  sta.push(x)
// 出栈  sta.pop() 就是弹出最后一个进来的
//

