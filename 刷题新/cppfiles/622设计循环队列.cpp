#if 0
#include "../headers/wjxHeaders.h"
/*
微软面试

队尾 = (队头_+队列的长度-1) mod 数组长度



*/
//2021年5月25日 不会写
class MyCircularQueue {
private:
    vector<int> data;//固定大小的数组
    int head;//队首
    int tail;//队尾
    int capacity;//循环队列的容量,也就是最大能容量的元素数量.
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        capacity = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    //入队,如果插入成功,返回true否则返回false
    bool enQueue(int value) {
        if (isFull()) {//已经满了,肯定无法插入
            return false;
        }
        if (isEmpty()) {//当前队列为空,队头处在位置0处
            head = 0;
        }
        tail = (tail + 1) % capacity;//进行插入
        data[tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    //出队,如果出队成功,返回true,否则返回false
    bool deQueue() {
        if (isEmpty()) {//队列此时已经是空的,别出队了
            return false;
        }
        if (head == tail) {//队头和队尾一样的时候,队列只有1个元素,再删除的时候,就是回到初始状态
            head = -1;
            tail = -1;
            return true;
        }
        //出队就是让队头指针前进,下一次访问队头就变成前面一个了
        head = (head + 1) % capacity;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {//队伍为空,返回-1
            return -1;
        }
        return data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        //
        return ((tail + 1) % capacity) == head;
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