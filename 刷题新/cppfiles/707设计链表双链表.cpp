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
        if (index < 0 || index >= this->m_size) return -1;
        ListNode* pTemp = this->head;

        for (int i = 0; i < index; i++) {
            pTemp = pTemp->next;
        }

        return pTemp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        ListNode* pNew = new ListNode(val);
        if (!this->head) {
            this->head = pNew;
            
            this->m_size++;
            return;
        }
        pNew->next = this->head;
        this->head->prev = pNew;
        pNew->prev = nullptr;
        this->head = pNew;

        this->m_size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* pNew = new ListNode(val);
        if (!this->head) {
            this->head = pNew;
            this->m_size++;
            return;
        }
        ListNode* pTemp = this->head;
        ListNode* pBefore = pTemp->prev;

       
        while (pTemp) {
            pBefore = pTemp;
            pTemp = pTemp->next;
        }
        
        pBefore->next = pNew;
        pNew->prev = pBefore;
        
      

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
        pTemp->next->prev = pNew;
        pNew->next = pTemp->next;
        pNew->prev = pTemp;
        pTemp->next = pNew;
        this->m_size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->m_size) return;
        ListNode* pTemp = this->head;
        if (index == 0) {
            ListNode* pDel = this->head;
            this->head = pTemp->next;
          
            delete pDel;
            pDel = nullptr;
            
        }
    
        else {
            for (int i = 0; i < index - 1; i++) {
                pTemp = pTemp->next;
            }

            auto p = pTemp->next->next;


            ListNode* pDel = pTemp->next;

            pTemp->next =p;

            if (p) {
               p->prev = pTemp;
            }
          
            delete pDel;
            pDel = nullptr;
        }


        this->m_size--;
    }


    void print() {
        ListNode* pTemp = this->head;

        while (pTemp) {
            cout << pTemp->val << " ";
            pTemp = pTemp->next;
        }
        cout << endl;
    }

    class ListNode {//双链表的结点 有前后两个指针
    public:
        int val;
        ListNode* next,*prev;
        ListNode(int val) :val(val), next(nullptr),prev(nullptr) {}

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

    list.addAtIndex(0, 10);

    list.addAtIndex(1, 20);
    list.addAtIndex(1, 30);



    
    list.print();

    list.deleteAtIndex(3);


    list.print();


}

int main()
{
    test01();

  
    system("pause");
    return 0;
}
#endif