#if 0
#include "../headers/wjxHeaders.h"
/*
�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ����������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档

����1��
	��set�󽻼� ��������������ָ���ַ  �ռ临�ӶȲ�����

����2��
	1.���� head1 head2�ĳ��ȣ����нϳ������Ķ�����ĳ��ȡ�
	2.���ϳ�����ͷ��� �ƶ����ͽ϶����� ָ������λ��
	3.���б������ҵ���ͬ�Ľ��

*/

/// <summary>
/// ��������ͷ�������������
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
/// ��������ͷ��㣬��ǰ�ƶ�
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
/// ����headA �� headB �ཻ�Ľ��
/// </summary>
/// <param name="headA"></param>
/// <param name="headB"></param>
/// <returns>�ཻ�Ľ�㣬���ཻ����nullptr</returns>
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
//leetcode ���,˫ָ��ķ���
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
	//�����same,Ҳ���ǲ��ཻ������,���ն��ᵽ�սڵ�
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