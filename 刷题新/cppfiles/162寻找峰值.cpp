#if 0
#include "../headers/wjxHeaders.h"

/*
峰值元素是指其值大于左右相邻值的元素。

给你一个输入数组?nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设?nums[-1] = nums[n] = -∞ 。

可以用遍历的方法解决，但是想要用二分查找的方法



****lambda里面不要套递归，

*/
//std::function<int(vector<int>&, int, int)> search;
int search(vector<int>& num, int left, int right) {
    if (left == right)
        return left;
    int mid = (left + right) / 2;
    if (num[mid] > num[mid + 1])
        return search(num, left, mid); //C++ 使用 auto 类型说明符声明的变量不能出现在其自身的初始值设定项中
    else
        return search(num, mid + 1, right);
}

int findPeakElement(vector<int>& nums) {

    return search(nums, 0,nums.size() - 1);
}
void test01()
{
    vector<int> v{ 1,3,5,2,7,9,11,6,8 };
    cout << findPeakElement(v);
}
//void test02()
//{
//    std::function<void(int, int)> myfunction;
//    myfunction = [=](int a, int b) {
//        cout << "a=" << a << ",b=" << b << endl;
//        return;
//    };
//    myfunction(3,5);
//}
int main()
{
    test01();
    //test02();
	system("pause");
	return 0;
}


#endif