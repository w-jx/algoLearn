#if 0
#include "../headers/wjxHeaders.h"

vector<int> exchange(vector<int>& nums) {
    int len = nums.size();
    int left = 0, right = len - 1;
    while (left < right) {
        if (nums[left] % 2 == 0) {
            while (right>left && nums[right] % 2 == 0 ) {
                right--;

            }
            swap(nums[left], nums[right]);
        }
        left++;
    }
    return nums;
}
void test01()
{
    vector<int> v{ 2,4,6 };
    printVector(exchange(v));
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif