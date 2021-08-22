#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next)
        return head;
    ListNode* dummy = new ListNode(-1, head);
    ListNode* pre = dummy;
    ListNode* cur = head;
    ListNode* newhead = head;//�������newhead �Ƿ�Ϊ���ж�ѭ���Ƿ����
    ListNode* oldhead = head;
    bool loopover = false;
    while (true) {

        oldhead = pre->next;
        newhead = pre->next;
        if (!newhead)
            break;
        int i = 1;
        while (i < k) {
            newhead = newhead->next;
            if (!newhead) {
                loopover = true;
                break;
            }
            ++i;
        }//while
        if (loopover)
            break;
        auto last = oldhead;
        auto _next = oldhead->next;
        pre->next = newhead;
        cur->next = newhead->next;
        i = 1;


        while (i < k) {
            auto temp = _next->next;
            _next->next = last;
            last = _next;
            _next = temp;
            ++i;
        }
        pre = cur;
        cur = cur->next;

    }//�ж�ʣ�µĽ�������ǲ����Ѿ�С��k��
    return dummy->next;
}
//2021��6��14������,��תk��ͷ�ڵ�
ListNode* reverse(ListNode* head, int k,ListNode*& last)
{
    ListNode* dummy = new ListNode(-1, head);
    ListNode* pre = dummy;
    ListNode* cur = head;

    for (int i = 1; i < k; ++i) {
        auto oldhead = pre->next;
        auto newhead = cur->next;
        pre->next = newhead;
        cur->next = newhead->next;
        newhead->next = oldhead;
    }
    last = cur;
    head = dummy->next;
    return dummy->next;
}
void test01()
{
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);

    reverseKGroup(root,3);

    cout << root->val << endl;;
}
ListNode* reverseKGroup2(ListNode* head, int k) {
    if (k == 1)
        return head;
    auto cur = head;
    int cnt = 0;
    while (cur) {
        ++cnt;
        cur = cur->next;
    }

    cur= head;
    ListNode* last = nullptr;
    int times = cnt / k;
    auto node = reverse(cur, k, last);

    for (int i = 1; i < times; ++i) {
        auto lastref = last;
        auto waithead = last->next;
        lastref->next = nullptr;
        auto node = reverse(waithead, k,last );

        lastref->next = node;
    }
    return node;
}
void test02()
{
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    ListNode* last = nullptr;

    auto newroot = reverseKGroup2(root,2);
    printNode(newroot);


}
int main()
{
    //test01();
    test02();
    system("pause");
	return 0;
}
#endif