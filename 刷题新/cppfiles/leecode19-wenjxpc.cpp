#include <iostream>
#include <string>
using namespace std;

int m=0;
int a = 0;

typedef struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
void dele(ListNode* x);
//递归方法写的版本
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	m = n;
	if (head == NULL) return NULL;
	ListNode* be_head = new ListNode(0);
	be_head->next = head;
	dele(be_head);
	return be_head->next;
}
//我自己的思路写的版本
ListNode* removeNthFromEnd1(ListNode* head, int n)
{
	ListNode* be_head = new ListNode(0);//首先准备一个结点be_head指向头节点
	be_head->next = head;//不能直接操作头节点
	ListNode* pcurrent = be_head;//

	int m_Size = 0;
	while (pcurrent != NULL) {
		m_Size++;
		pcurrent = pcurrent->next;
	}//这个size相比较真正的size多了一个,因为pcurrent一开始指向be_head

	int len = m_Size - n-1;
	pcurrent = be_head;

	for (int i = 0; i < len ; i++) {

		pcurrent = pcurrent->next;//指向倒数第n个结点的前一个结点
	}
	pcurrent->next = pcurrent->next->next;

	return be_head->next;
}
void dele(ListNode* x)
{
	if (x != NULL) {
		dele(x->next);
	}
	a++;
	if (a == m + 2)
		x->next = x->next->next;
}

void printList(ListNode* head)
{
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
void outputList(ListNode* head)
{
	if (head != NULL) {
		cout << head->val << " ";
		outputList(head->next);
	}
}
void test01()
{
	ListNode* head = new ListNode(1);
	ListNode* head1 = head;
	//ListNode* pCurrent = head;

	for (int i = 2; i <= 5; i++) {
		head->next = new ListNode(i);
		head = head->next;
	}
	printList(head1);
	removeNthFromEnd(head1, 3);
	//printList(head1);
	outputList(head1);

}
void test02()
{

	int a[4] = { 1, 2, 3, 4 };
	int* ptr = (int*)(&a+1);
	printf("%d", *(ptr -1));
		
	
}
bool fun(int n) {
	int sum = 0;
	for (int i = 1; n > sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}
class shape
{
public:
	virtual int area() = 0;
};
class rectangle :public shape
{
public:
	int a, b;
	void setLength(int x, int y) { a = x; b = y; }
	int area() { return a * b; }
};

void test03()
{
	/*Item stock;
	const char* s1 = "pen";
	stock.setInfo(s1, 20);*/

}
int main()
{
	test01();
	//test02();
	//cout << fun(484) << endl;
	//test03();

	system("pause");
	return 0;
}