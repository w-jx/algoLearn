#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

方法1:用set 保存结点
方法2：快慢指针
 

*/

//注意 快慢指针 初始位置相同
ListNode* detectCycle(ListNode* head) { 
	ListNode* slow = head, * fast = head;
	ListNode* meet = nullptr;

	while (fast) {
		slow = slow->next;
		fast = fast->next;//slow 和 fast 各自走一步

		if (!fast)
			return nullptr;//fast 为空，没环
		fast = fast->next;//fast 再走一步
			
		if (fast == slow) {//找到了相遇点
			meet = fast;
			break;
		}
	}
	if (meet == nullptr)//没找到相遇点，说明没有环
		return nullptr;
	ListNode* cur = head;//为了不破坏 链表

	while (cur && meet) {
		if (cur == meet)
			return cur;
		cur = cur->next;//cur 和meet 走一步
		meet = meet->next;
	}
	return nullptr;
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