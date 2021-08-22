#if 0
#include "../headers/wjxHeaders.h"
/*
* 看了答案解析,完全没思路,学习双指针法
leecode题目介绍:
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

理解上如果有环,那么最后一个节点的next是头结点,换言之,环的起点和终点只会是链表的头结点和尾结点
*/

bool hasCycle(ListNode* head) { //看了答案的解法

	//链表为空或者链表只有一个节点,那么肯定不会是环形的,false
	if (head == nullptr || head->next == nullptr) 
		return false;
	ListNode* slow = head;//快慢指针分别..
	ListNode* fast = head->next;

	while (slow != fast) {
		if (fast == nullptr || fast->next == nullptr)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
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