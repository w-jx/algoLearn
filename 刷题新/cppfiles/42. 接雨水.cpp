#if 0
#include "../headers/wjxHeaders.h"

//自己做,没做出来
int trap(vector<int>& height) {
    if (height.empty())
        return 0;
    int n = height.size();
    deque<int> s;
    int cnt = 0;
    s.push_back(height[0]);
    bool last_is_bigger = false;
    for (int i = 1; i < n;++i ) {
        if (height[i] > s.back()) {
            s.push_back(height[i]);
            last_is_bigger = true;
        }
        else if (height[i] <= s.back()) {
            s.push_back(height[i]);
            //开始计算雨水数量
            if (last_is_bigger) {
                int base = s[0];
                while (s.size() > 1) {
                }              
            }
            last_is_bigger = false;
        }         
    }

    return cnt;
}
/*
答案题解1:动态规划
下标i
下雨后雨水达到的最大高度等于下标i两边的最大高度的较小的那个
能接的雨水量 等于下标i处的水能达到的最大高度 减去 height[i]

朴素的做法,对于每个元素,分别向左,向右扫描并记录左边和右边的最大高度
然后计算每个下标位置能接的雨水量

通过!

*/
//时间复杂度o(n^2),空间复杂度o(1)
int trap1(vector<int>& height) {
    if (height.empty())
        return 0;

    int cnt = 0;
    int n = height.size();
    int leftMax = INT_MIN, rightMax = INT_MIN;
    for (int i = 1; i < n - 1; ++i) {
        leftMax = INT_MIN, rightMax = INT_MIN;
        for (int j = 0; j < i; ++j) {
            leftMax = std::max(leftMax, height[j]);
        }
        for (int j = i + 1; j < n; ++j)
            rightMax = std::max(rightMax, height[j]);

        cnt += std::max(0, std::min(leftMax, rightMax) - height[i]);
    }
    return cnt;
}
//O(n^2)来源找左右两侧最大值,利用动态规划
//提前进行预处理,可以在o(1)的时间得到结果,整体时间复杂度o(n),空间复杂度o(n)
int trap1_upgrade(vector<int>& height) {
    if (height.empty())
        return 0;
    int cnt = 0;
    int n = height.size();
    //leftMax[i]代表height[i]左侧的最大值
    //rightMax[i]代表height[i]右侧的最大值
    vector<int> leftMax(n),rightMax(n);
    leftMax[0] = leftMax[n - 1] = INT_MIN;
    rightMax[0] = rightMax[n - 1] = INT_MIN;

    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i - 1]);
    }
    for (int i = n-2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i + 1]);
    }
    for (int i = 1; i < n - 1; ++i) {
        cnt += std::max(0, std::min(leftMax[i], rightMax[i]) - height[i]);
    }
    return cnt;
}/*
 答案题解方法2:单调栈
 单调栈存储下标,满足从栈底到栈顶的下标对应的数组元素递减
 
 遍历到下标i的时候
 如果栈内元素有2个,栈顶top,栈顶下left

 height[left]>=height[top]

 如果height[i]>height[top],则得到一个可以接雨水的区域
 宽度:i-left-1
 高度:

 难以理解,暂时先放一放
 */
int trap2(vector<int>& height) {
    if (height.empty())
        return 0;


 
}
/*
答案题解3:双指针方法
leftMax从左往右计算,rightMax从右往左边计算可以使用双指针代替数组

两个指针:left,right
两个变量:leftMax,rightMax
left = 0,right=n-1
leftMax = 0,rightMax = 0
left只右移,rightMax只左移,移动指针的过程维护变量的值

两个指针没有相遇:
利用height[left],height[right]的值
更新leftMax,rightMax

1.height[left]<height[right]
必然有leftMax<rightMax
下标left能接的水雨水量为:leftMax-height[left]
left+1
2.height[left]>=height[right],leftMax>=rightMax
下标right能接的水量:rightMax - height[right],right-1

两个指针相遇的时候,就能得到最终结果

*/
int trap3(vector<int>& height) {
    if (height.empty())
        return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    while (left < right) {
        leftMax = std::max(leftMax, height[left]);
        rightMax = std::max(rightMax, height[right]);
        if (leftMax < rightMax) {
            ans += leftMax - height[left++];
        }
        else {
            ans += rightMax - height[right--];
        }
    }
    return ans;
}
void test01()
{
    vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << trap1(height) << endl;

}
int main()
{
	test01();
}
#endif