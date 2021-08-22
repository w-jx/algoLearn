#if 0
#include "../headers/wjxHeaders.h"






ListNode* reverseBetween(ListNode* head, int left, int right) {
	ListNode dummy(-1,head);	
	ListNode* cur = &dummy;

	for (int i = 0; i < left - 1; i++)
		cur = cur->next;

	ListNode* pre = cur;
	cur = cur->next;
	for (int i = 0; i < right - left; i++) {
		auto oldhead = pre->next;
		auto newhead = cur->next;
		pre->next = newhead;
		cur->next = newhead->next;
		newhead->next = oldhead;
	}
	return dummy.next;

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