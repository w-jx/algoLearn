#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
/*
执行用时，560ms.我发现我这个用的是单索引
*/
int minSubArrayLen(int target, vector<int>& nums) {
	
    int len = nums.size();
    int i = 0, min = INT_MAX, sum = 0;
    bool isFind = false;
    for (int j = 0; j < len; j++) {
        sum += nums[j];
        if (sum >= target) {
            
			if ((j - i) < min)
				min = j - i + 1;
			isFind = true;

			sum = 0;
			j = i;
			i += 1;
        }
    }
    if (isFind)
        return min;
    return 0;
	
}
int minSubArrayLen2(int target, vector<int>& nums) {

    int len = nums.size();

    int begin = 0, end = 0,sum=0,min=len+1;
    while (end < len) {
        sum += nums[end];
        if (sum >= target) {
            if (end - begin +1< min)
                min = end - begin+1;
            sum -= nums[begin];
            sum -= nums[end];
            begin++;
        }
        else {
            end++;
        } 
    }
   
    return min == len+1 ? 0 : min;
}
int minSubArrayLen3(int target, vector<int>& nums) {
    int len = nums.size();
    int i = 0, j = 0, sum = 0, n = len+1;

    while (j < len) {
        sum += nums[j];
        if (sum < target)
            j++;
        else {
            if (j - i + 1 < n)
                n = j - i + 1;
            sum -= nums[i];
            sum -= nums[j];
            i++;
        }
    }
    return n == len ? 0 : n;

}
void test01()
{
	vector<int> nums = { 1,2,3,4,5 };
	//cout << minSubArrayLen(11, nums) << endl;
    cout << minSubArrayLen3(15, nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif