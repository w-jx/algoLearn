#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
ListNode* partition(ListNode* head, int x) {

	ListNode lessHead(0);//�ֱ���������ʱ��ͷ���
	ListNode moreHead(0);

	ListNode* lessPtr = &lessHead;//��Ӧָ��ָ������ͷ���
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
	morePtr->next = nullptr;//ע��Ҫ�ÿ�

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