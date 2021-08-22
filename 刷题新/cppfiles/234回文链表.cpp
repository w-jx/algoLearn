#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

要用O(N)的时间复杂度和O（1）的空间复杂度解决，就要用快慢指针
1.找到中间结点
2.把后面结点反转
3.然后依次比较

*/
ListNode* reverse(ListNode* head) {
	if (!head ||!head->next)
		return head;
	auto nextNode = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;

	return nextNode;
}
bool isPalindrome(ListNode* head) {
	ListNode* fast = head, *slow = head;//通过快慢指针找到中点
	//在纸上画一下结点数是奇数 和 偶数 的两种情况	
	while (!fast && !fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	//fast不为空，说明
	
	长度为奇数个
	if (fast)
		slow = slow->next;
	slow = reverse(slow);//反转链表，返回新链表的头结点

	fast = head;

	while (slow) {
		if (fast->val != slow->val)
			return false;
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}
void test01()
{
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(2);
	root->next->next = new ListNode(1);

	cout << isPalindrome(root) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif