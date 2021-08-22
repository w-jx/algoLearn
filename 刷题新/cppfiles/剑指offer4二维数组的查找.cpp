#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÃ‚ƒøΩÈ…‹:


*/
bool isInArray(vector<int>& nums, int target)
{
	int len = nums.size();
	int left = 0, right =len - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return true;
		else if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid - 1;
	}
	return false;
}
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	int row = matrix.size(),col=0;
	if (row == 0) return false;
	int i = 0;
	while (i< row) {
		if (!matrix[i].empty()) {
			col = matrix[i].size();
			break;
		}
		i++;
	}
		
	for (int i = 0; i < row; i++) {
		if (matrix[i].empty()) continue;
		if (matrix[i][0] > target) return false;
		else if (matrix[i][0] < target && matrix[i][col - 1] < target) {
			continue;
		}
		else if (matrix[i][0]<=target && matrix[i][col - 1]>=target) {
			bool flag = isInArray(matrix[i], target);
			if (flag)
				return true;
		}
	}
	return false;

}
void test01()
{
	vector<vector<int> > v{
		{1,   4,  7, 11, 15} ,
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30 }
	};
	vector<vector<int> > v1{ {-5} };
	vector<vector<int> > v2{  };
	cout << findNumberIn2DArray(v, 5) << endl;
	//cout << findNumberIn2DArray(v1, -5) << endl;
	//cout << findNumberIn2DArray(v2, 0) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif