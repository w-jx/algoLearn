#if 0
#include "../headers/wjxHeaders.h"

//先排序 在获得即可
int findKthLargest(vector<int>& nums, int k) {
	make_heap(nums.begin(), nums.end(), less<>());
	for (int i = 0; i <= k-2; i++) {
		pop_heap(nums.begin(), nums.end()-i, less<>());
	}
	return nums.front();
}

void test01()
{
	vector<int> v{ 1,5,2,8,9,4,7 };
	make_heap(v.begin(), v.end(), std::greater<>());
	printVector(v);
	pop_heap(v.begin(), v.end()-1,std::greater<>());
	printVector(v);
	pop_heap(v.begin(), v.end() - 2, std::greater<>());
	printVector(v);

}
int findKthLargest2(vector<int>& nums, int k) {

	priority_queue<int> q(nums.begin(), nums.end());
	for (int i = 0; i < k-1; i++) {
		q.pop();
	}
	return q.top();
}
int main()
{
	/*test01();*/
	vector<int> v{ 1,5,2,8,9,4,7 };
	auto vtemp = v;
	sort(vtemp.begin(), vtemp.end(), greater<>());
	/*
	sort 的greater v1>v2  反而是从小到大排序的
	less  v1<v2     从大到小排序的
	
	*/
	printVector(vtemp);
	cout << "第k的最大的数是=" << findKthLargest(v, 4) << endl;


	cout << "第k的最大的数是=" << findKthLargest2(v, 4) << endl;
	
	system("pause");
	return 0;
}


#endif