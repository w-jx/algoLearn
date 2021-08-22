#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = nullptr;
        this->m_size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index <0 || index >= this->m_size) return -1;
        ListNode* pTemp = this->head;

        for (int i = 0; i < index; i++) {
            pTemp = pTemp->next;
        }

        return pTemp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* pNew = new ListNode(val);
        pNew->next = this->head;
        this->head = pNew;

        this->m_size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* pNew = new ListNode(val);

        ListNode* pTemp = this->head;
        if (pTemp) {
            while (pTemp->next) {
                pTemp = pTemp->next;
            }
            pTemp->next = pNew;
        }
        else {
            this->head = pNew;
           
        }
      
        this->m_size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index<0 || index>this->m_size) return;
        if (index == this->m_size) { this->addAtTail(val); return; }

        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        ListNode* pNew = new ListNode(val);

        ListNode* pTemp = this->head;

        for (int i = 0; i < index - 1; i++) {
            pTemp = pTemp->next;
        }
        pNew->next = pTemp->next;
        pTemp->next = pNew;
        this->m_size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < -1 || index >= this->m_size) return;
        ListNode* pTemp = this->head;
        if (index == 0) {
            this->head = pTemp->next;
            //delete pTemp;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                pTemp = pTemp->next;
            }
            ListNode* pDel = pTemp->next;
            pTemp->next = pTemp->next->next;
            delete pDel;
        }


        this->m_size--;
    }

    void removeElements(int val) {//leetcode 移除链表元素

        ListNode* cur = new ListNode(100);
        cur->next = this->head;
        ListNode* ptemp = this->head;
        ListNode* pBefore = cur;
        while (ptemp) {
            if (ptemp->val == val) {
                pBefore->next = pBefore->next->next;
                ptemp = pBefore->next;
            }
            else {
                pBefore = ptemp;
                ptemp = ptemp->next;
            }

        }
        this->head = cur->next;
        this->m_size--;


    }

    void oddEvenList() {//leetcode 奇偶链表

    if (head == nullptr || head->next == nullptr) return ;

        ListNode* temp = head;
        ListNode* pRet = temp;
        queue<ListNode*> q;

        while (temp && temp->next) {          
			q.push(temp->next);
			auto tempnode = temp->next->next;
			if (tempnode) {
				temp->next = tempnode;
				temp = tempnode;
			}
			else
				break;          
        }
        while (!q.empty()) {
            auto p =q.front();  
			temp->next = p;
			temp = temp->next;

            q.pop();
        }
        temp->next = nullptr;
        this->head = pRet;

    }
    /*
    * 很神奇,这个代码,奇数个结点会出现无限循环,但是偶数个输出正常,问题找到了!!!
    void oddEvenList() {//leetcode 奇偶链表

    if (head == nullptr || head->next == nullptr) return ;

        Node* temp = head;
        Node* pRet = temp;
        queue<Node*> q;

        while (temp && temp->next) {          
			q.push(temp->next);
			auto tempnode = temp->next->next;
			if (tempnode) {
				temp->next = tempnode;
				temp = tempnode;
			}
			else
				break;          
        }
        cout << q.size() << endl;
        while (!q.empty()) {
            auto p =q.front();  
			temp->next = p;
			temp = temp->next;

            q.pop();
        }
        
        this->head = pRet;

    }
    
    
    
    
    
    
    
    */
    bool isPalindrome() { //回文链表,尝试用栈实现,总是出错
        if (this->head == nullptr || this->head->next == nullptr) return true;

        ListNode* pTemp = this->head;
        stack<ListNode*> s;

        s.push(pTemp);
        pTemp = pTemp->next;
        bool flag = false;
        while (pTemp) {
            auto p = s.top();
            if (pTemp->val != p->val) {
                s.pop();
                if (!s.empty()) {
                    auto pbefore = s.top();
                    if (pTemp->val == pbefore->val) {
                        s.pop();
                        pTemp = pTemp->next;
                        break;
                    }
                }
                s.push(p);
                s.push(pTemp);
                pTemp = pTemp->next;
            }
            else {
               
                s.pop();
                pTemp = pTemp->next;
                break;
            }
        }
      
        while (!s.empty()) {
            if (pTemp == nullptr) return false;

            auto p = s.top();

            if (p->val == pTemp->val) {
                s.pop();
                pTemp = pTemp->next;
            }
            else {
                return false;
            }
        }
        return pTemp == nullptr;

    }

    bool isPalindrome2() { //回文链表,尝试用栈实现,总是出错
        if (this->head == nullptr || this->head->next == nullptr) return true;

        ListNode* pTemp = this->head;
        vector<ListNode*> v;

        while (pTemp) {
            v.push_back(pTemp);
            pTemp = pTemp->next;
        }
        int begin = 0;
        int end = v.size() - 1;

        while (begin < end) {
            if (v[begin]->val != v[end]->val)
                return false;
            begin++;
            end--;
        }
        return true;

    }
    void print() {
        ListNode* pTemp = this->head;

        while (pTemp) {
            cout << pTemp->val << " ";
            pTemp = pTemp->next;
        }
        cout << endl;
    }

    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val) :val(val), next(nullptr) {}

    };


    ListNode* head;
    int m_size;

};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


void test01()
{
    MyLinkedList list;
    //list.addAtHead(1);
    //list.print();

    //list.addAtTail(5);

    //list.addAtIndex(2,10);


    //list.print();

   
    //list.print();
    list.addAtIndex(0, 10);

    list.addAtIndex(0, 20);

    list.addAtIndex(1, 30);


    list.addAtHead(7);
    list.addAtHead(13);
    list.addAtIndex(4, 15);
    list.print();
    list.oddEvenList();
    list.print();



}
//奇偶链表测试
void test02() 
{
    MyLinkedList list;
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtTail(4);
    list.addAtTail(5);
    //list.addAtTail(6);
    list.print();

    list.oddEvenList();
    list.print();


}
void test03()
{
    MyLinkedList list;
    list.addAtTail(1);
  //  list.addAtTail(2);
    //list.addAtTail(2);
  //  list.addAtTail(2);
  //  list.addAtTail(1);

    list.print();

    cout << list.isPalindrome2() << endl;
}

void printNode(ListNode* temp) {
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void test04()
{
    MyLinkedList list1, list2;
    list1.addAtHead(1);
    list1.addAtHead(2);
    list1.addAtHead(3);

    list2.addAtHead(2);
    list2.addAtHead(3);
    list2.addAtHead(4);

    
   
}
int main()
{
    //test01();
    //test02();
    test03();
	system("pause");
	return 0;
}
#endif