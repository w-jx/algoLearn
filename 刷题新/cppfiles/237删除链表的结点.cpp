#if 0
#include "../headers/wjxHeaders.h"


void deleteNode(ListNode* node) {
    ListNode* cur = node;
    
    while (cur->next) {
        cur->val = cur->next->val;
        cur = cur->next;
    }
    delete cur;
}
void test01()
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    ListNode* node = head->next;

    head->next->next = new ListNode(1);

    head->next->next->next = new ListNode(9);

    ListNode* cur = head;
    //while (cur) {
    //    cout << cur->val << " ";
    //    cur=cur->next;
    //}
    deleteNode(node);
    ///cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
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