#if 0
#include "../headers/wjxHeaders.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	
	auto sum = l1->val + l2->val;
	ListNode* pTemp = new ListNode(sum % 10);
	ListNode* pRet = pTemp;
	l1 = l1->next;
	l2 = l2->next;
	while (1) {
		if (l1 == nullptr && l2 == nullptr) break;

		if (l1 == nullptr) {
			sum = sum / 10 + l2->val;
			l2 = l2->next;
		}
		else if (l2 == nullptr) {
			sum = sum / 10 + l1->val;
			l1 = l1->next;
			
		}
		else {
			sum = sum / 10 + l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
		}
			

		ListNode* pNew = new ListNode(sum % 10);
		pTemp->next = pNew;
		pTemp = pNew;
		
	}
	if (sum / 10 > 0) {
		ListNode* pNew = new ListNode(sum / 10);
		pTemp->next = pNew;
		pTemp = pNew;
	}
	return pRet;


}
void test01()
{
	vector<int> v = { 9,9,9,9,9,9,9 };
	vector<int> v2 = { 9,9,9,9 };
	ListNode* list1 = makeList(v);
	ListNode* list2 = makeList(v2);

	printNode(addTwoNumbers(list1, list2));//3,6,7
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif