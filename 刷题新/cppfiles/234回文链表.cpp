#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

Ҫ��O(N)��ʱ�临�ӶȺ�O��1���Ŀռ临�ӶȽ������Ҫ�ÿ���ָ��
1.�ҵ��м���
2.�Ѻ����㷴ת
3.Ȼ�����αȽ�

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
	ListNode* fast = head, *slow = head;//ͨ������ָ���ҵ��е�
	//��ֽ�ϻ�һ�½���������� �� ż�� ���������	
	while (!fast && !fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	//fast��Ϊ�գ�˵��
	
	����Ϊ������
	if (fast)
		slow = slow->next;
	slow = reverse(slow);//��ת���������������ͷ���

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