#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

class MyList
{
public:
    MyList()
    {
        head = nullptr;
    }
    ~MyList()
    {
        ListNode *cur = head;
        while (cur)
        {
            auto next = cur->next;
            delete cur;
            cur = next;
        }
    }
    void add(int val)
    {
        if (!head)
        {
            head = new ListNode(val);
        }
        else
        {
            auto cur = head;
            if (cur->val > val)
            { //头结点(最小的)已经比当前结点大了,更新头结点
                ListNode *node = new ListNode(val);
                node->next = head;
                head = node;
                return;
            }
            //否则找到一个合适的位置插入结点
            while (cur && cur->next)
            {
                if (cur->next->val > val)
                {
                    break;
                }
                cur = cur->next;
            }
            cur->next = new ListNode(val);
        }
    }

    void removeElement(int val)
    {
        auto dummy = new ListNode(-1, head);
        auto pre = dummy;

        while (pre->next)
        {
            if (pre->next->val == val)
            {
                //将要删除的结点备份一份
                auto deletedBack = pre->next;
                pre->next = pre->next->next;
                delete deletedBack;
            }
            else
            {
                pre = pre->next;
            }
        }

        head = dummy->next;
        delete dummy;
    }

    void foreach ()
    {
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
        delete cur;
    }

private:
    ListNode *head;
};

int main()
{
    MyList mylist;
    mylist.add(3);
    mylist.add(1);
    mylist.add(5);

    mylist.add(5);

    mylist.foreach ();
    mylist.foreach ();

    mylist.removeElement(5);
    mylist.foreach ();
    mylist.foreach ();
}