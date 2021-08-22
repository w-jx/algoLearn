#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
ListNode* deleteDuplicates(ListNode* head) {

	ListNode* pBefore = new ListNode;
	pBefore->next = head;
	
	ListNode* cur = head, *pre = pBefore;
	int tempval = 0;
	while (cur && cur->next) {
		if (cur->val != cur->next->val) {
			pre = cur;
			cur = cur->next;
		}
		else {
			tempval = cur->val;
			while (cur && cur->val == tempval)
				cur = cur->next;
			pre->next = cur;
		}
	}
	return pBefore->next;

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