#if 0
#include "../headers/wjxHeaders.h"


//暴力解法，时间复杂度太高了
int maxArea(vector<int>& height) {
	int len = height.size();
	if (len <= 1)
		return 0;

	int maxSquare = 0;
	for (int i = 0; i < len-1; i++) {
		for (int j = len - 1; j > 0; j--) {
			auto currentHeight = min(height[i], height[j]);
			auto currentWidth = j - i;
			auto currentSquare = currentHeight * currentWidth;
			if (currentSquare > maxSquare)
				maxSquare = currentSquare;
		}
	}
	return maxSquare;
}
//方法1 双指针 
int maxArea2(vector<int>& height)
{
	int len = height.size();

	int i = 0, j = len - 1,maxsquare=0;
	while (i < j) {
		auto square = min(height[i], height[j]) * (j - i);
		if (square > maxsquare)
			maxsquare = square;

		if (height[i] < height[j]) {
			i++;
		}
		else
			j--;
	}
	return maxsquare;
	
}
void test01()
{
	vector<int> v{ 1,2,1 };
	cout << maxArea2(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif