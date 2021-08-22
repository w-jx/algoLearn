#if 0
#include "../headers/wjxHeaders.h"
/*
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

方法1：
	用set求交集 ，插入链表结点的指针地址  空间复杂度不满足

方法2：
	1.计算 head1 head2的长度，还有较长链表的多出来的长度。
	2.将较长链表头结点 移动到和较短链表 指针对齐的位置
	3.进行遍历，找到相同的结点

*/

/// <summary>
/// 给定链表头，获得链表长度
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
int getLength(ListNode* head)
{
	ListNode* cur = head;
	int len = 0;
	while (cur) {
		++len;
		cur = cur->next;
	}
	return len;
}
/// <summary>
/// 给定链表头结点，向前移动
/// </summary>
/// <param name="head"></param>
/// <param name="short_len"></param>
/// <param name="long_len"></param>
/// <returns></returns>
ListNode* forword_ListNode(ListNode* head, int short_len, int long_len)
{
	
	int step = long_len - short_len;
	auto cur = head;
	for (int i = 0; i < step; ++i) {
		cur = cur->next;
	}
	return cur;

}

/// <summary>
/// 返回headA 和 headB 相交的结点
/// </summary>
/// <param name="headA"></param>
/// <param name="headB"></param>
/// <returns>相交的结点，不相交返回nullptr</returns>
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	auto lenA = getLength(headA);
	auto lenB = getLength(headB);

	ListNode* curA = headA;
	ListNode* curB = headB;

	if (lenA > lenB)
		curA = forword_ListNode(curA, lenB, lenA);
	else if (lenA < lenB)
		curB = forword_ListNode(curB, lenA, lenB);
	
	while (curA && curB) {
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}
	return nullptr;

}
//leetcode 题解,双指针的方法
ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {

	if (!headA || !headB)
		return nullptr;

	ListNode* cura = headA;
	ListNode* curb = headB;

	while (cura != curb) {
		if (cura)
			cura = cura->next;
		else
			cura = headB;
		if (curb)
			curb = curb->next;
		else
			curb = headA;
	}
	return cura;

}
void test01()
{
	//结果是same,也就是不相交的链表,最终都会到空节点
	ListNode* cura = nullptr;
	ListNode* curb = nullptr;
	if (cura == curb)
		cout << "same\n";
	else
		cout << "different\n";
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif