#if 0
#include <iostream>
using namespace std;
/*
leecode题目介绍:
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。

2021.3.13:做的时候总是分不清指针的指向，所以要先测试下
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	Solution(int firstNodeValue) {
		this->head = new ListNode(firstNodeValue);
	}
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode* pNext = node->next;
		node->next = node->next->next;
		delete pNext;

	}
	void printNode()
	{
		while (head != NULL) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

	void push(int val)
	{
		if (head == NULL)
			return;
		ListNode* pHead = head;
		while (pHead->next != NULL) {
			pHead = pHead->next;
		}
		ListNode* pNew = new ListNode(val);
		pHead->next = pNew;
	}
	ListNode* head;
};
void foreachNode(ListNode* head) {
	if (!head) return;
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
//题解答案
ListNode* deleteNode(ListNode* head, int val) {
	/*
	4		5		1		9
	pre		cur		cur->next        待删除的是5
	pre->next=cur->next; 就删除了5
	特殊情况：
	1.删除节点是头节点，直接返回head->next
	2.初始化：pre=head,cur=head->next
	3.定位节点 
		跳出：cur为空的时候或cur的节点的值等于val的时候
		1.保存当前节点索引，pre=cur
		2.遍历cur=cur->next;
	4.删除节点
	5.返回链表头节点
	*/
	if (!head) return nullptr;
	if (head->val == val) return head->next;

	auto pre = head, cur = head->next;
	while (cur) {

		if (cur->val == val) {
			pre->next = cur->next;
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	return head;


	
	


	
}
void test01()
{
	Solution s(0);
	s.push(1);
	s.push(2);
	s.push(3);

	s.printNode();
	ListNode* pDel = new ListNode(2);
	pDel->next = new ListNode(3);
	pDel->next->next = NULL;
	s.deleteNode(pDel);
	s.printNode();
}
void test02()
{
	//因为做的时候总是分不清指针的指向，所以测试下2021,3,13


	ListNode* node = new ListNode(0);//有一个0的结点
	node->next = new ListNode(1);
	node->next->next = new ListNode(2);

#if 0
	//情景1，对node2的next指针的修改，会反映到node上，下面的遍历 只会输出0，2
	ListNode* node2 = node;//相当于是个拷贝

	node2->next = node2->next->next;

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}

#endif 

#if 0
	//情景2：对node2本身指向的修改，并没有同步到node上，遍历输出是还是0，1，2
	ListNode* node2 = node;//node2指向了是node

	node2 = node2->next->next;//相当于是将node2的指向 指向了别的地方，并不影响原来指向内容的值

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}

#endif

#if 0
	//情景3：对node2本身值的修改，同步到node上了，输出结果是10，1，2
	ListNode* node2 = node;//node2指向了是node

	node2->val = node2->val+10;

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}

#endif

#if 0
	//情景4：对node本身值的修改，不会同步到node2上，因为node2就相当于是原来的拷贝，有原来的所有信息
	ListNode* node2 = node;//node2指向了是node
	/*
	相当于：
	node2->val = node->val;
	node2->next= node->next;
	*/
	
	
	node = node->next;

	while (node2) {
		cout << node2->val << " ";
		node2 = node2->next;
	}
	cout << endl;

#endif
#if 0
	//情景5：node之前的结点。不影响node,因为beforeNode->next指向了 head，我们修改
	//beforeNode->next 不会影响node本身。相当于情景2
	ListNode* beforeNode = new ListNode(-1);//node2指向了是node
	beforeNode->next = node;

	beforeNode->next = beforeNode->next->next; //

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}

#endif

#if 0
	//情景6：node之前的结点。如果我们修改了node，仍然可以用beforeNode访问到
	
	ListNode* beforeNode = new ListNode(-1);//node2指向了是node
	beforeNode->next = node;

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
	if (beforeNode->next == nullptr)
		cout << "next is nullptr\n";
	else
		cout << "node is not nullptr:"<<beforeNode->next->val << endl;
	while (beforeNode->next) {
		cout << beforeNode->next->val << " ";
		beforeNode->next = beforeNode->next->next;
	}//仍然输出0 ，1 ，2
	cout << endl;

#endif

#if 1 //注意和情景4的区别
	int* a = new int(5);
	int* b = a;

	*a = 100;
	cout << *b << endl;//对a的修改，同步到了b上

	*b = 200;
	cout << *a << endl;//对b的修改，也同步到了a上

	delete a, b;

#endif
}
void test03()
{
	ListNode *node =new ListNode(4);
	node->next = new ListNode(5);
	node->next->next = new ListNode(1);
	node->next->next->next = new ListNode(9);

	auto nodres = deleteNode(node, 5);
	foreachNode(nodres);
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
#endif