#if 0
#include <iostream>
using namespace std;
//设计链表,头结点不保存信息,leecode必须头结点也保存信息,这个是我设计头结点不保存信息的,leecode已经通过
class LinkNode //结点
{
public:
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
        head->val = NULL;
        head->next = NULL;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= this->m_Size)
            return -1;
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < index; i++) {
            pCurrent = pCurrent->next;
        }
        return pCurrent->next->val;
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode;
        newNode->val = val;
        newNode->next = this->head->next;
        this->head->next = newNode;
        this->m_Size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < m_Size; i++) {
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
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < index; i++) {
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
        LinkNode* pCurrent = this->head;
        for (int i = 0; i < index ; i++) {
            pCurrent = pCurrent->next;
        }
        pCurrent->next = pCurrent->next->next;
        this->m_Size--;
    }
    void printList(PRINTFUNC print)
    {
        LinkNode* pCurrent = this->head->next;
        for (int i = 0; i < this->m_Size; i++) {
            print(pCurrent);
            pCurrent = pCurrent->next;           
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

    list->addAtHead(0);
    list->addAtHead(1);
    list->addAtTail(23);
    list->addAtIndex(2, 10);
    list->addAtHead(27);
    list->addAtHead(30);
    list->printList(myPrint);
    cout << endl;
    list->deleteAtIndex(2);
    list->printList(myPrint);
    cout << endl;

    cout << list->get(1) << endl;


}
void test02()
{
    MyLinkedList* list = new MyLinkedList;
    list->addAtIndex(0, 10);
    list->addAtIndex(0, 20);
    list->addAtIndex(1, 30);
    list->printList(myPrint);
    cout << list->get(0) << endl;
}
int main()
{
    //test01();
    test02();
	system("pause");
	return 0;
}

#endif