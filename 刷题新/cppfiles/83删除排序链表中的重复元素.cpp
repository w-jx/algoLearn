#if 0
#include "../headers/wjxHeaders.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
void foreachNode(ListNode* head) {
	if (!head) return;
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
ListNode* make_head(initializer_list<int> const & list) {
	if (list.size() == 0) return nullptr;
	ListNode* head = new ListNode(*list.begin());
	auto temp = head;
	for (auto iter = list.begin() + 1; iter != list.end(); iter++) {
		temp->next = new ListNode(*iter);
		temp = temp->next;
	}
	return head;
}
ListNode* deleteDuplicates(ListNode* head)
{

}
void test01()
{
	foreachNode(make_head({ 1,2,3,4 }));
}
int main()
{
	system("pause");
	return 0;
}


#endif