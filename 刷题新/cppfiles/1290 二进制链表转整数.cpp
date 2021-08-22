#if 0
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
int getDecimalValue(ListNode* head) {
	
	vector<int> v;
	while (head != nullptr) {
		v.push_back(head->val);
		head = head->next;
	}
	int sum = 0;
	int maxSize = v.size();
	int index = 1;
	for (auto iter : v) {
		int value = iter;
		for (int i = 0; i < maxSize-index; i++) {
			value*= 2;
		}
		sum += value;
		index++;
	}

	return sum;



}
void test01()
{
	ListNode* node1 = new ListNode(0);
	/*node1->next = new ListNode(0);
	node1->next->next = new ListNode(1);*/

	cout << getDecimalValue(node1) << endl;
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif