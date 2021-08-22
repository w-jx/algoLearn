#if 0
#include "../headers/wjxHeaders.h"
/*
�������
ϸ��:
����next��m_data����Ҫ����Ϊ��������
*/
void printint(int val) {
	cout << val << " ";
}
bool cmpint(int val1, int val2) {
	return val1 == val2;
}
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
	void printnode(printcallback print= printint) {
		MyNode<T>* cur = &(this->dummy);
		cur = cur->next;
		while (cur != &(this->dummy)) {
			print(cur->m_data);
			cur = cur->next;
		}
		cout << endl;
	}
	//ɾ�������еĽ��
	bool remove(T data, cmpcallback cmp=cmpint) {
		//������û�� �������
		if (this->dummy.next == &(this->dummy))
			return false;
		MyNode<T>* cur = &(this->dummy);
		
		while (cur->next != &(this->dummy)) {
			
			if (cmp(cur->next->m_data,data)) {
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
	int m_size;
	MyNode<T> dummy;//����ͷ���
};
class Person {
public:
	Person() {
		_age = 0;
		_name = string();
	}
	Person(int age, string name) :_age(age),_name(name){}
	int age()const {
		return this->_age;
	}
	string name()const {
		return this->_name;
	}

private:
	int _age;
	string _name;
};
void printPerson(Person p) {
	cout << p.age() << "," << p.name() << endl;
}
bool cmpPerson(Person p1, Person p2) {
	return p1.age() == p2.age() && p1.name() == p2.name();
}
//���������
void test01()
{
	Clist<int> mylist;
	mylist.add(10);
	mylist.add(20);
	mylist.add(30);

	mylist.printnode();



	Person p1(20, "wjx");
	Person p2(21, "zj");
	Person p3(22, "sl");
	Clist<Person> mylist2;
	mylist2.add(p1);
	mylist2.add(p2);
	mylist2.add(p3);
	mylist2.printnode(printPerson);
	mylist2.remove(p1, cmpPerson);
	mylist2.printnode(printPerson);
	


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
