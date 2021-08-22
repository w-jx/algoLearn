#if 0
#include <iostream>
using namespace std;
#include <vector>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

void printNode(ListNode* head);

ListNode* reverseList(ListNode* head) {

	if (head == NULL)
		return NULL;
	ListNode* pRet = new ListNode(head->val);
	head = head->next;
	while (head != NULL) {
		ListNode* node = new ListNode(head->val);
		node->next = pRet;
		pRet = node;
		head = head->next;
	}

	return pRet;

}
ListNode* reverseList1(ListNode* head) {//这个反而不如之前那个

	if (head == NULL)
		return NULL;
	ListNode* pRet = NULL;
	
	while (head != NULL) {
		ListNode* node = new ListNode(head->val);
		node->next = pRet;
		pRet = node;
		head = head->next;
	}

	return pRet;

}

ListNode* reverseList2(ListNode* head) {//三指针实现链表反转

	if (head == NULL)
		return NULL;
	ListNode* pBeg = head;//指向头结点
	ListNode* pMid = head->next;//指向头结点的下一个
	ListNode* pTemp;
	head->next = NULL;//旧的头结点是新的尾结点,指向NULL

	while (pMid) {
		pTemp = pMid->next;//先保留下
		pMid->next = pBeg;//改变指向
		pBeg = pMid;
		pMid = pTemp;

	}
	return pBeg;


}
ListNode* reverseList3(ListNode* head) {//递归法

	if (head == NULL || head->next==NULL)//空链表或只有一个结点,返回头指针
		return head;
	ListNode* pNew = reverseList3(head->next);//一直递归,找到链表中的最后一个结点
	/*
	 当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
     递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。
     每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。	
	*/
	head->next->next = head;
	head->next = NULL;
	//每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
	return pNew;

}
ListNode* deleteNode(ListNode* head, int val)
{
	if(head == NULL)
		return NULL;
	ListNode* pBefore = new ListNode(10);
	pBefore->next = head;
	ListNode* pRet = pBefore;
	while (head != NULL) {
		if (head->val == val) {
			pBefore->next = head->next;		
			break;
		}
		pBefore = head;
		head = head->next;
		
	}
	return  pRet->next;
}
ListNode* deleteNode1(ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	

	while (head != NULL) {
		if (head->val == val) {
			head=head->next;
			break;
		}
		head = head->next;
		
	}
	return head;
}
void printNode(ListNode* head)
{
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
void push(ListNode* head, int val)
{
	if (head == NULL)
		return ;
	ListNode* pHead = head;
	while (head->next != NULL) {
		head = head->next;
	}
	ListNode* pNew = new ListNode(val);
	head->next = pNew;
}
void test01()//反转链表测试
{
	ListNode* head1 = new ListNode(0);
	ListNode* l1 = head1;
	for (int i = 1; i < 4; i++) {//遍历head1不影响打印l1
		ListNode* pNext = new ListNode(i);
		head1->next = pNext;
		head1 = pNext;
	}
	printNode(l1);

	printNode(reverseList1(l1));
}
void test02()//删除链表的结点测试
{
	ListNode* list1 = new ListNode(4);
	
	push(list1,5);
	push(list1, 1);
	push(list1, 9);
	
	
	printNode(deleteNode(list1,1));
	

}
void test03()//递归反转链表
{
	ListNode* list1 = new ListNode(1);

	push(list1, 2);
	push(list1, 3);
	push(list1, 4);

	printNode(list1);
	printNode(reverseList3(list1));
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
