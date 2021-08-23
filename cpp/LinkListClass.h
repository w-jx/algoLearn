#ifndef LINKLISTCLASS_H
#define LINKLISTCLASS_H

//结点类
template <class T>
class MyListNode
{
public:
	//LinkNode() {
	//	this->next = NULL;
	//	this->data = NULL;
	//}
	MyListNode<T>* next;
	T m_data;
};

//链表类
template<class T>
class LinkList
{
public:
	LinkList() {//初始化
		this->m_Size = 0;
		this->head = new MyListNode<T>;//大坑,<T>不加死活不行
		this->head->m_data = NULL;
		this->head->next = NULL;
	}
	
	void insert(int pos, T value);
	void remove(int pos);
	MyListNode<T>* removeNthFromEnd(int n);//删除倒数第n个结点,并返回链表的头结点 leecode 19
	int find(T value);
	void clear();
	int size();

	
	MyListNode<T>* front();

//属性
	MyListNode<T>* head;//头结点不保存信息
	int m_Size;

//内部类可以访问外部类的私有成员，外部类不能访问内部类的私有成员！

};




template<class T>
inline void LinkList<T>::insert(int pos, T value)
{
	if (pos < 0 || pos >= this->m_Size)
		pos = this->m_Size;
	
	MyListNode<T>* newNode = new MyListNode<T>;//创建新结点
	newNode->m_data = value;
	newNode->next = NULL;
	
	MyListNode<T>* pCurrent = this->head;//临时变量
	
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	/*
	* 如果new LinkNode<T>不加<T>
	C2955	“LinkNode”: 使用 类 模板 需要 模板 参数列表
	C2512	“LinkNode”: 没有合适的默认构造函数可用
	*/
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	this->m_Size++;

}


template<class T>
inline void LinkList<T>::remove(int pos)
{
	if (pos<0 || pos>=this->m_Size)
		return;
	
	MyListNode<T>* pCurrent = this->head;//临时变量
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pCurrent->next->next;
	this->m_Size--;
}

template<class T>
inline MyListNode<T>* LinkList<T>::removeNthFromEnd(int n)
{
	return NULL;
}

template<class T>
inline int LinkList<T>::find(T value)
{
	MyListNode<T>* pCurrent = this->head->next;//下一个才是真正的值
	int pos = 0;
	while (pCurrent != NULL) {
		if (pCurrent->m_data == value) {
			return pos;
		}
		pos++;
		pCurrent = pCurrent->next;
			
	}

	return -1;
}

template<class T>
inline void LinkList<T>::clear()
{
	this->head->next = NULL;
	this->head->m_data = 0;
	this->m_Size = 0;
}

template<class T>
inline int LinkList<T>::size()
{
	return this->m_Size;
}





template<class T>
inline MyListNode<T>* LinkList<T>::front()
{
	return this->head->next;
}


#endif // !LINKLISTCLASS_H



