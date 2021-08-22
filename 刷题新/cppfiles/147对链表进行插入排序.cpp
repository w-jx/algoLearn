#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//ListNode* insertionSortList(ListNode* head) {
//	if (!head || !head->next)
//		return head;
//	ListNode* sorted = head;
//	ListNode* unsorted = head->next;
//	sorted->next = nullptr;
//	bool isAdd = false;
//	while (unsorted) {//未排序部分为空，排序完成
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
//		//找到最小的了，然后先删除一波
//		auto node = pre->next;
//		pre->next = pre->next->next;
//		delete node;
//		node = nullptr;
//
//		//添加到已排序结点
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
先找到待插入的结点（前一个结点值比当前的大），移除，移除前保存。
将该结点插入到合适的位置——从头遍历比较，并插入。
*/
ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
		return head;
	ListNode* dummy = new ListNode(-1,head);
	ListNode* lastSorted = head; //指向有序数组最后一个元素
	ListNode* cur = head->next;

	while (cur) {
		//说明cur 位于lastSorted之后，因此将lastSorted后移一位，cur就是新的lastSorted
		if (lastSorted->val <= cur->val) {
			lastSorted = lastSorted->next;
		}
		else {//lastSorted->val > cur->val			
			//从链表的头结点开始向后遍历，查找插入cur的位置
			ListNode* prev = dummy;
			while ( prev->next->val <= cur->val) {//prev->next->val>cur->val 跳出
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