#pragma once
/*
��ѭ������,�ܸ�����
 */

#include <iostream>
using namespace std;

void printint(int val) {
	cout << val << " ";
}
bool cmpint(int val1, int val2) {
	return val1 == val2;
}

//��ѭ������
template<class T>
class Clist {
public:
	using printcallback = void(T data);//��ӡ�ص�
	using cmpcallback = bool(T data1, T data2);//�Ƚϻص�
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
	//ɾ�������еĽ��
	bool remove(T data, cmpcallback cmp = cmpint) {
		//������û�� �������
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
	//��ѭ������Ľ��
	template<class T>
	class MyNode {
	public:
		MyNode() {
			m_data = T();
			next = nullptr;
		}
		MyNode(T data) :m_data(data), next(nullptr) {}
		MyNode<T>* next;//���������Ա����ǹ���,��Ȼ���������޷����ʽ��
		T m_data;

	};
	int m_size;
	MyNode<T> dummy;//����ͷ���
};