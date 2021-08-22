#if 0
#include "../headers/wjxHeaders.h"

/*
*���ֲ��ҵķ���:
cnt[i]����nums������С��i�����ж��ٸ�
�ظ�������target
[1,target-1] ��������cnt[i]<=i
[target,n] ��������cnt[i]>i ���е�����

����n+1��Ԫ�ص�����,���ֶ���[1,n]֮��,target����������
����С��target����i,һ����cnt[i]=i
���ڴ���target����j,һ����cnt[j]=j+1;

����target��������������,��Щ������������,�൱����target
�滻����Щ��,
����滻����iС��target,��ô[i,target-1]��cntֵ������1,��������
	������Ϊ����i,��i��target-1����������i���ڵ���,��cnt��һ�ι���
	������i���target��,��i�Ĺ���û��,����cnt��ֵ����1



����滻����j���ڵ���target,��ô[target,j-1]��cntֵ������1,��������
	��������j,��target,j-1����jС,����j��target,j-1û�й���cntֵ
	���ڻ����˱�target,[target,j-1]����target���ڵ���,����cntֵ��1


*/
//Ҫ�ҵ��Ǹ�λ�ô���cnt[i]>i
//�����Ƕ�ֵ����ж��ֶ����������������ÿ����Сֵ����Ͻ���������½磬
//ֱ��ֵ��ֻʣ��һ��ֵ����ô��ֵ�����ظ�ֵ��
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    //���ִ�1��n-1
    int left = 1, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += nums[i] <= mid;
        }
        if (cnt <= mid) {
            left = mid + 1;//�ظ�������midҪ��
        }
        else {//cnt>mid  �ظ�����
            right = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif