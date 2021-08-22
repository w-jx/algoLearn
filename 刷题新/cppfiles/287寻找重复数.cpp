#if 0
#include "../headers/wjxHeaders.h"

/*
*二分查找的方法:
cnt[i]代表nums数组中小于i的数有多少个
重复的数是target
[1,target-1] 所有数都cnt[i]<=i
[target,n] 所有数都cnt[i]>i 具有单挑性

对于n+1个元素的数组,数字都在[1,n]之间,target出现了两次
对于小于target的数i,一定有cnt[i]=i
对于大于target的数j,一定有cnt[j]=j+1;

对于target出现了三次以上,有些数不在数组里,相当于用target
替换了这些数,
如果替换的数i小于target,那么[i,target-1]的cnt值均减少1,其他不变
	本来因为是数i,数i到target-1的数都比数i大于等于,对cnt有一次贡献
	现在数i变成target了,数i的共享没了,所以cnt的值减少1



如果替换的数j大于等于target,那么[target,j-1]的cnt值均增加1,其他不变
	本来是数j,从target,j-1都比j小,所以j对target,j-1没有共享cnt值
	现在换成了比target,[target,j-1]都比target大于等于,所以cnt值加1


*/
//要找的那个位置处于cnt[i]>i
//二分是对值域进行二分而不是数组的索引，每次缩小值域的上界或者扩大下界，
//直到值域只剩下一个值，那么该值就是重复值。
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    //数字从1到n-1
    int left = 1, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += nums[i] <= mid;
        }
        if (cnt <= mid) {
            left = mid + 1;//重复的数比mid要大
        }
        else {//cnt>mid  重复数字
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