#if 0
#include "../headers/wjxHeaders.h"
/*
ǰ׺��
*/
/*
������д��ǰ׺�ͷ���,��Ȼ�õ���ǰ׺��
ʱ�临�Ӷ���Ȼ��O(n^2),�ռ临�Ӷ�O(n)
��Ȼ�ǳ�ʱ��
*/
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> segmentSum(n);
    segmentSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        segmentSum[i] = nums[i] + segmentSum[i - 1];
    }
    int cnt = 0;
    if (segmentSum[0] == k)
        ++cnt;
    for (int i = 1; i < n; ++i) {
        if (segmentSum[i] == k)
            ++cnt;
        for (int j = 0; j < i; ++j) {
            if (segmentSum[i] - segmentSum[j] == k)
                ++cnt;
        }
    }//
    return cnt;
}
/*
ǰ׺�ͼ�hashmap
/ϸ�ڣ�������ҪԤ��ǰ׺��Ϊ 0 ���������©��ǰ��λ����������
        //��������[1,1,0]��k = 2 ���û�����д��룬��᷵��0,©����1+1=2����1+1+0=2�����
        //���룺[3,1,1,0] k = 2ʱ�򲻻�©��
        //��Ϊpresum[3] - presum[0]��ʾǰ�� 3 λ�ĺͣ�������Ҫmap.put(0,1),���µ�

     pre[i]�����±�i��ǰ׺��
     pre[i]=pre[i-1]+nums[i],�ǵ��±�i-1��ǰ׺�ͼ�nums[i]

     �����j-i�����������Ϊk
     �� pre[i]-pre[j-1]=k;��ΪҪ����nums[j]������j-1
     ���ǿ���ͨ������õ�������������͵���k���±�j��ֵ
     pre[j-1]=pre[i]-k,pre[i]�ǵ���ǰԪ�ص�ǰ׺��
     Ȼ�������ж�hashmap���Ƿ���pre[i]-k,�Ϳ���֪��������������
     �Ƿ����k,����pre[j-1]�Ĵ�������
     

*/
int subarraySum1(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hashmap;
    hashmap.insert({ 0,1 });//��ֹk==nums[i]
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        //��ǰ��ǰ׺��Ϊsum,�����sum-k��ǰ׺��,�����Ǿ���
        //ȷ���������ǰ׺����k,���Ƿ���Ҫ���
        if (hashmap.count(sum - k) > 0)
            cnt += hashmap[sum - k];

        hashmap[sum]++;
    }

    return cnt;
}
void test01()
{
    vector<int> nums{ 3,4,7,2,-3,1,4,2 };
    cout<<subarraySum1(nums,7) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif