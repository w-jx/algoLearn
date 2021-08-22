#if 0
#include <iostream>
using namespace std;
//leecode已经提交通过,但是占用空间太大
class LinkNode //结点
{
public:
    LinkNode()
    {
        this->val = NULL;
        this->next = NULL;
    }
    ~LinkNode() {
        delete next;
    }
    int val;
    LinkNode* next;
};
typedef void(*PRINTFUNC)(LinkNode*);
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->m_Size = 0;
        head = new LinkNode;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= this->m_Size)
            return -1;

        LinkNode* pCurrent = new LinkNode;
        pCurrent->next = this->head;
       
        for (int i = 0; i < index; i++) {
            pCurrent = pCurrent->next;
        }   
        return pCurrent->next->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {    
        
        LinkNode* newNode = new LinkNode;
        newNode->val = val;
        newNode->next = this->head;
        this->head = newNode;
        
        this->m_Size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
       
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < m_Size-1; i++) {
            pCurrent = pCurrent->next;
        }       
        LinkNode* newNode = new LinkNode;
        newNode->val = val;
        newNode->next = pCurrent->next;
        pCurrent->next = newNode;
        this->m_Size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       
        if (index < 0 || index > this->m_Size)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        LinkNode* pCurrent = head;     
        for (int i = 0; i < index-1 ; i++) {
            pCurrent = pCurrent->next;
        }
        LinkNode* newNode = new LinkNode;
        newNode->val = val;
        newNode->next = pCurrent->next;
        pCurrent->next = newNode;

        this->m_Size++;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->m_Size)
            return;

        LinkNode* newNode = new LinkNode;
        newNode->next = this->head;
        LinkNode* pCurrent = newNode;

        if (index == 0) {
            this->head = this->head->next;
            return;
        }
        for (int i = 0; i < index ; i++) {
            pCurrent = pCurrent->next;
        }
        pCurrent->next = pCurrent->next->next;
        
       
       
        this->m_Size--;
    }
    void printList(PRINTFUNC print)
    {
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < this->m_Size; i++) {
            print(pCurrent);
            pCurrent = pCurrent->next;
        }
        cout << endl;

    }
    void deleteNode(LinkNode* node) {
        LinkNode* pBefore = new LinkNode;
        pBefore->next = this->head;

        while (pBefore->next) {
            if (node == pBefore->next) {
                pBefore->next = pBefore->next->next;
                break;
            }
            cout << "test:pBefore.val=" << pBefore->val << endl;
            cout << "test:pBefore.next.val=" << pBefore->next->val << endl;
            pBefore = pBefore->next;
        }
    }
    ~MyLinkedList()
    {
        delete head;
    }
    int m_Size;
    LinkNode* head;

};
void myPrint(LinkNode* data)
{
    cout << data->val << " ";
}
void test01()
{
    MyLinkedList* list = new MyLinkedList;
    list->addAtHead(10);
    list->addAtHead(20);
    list->addAtHead(26);
    list->addAtTail(15);
    list->addAtIndex(2, 88);
    list->printList(myPrint);
    list->deleteAtIndex(0);
    list->printList(myPrint);
    cout << list->get(0) << endl;


    delete list;

}
void test02()
{
    MyLinkedList* list = new MyLinkedList;
    list->addAtIndex(0, 10);
    list->addAtIndex(0, 20);
    list->addAtIndex(1, 30);
    list->printList(myPrint);
    delete list;

}
void test03()
{
    MyLinkedList* list = new MyLinkedList;
    list->addAtIndex(0, 10);
    list->addAtIndex(0, 20);
    list->addAtIndex(0, 30);
    list->printList(myPrint);
    
}
int main(void)
{
    //test01();
   // test02();
    test03();
    system("pause");
    return 0;
}
#endif


