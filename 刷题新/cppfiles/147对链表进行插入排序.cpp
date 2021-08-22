#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//ListNode* insertionSortList(ListNode* head) {
//	if (!head || !head->next)
//		return head;
//	ListNode* sorted = head;
//	ListNode* unsorted = head->next;
//	sorted->next = nullptr;
//	bool isAdd = false;
//	while (unsorted) {//δ���򲿷�Ϊ�գ��������
//
//		ListNode* pre = new ListNode(-1, unsorted);
//		ListNode* cur = unsorted;
//
//		int min = INT_MAX;
//		ListNode* min_node = nullptr;
//		while (cur) {
//			if (cur->val < min) {
//				min = cur->val;
//				min_node = cur;
//			}
//			pre = pre->next;
//			cur = cur->next;
//		}
//		//�ҵ���С���ˣ�Ȼ����ɾ��һ��
//		auto node = pre->next;
//		pre->next = pre->next->next;
//		delete node;
//		node = nullptr;
//
//		//��ӵ���������
//		ListNode* sortedRef = sorted;
//		ListNode* preSorted = new ListNode(-1, sorted);
//
//		while (sortedRef) {
//			if (min_node->val < sortedRef->val) {
//				min_node->next = sortedRef;
//				sortedRef = min_node;
//				isAdd = true;
//				break;
//			}
//			sortedRef = sortedRef->next;
//			preSorted = preSorted->next;
//		}
//		if (!isAdd) {
//			sortedRef = min_node;
//			min_node->next = nullptr;
//		}
//	}
//	return sorted;
//
//}
/*
���ҵ�������Ľ�㣨ǰһ�����ֵ�ȵ�ǰ�Ĵ󣩣��Ƴ����Ƴ�ǰ���档
���ý����뵽���ʵ�λ�á�����ͷ�����Ƚϣ������롣
*/
ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
		return head;
	ListNode* dummy = new ListNode(-1,head);
	ListNode* lastSorted = head; //ָ�������������һ��Ԫ��
	ListNode* cur = head->next;

	while (cur) {
		//˵��cur λ��lastSorted֮����˽�lastSorted����һλ��cur�����µ�lastSorted
		if (lastSorted->val <= cur->val) {
			lastSorted = lastSorted->next;
		}
		else {//lastSorted->val > cur->val			
			//�������ͷ��㿪ʼ�����������Ҳ���cur��λ��
			ListNode* prev = dummy;
			while ( prev->next->val <= cur->val) {//prev->next->val>cur->val ����
				prev = prev->next;
			}
			lastSorted->next = cur->next;
			cur->next = prev->next;
			prev->next = cur;
		}
		cur = lastSorted->next;
	}
	return dummy->next;

}
void test01()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(2);
	auto node = insertionSortList(head);

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif