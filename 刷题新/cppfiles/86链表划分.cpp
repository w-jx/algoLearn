#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
ListNode* partition(ListNode* head, int x) {

	ListNode lessHead(0);//分别定义两个临时的头结点
	ListNode moreHead(0);

	ListNode* lessPtr = &lessHead;//对应指针指向两个头结点
	ListNode* morePtr = &moreHead;

	ListNode* cur = head;
	while (cur) {
		if (cur->val < x) {
			lessPtr->next = cur;
			lessPtr = lessPtr->next;
		}
		else {
			morePtr->next = cur;
			morePtr = morePtr->next;
		}
		cur = cur->next;
	}
	lessPtr->next = moreHead.next;
	morePtr->next = nullptr;//注意要置空

	return lessHead.next;
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif