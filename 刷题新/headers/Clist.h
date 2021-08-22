#pragma once
/*
单循环链表,很给力的
 */

#include <iostream>
using namespace std;

void printint(int val) {
	cout << val << " ";
}
bool cmpint(int val1, int val2) {
	return val1 == val2;
}

//单循环链表
template<class T>
class Clist {
public:
	using printcallback = void(T data);//打印回调
	using cmpcallback = bool(T data1, T data2);//比较回调
	Clist() {
		this->m_size = 0;
		this->dummy.next = &(this->dummy);
	}
	void add(T data) {
		MyNode<T>* newnode = new MyNode<T>(data);
		MyNode<T>* cur = &(this->dummy);

		while (cur->next != &(this->dummy)) {
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->next = &(this->dummy);
		this->m_size++;
	}
	void printnode(printcallback print = printint) {
		MyNode<T>* cur = &(this->dummy);
		cur = cur->next;
		while (cur != &(this->dummy)) {
			print(cur->m_data);
			cur = cur->next;
		}
		cout << endl;
	}
	//删除链表中的结点
	bool remove(T data, cmpcallback cmp = cmpint) {
		//链表中没有 其他结点
		if (this->dummy.next == &(this->dummy))
			return false;
		MyNode<T>* cur = &(this->dummy);

		while (cur->next != &(this->dummy)) {

			if (cmp(cur->next->m_data, data)) {
				auto pdel = cur->next;
				cur->next = cur->next->next;
				delete pdel;
				return true;
			}
			cur = cur->next;
		}
		return false;
	}

private:
	//单循环链表的结点
	template<class T>
	class MyNode {
	public:
		MyNode() {
			m_data = T();
			next = nullptr;
		}
		MyNode(T data) :m_data(data), next(nullptr) {}
		MyNode<T>* next;//这两个属性必须是公共,不然在链表中无法访问结点
		T m_data;

	};
	int m_size;
	MyNode<T> dummy;//虚拟头结点
};