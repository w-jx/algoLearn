#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//����multiset
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> WindowMaxval_vec(n - k + 1);//n-k+1��Ԫ��
	int idx = 0;//�������ڵ��±�
	
	multiset<int> myset;//��Ϊ�������ظ�Ԫ��
	int left = 0, right = k;
	for (int i = 0; i < right; ++i) {
		myset.insert(nums[i]);
	}
	for (int i = right; i < n; ++i) {
		WindowMaxval_vec[idx++] = *myset.rbegin();
		
		myset.erase(myset.find(nums[left]));//Ϊ��ɾ����ʱ��,�ظ�Ԫ��ֻɾ��һ��
		++left;
		myset.insert(nums[i]);
	}
	WindowMaxval_vec[idx++] = *myset.rbegin();
	return WindowMaxval_vec;

}
class Cmp {
public:
	bool operator()(std::pair<int, int>& p1, std::pair<int, int>& p2) {
		return p1.first < p2.first;
	}
};
//�������ȼ�����
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
	priority_queue<std::pair<int,int>,vector<std::pair<int,int>>, Cmp> que;
	for (int i = 0; i < k; ++i) {
		que.push({ nums[i],i });
	}
	int n = nums.size();
	vector<int> WindowMaxval_vec(n - k + 1);//n-k+1��Ԫ��
	int idx = 0;//�������ڵ��±�
	int pos = k;
	
	while (idx < n - k + 1) {
		
		while (que.top().second < idx)
			que.pop();
		WindowMaxval_vec[idx] = que.top().first;
		++idx;
		if (pos == n)
			break;
		que.push({nums[pos],pos});
		++pos;
	}
	return WindowMaxval_vec;
	
}
void test01()
{
		vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
		auto res = maxSlidingWindow2(nums, 3);
		for (auto iter : res)
			cout << iter << " ";
		cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif