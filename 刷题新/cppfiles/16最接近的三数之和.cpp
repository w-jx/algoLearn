#if 0
#include "../headers/wjxHeaders.h"

int threeSum(vector<int>& nums, int target) {
	if (nums.size() < 2)
		return {};
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int retval = 0, extra = INT_MAX;

	for (int i = 0; i < n - 2; ++i) {

		int first = i + 1;
		int last = n - 1;

		while (first < last) {

			int sum = nums[i] + nums[first] + nums[last];
			if (sum == target) {
				return target;

			}
			else if (sum < target) {
				//firstÇ°½ø
				if (target - sum < extra) {
					extra = target - sum;
					retval = sum;
				}
				++first;
			}
			else if (sum > target) {
				//last ºóÍË
				if (sum - target < extra) {
					extra = sum - target;
					retval = sum;
				}
				--last;

			}


		}//while first<last;
	}//i<n-2;

	return retval;
}
void test01()
{
	vector<int> nums{ 1,1,1,1 };
	cout << threeSum(nums, 0) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif