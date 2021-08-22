#if 0
#include "../headers/wjxHeaders.h"

size_t getlen(ListNode*& node)
{
    auto head = node;
    size_t cnt = 0;
    while (head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto len1 = getlen(l1);
    auto len2 = getlen(l2);

    vector<ListNode*> node_vec;
    auto head1 = l1;
    auto head2 = l2;
    int extra = 0;
    if (len1 > len2) {
        extra = len1 - len2;
        for (int i = 0; i < extra; ++i) {
            node_vec.push_back(head1);
            head1 = head1->next;
        }
    }
    else if (len2 > len1) {
        extra = len2 - len1;
        for (int i = 0; i < extra; ++i) {
            node_vec.push_back(head2);
            head2 = head2->next;
        }
    }
    extra = 0;
    int sum = 0, val = 0;
    while (head1) {
        ListNode* node = new ListNode(head1->val + head2->val);
        node_vec.push_back(node);
        head1 = head1->next;
        head2 = head2->next;
    }
    size_t n = node_vec.size();
    node_vec.push_back(nullptr);

    for (int i = n-1; i >= 0; --i) {
        node_vec[i]->next = node_vec[i + 1];
        sum = node_vec[i]->val + extra;
        extra = sum / 10;
        val = sum % 10;
        node_vec[i]->val = val;
    }
    //·ÀÖ¹²âÊÔÓÃÀý[5],[5]
    if (extra != 0) {
        ListNode* node = new ListNode(extra);
        node->next = node_vec[0];
        return node;
    }
    return node_vec[0];
}
void test01()
{
    ListNode* head1 = new ListNode(7);
    head1->next  = new ListNode(2);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
 
    auto head = addTwoNumbers(head1, head2);
    printNode(head);
}
int main()
{
	test01();
}
#endif