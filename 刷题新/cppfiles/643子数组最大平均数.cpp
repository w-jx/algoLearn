#if 0
#include "../headers/wjxHeaders.h"

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.begin() + k , 0);
    int left = 0, right = k - 1;
    int maxval = sum;
    while (right < n) {
        sum -= nums[left];
        left++;
        right++;
        if (right == n)
            break;
        sum += nums[right];
        maxval = std::max(sum, maxval);
    }
    double N = maxval;
    N /= k;
    return N;
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