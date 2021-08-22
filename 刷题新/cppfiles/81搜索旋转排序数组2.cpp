#if 0
#include "../headers/wjxHeaders.h"
using namespace std;

//这一题要先看第33题目，唯一的区别在于这边多了重复的判断
bool search(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		//mid值的情况，第一种是和left在一个数组；第二种，left在数组1，mid在数组2
		//可以通过nums[mid]   nums[left] 大小判断是情况1，还是情况2
		if (nums[mid] == target) return true;
		if (nums[mid] == nums[left]) {
			left++;
			continue;
		}

		if (nums[mid] > nums[left]) {//left,mid在同一个数组里面
			if (target >= nums[left] && target < nums[mid]) //目标在[nums[left],nums[mid])之间
				right = mid - 1;//进一步缩小空间
			else if (target > nums[mid] || target < nums[left]) {
				//target 落在right 和mid 之间  ，可能在第一个数组，也可能在第二个数组
				//例如 4，5，6，7，8  | 0，1，2  mid指向的元素为7
				//如果target 是8，那么大于nums[mid]，在第一个数组中
				//如果target 是1，那么小于nums[left]，在第二个数组中
				left = mid + 1;
			}

		}
		else if (nums[mid] < nums[left]) { //left在数组1，mid在数组2中
			if (target <= nums[right] && target > nums[mid]) {
				left = mid + 1;//进一步缩小区间
			}
			else if (target > nums[right] || target < nums[mid]) {
				//还是两种情况，第一种，target比数组2中最大的都大了，说明target 落在了数组1中
				//第二种，target 比nums[mid]小，也可能落在数组2中
				//不管哪一种，都要把右侧指针减小
				right = mid - 1;

			}
		}

	}
	return false;
}


int main(void)
{



	system("pause");
	return 0;

}
#endif