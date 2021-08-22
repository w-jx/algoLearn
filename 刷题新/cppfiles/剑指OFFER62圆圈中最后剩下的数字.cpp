#if 0
#include "../headers/wjxHeaders.h"
/*



*/

class CircleList {
public:
	CircleList() {  }
	CircleList(vector<int>& nums) {
		if (nums.empty())
			return;
		head = new CNode(nums.front());
		lastpos = head;
		CNode* pre = head;
		for (int i = 1; i < nums.size(); ++i) {
			CNode* node = new CNode(nums[i]);
			node->last = pre;
			pre->next = node;
			pre = node;
		}
		pre->next = head;
		head->last = pre;

		this->_size = nums.size();
	}
	void add(int val) {
		auto plast = this->head->last;
		CNode* node = new CNode(val);
		plast->next = node;
		node->last = plast;

		node->next = this->head;
		this->head->last = node;
		this->_size++;
	}
	void _deleteNode(int m) {
		auto phead = lastpos;
		int i = 1;
		while (i < m) {
			phead = phead->next;
			++i;
		}
		//phead就待删除
		lastpos = phead->next;
		phead->next->last = phead->last;
		phead->last->next = phead->next;

		delete phead;
		--this->_size;

	}
	int size()const {
		return this->_size;
	}
	int getval()const {
		return this->lastpos->val;
	}
private:
	struct CNode {

		int val;
		CNode* last;
		CNode* next;
		CNode(int _val) :val(_val), last(nullptr), next(nullptr) {}
	};
	CNode * head;
	int _size;
	CNode* lastpos;//上次遍历位置
};
//方法1:循环链表,超时
void test01()
{
	vector<int> nums{ 0,1,2,3,4,5,6,7,8,9 };
	CircleList cl(nums);
	while (cl.size() > 1) {
		cl._deleteNode(17);
	}
	cout << cl.getval() << endl;

}
int f(int n, int m) {
	if (n == 1)
		return 0;
	int x = f(n - 1, m);
	return (m + x) % n;
}
int  lastRemain(int n, int m) {
	return f(n, m);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif