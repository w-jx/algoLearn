#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

常规想到的方法在push 元素val的时候
把栈s的所有元素push到栈stemp中
然后栈s 添加val
然后再把 栈 stemp的元素push到栈s中

题解的算法：
	输入栈压入 push数据，输出栈 用于pop和peek操作

*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outstack.empty())
            in2out();
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (outstack.empty())
            in2out();
        return outstack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return instack.empty() && outstack.empty();
    }
private:
    stack<int> instack;//分别定义输入输出栈
    stack<int> outstack;
    void in2out() {
        while (!instack.empty()) {
            outstack.push(instack.top());
            instack.pop();
        }
    }
};
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif