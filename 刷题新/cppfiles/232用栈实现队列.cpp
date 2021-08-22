#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

�����뵽�ķ�����push Ԫ��val��ʱ��
��ջs������Ԫ��push��ջstemp��
Ȼ��ջs ���val
Ȼ���ٰ� ջ stemp��Ԫ��push��ջs��

�����㷨��
	����ջѹ�� push���ݣ����ջ ����pop��peek����

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
    stack<int> instack;//�ֱ����������ջ
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