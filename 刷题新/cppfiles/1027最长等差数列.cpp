#if 0
#include "../headers/wjxHeaders.h"

/*
����1 ���Ż���̬�滮
dp[i][j]Ϊ��a[i],a[j]Ϊ�������Ԫ�صĵȲ����еĳ���
�������������,��ôǰһ����target
��
	target-a[i]=a[i]-a[j]
		target = 2*a[i]-a[j]
a[i],a[j]ȷ����,��ôֻҪ�ҵ�iǰ�����i��targetλ�ü���
dp[i][j] = dp[target][i]+1;
*/
//��ʱ�Ľⷨ,n3��ʱ�临�Ӷ�
int longestArithSeqLength(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 0;
	//�൱����������������nums[k] ,nums[i],nums[j]
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			for (int k = i - 1; k >= 0; k--) {
				if (nums[k] == target) {
					dp[i][j] = dp[k][i] + 1;
					break;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}
//���ù�ϣ����ʱ�临�Ӷ�
int longestArithSeqLength2(vector<int>& nums) {
	int n = nums.size();
	unordered_map<int, int> hashmap;
	/*   for (int i = 0; i < n; ++i)
		   hashmap[nums[i]] = i;*/
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (hashmap.find(target) != hashmap.end()) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//��ϣ����һЩ���õļ�����,�������Լ(n-2)��
int longestArithSeqLength3(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	unordered_map<int, int> hashmap;
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 2;
	hashmap[nums[0]] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (hashmap.find(target) != hashmap.end()) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//��Ŀ˵����0 <= A[i] <= 10000,����������ϣ��
//ʱ�临�ӶȽ�һ���½�
int longestArithSeqLength4(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	/*
	* ȫ�ֱ�������,�Զ���ʼ��Ϊ0
	ע��:�ֲ���������,ֻ��ȫ����ʼ��Ϊ0,������
	����-1ֻ��ѵ�һ����ʼ��Ϊ-1
	memset(hashmap, -1, sizeof(hashmap));
	*/
	int hashmap[10001];
	memset(hashmap, -1, sizeof(hashmap));
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 2;
	hashmap[nums[0]] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (target>=0 && hashmap[target]!=-1) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//��4�Ļ�����,i<n-1,����һЩ�������,�����ٷ�֮91������
int longestArithSeqLength4(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	//dp[i][j]����nums[i],nums[j]Ϊ�Ȳ����еĺ�����Ԫ��
	//�ĵȲ����еĳ���,��ʼ��Ϊ2,��Ϊ������nums[i],nums[j]
	//����Ԫ��
	vector<vector<int> > dp(n, vector<int>(n, 2));
	int hashmap[10001];
	memset(hashmap, -1, sizeof(hashmap));
	hashmap[nums[0]] = 0;
	/*
		target-nums[i]=nums[i]-nums[j]
			target =nums[i]*2-nums[j]
	*/
	int ans = 2;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int target = nums[i] * 2 - nums[j];
			if (target >= 0 && hashmap[target] != -1) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
				ans = std::max(ans, dp[i][j]);
			}
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
void test01()
{

}
int main()
{
	test01();
}
#endif