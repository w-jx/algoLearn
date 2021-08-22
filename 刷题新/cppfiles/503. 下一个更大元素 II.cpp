#if 0
#include "../headers/wjxHeaders.h"

//�����������
//1.�����д����ظ�Ԫ��
vector<int> nextGreaterElements(vector<int>& nums) {
	
	int n = nums.size();
	nums.insert(nums.end(), nums.begin(), nums.end());//����һ��
	vector<int> stk;//����ջ
	stk.reserve(n);
	int doublen = n * 2;

	unordered_map<int, int> num_dict;//�洢�±�->ֵ��ӳ��
	for (int i = 0; i < n; ++i) {
		num_dict[i] = nums[i];
	}
	//key->Ԫ��,val->��key����ұ�Ԫ��,û�еĻ���-1    
	unordered_map<int, int> num_hash;
	
	for (int i = 0; i < doublen; ++i) {
		while (!stk.empty() && stk.back() < nums[i] ){
			if (num_hash.find(stk.back()) == num_hash.end())
				num_hash[stk.back()] = nums[i];
			stk.pop_back();
			
		}
			stk.push_back(nums[i]);
		

	}

	vector<int> ret(n,-1);
	for (int i = 0; i < n; ++i) {
		if (num_hash.find(nums[i]) != num_hash.end()) {
			ret[i] = num_hash[nums[i]];
		}
		else
			ret[i] = -1;
		
	}
	return ret;
}
//�����:����ջ
vector<int> nextGreaterElements2(vector<int>& nums) {
	//����ջ�洢����������±�,��ջ�׵�ջ���±��Ӧ��ֵ
	//�ǵ���������(Խ��ԽС,�򲻱�)
	//������ɵɵ����ԭ���������ƴ��һ��ԭ����,ʵ���ϲ���Ҫ������ƴ��
	//ֻ��Ҫ�������±����ȡģ�Ϳ���,���Ҳ���ƴn��Ԫ��,ֻ��Ҫ(n-1)��Ԫ��
	int n = nums.size();
	vector<int> stk;//�洢�����±�,�±��±�
	stk.reserve(n);
	vector<int> ret(n, -1);
	int len = 2 * n - 1;
	for (int i = 0; i < len; ++i) {
		while (!stk.empty() && nums[stk.back()]< nums[i%n]) {
			ret[stk.back()] = nums[i];
			stk.pop_back();
		}
		stk.push_back(i%n);
	}
	return ret;

}
void test01()
{
	vector<int> nums{ 100,1,11,1,120,111,123,1,-1,-100 };
	auto ret = nextGreaterElements(nums);
	printVector(ret);
}
int main()
{
	test01();
}
#endif