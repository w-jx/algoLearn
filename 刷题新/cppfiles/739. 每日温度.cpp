#if 0
#include "../headers/wjxHeaders.h"
//暴力解法,超时
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (temperatures[j] > temperatures[i]) {
				res[i] = j - i;
				break;
			}
		}
	}
	return res;

}
//想怎么优化时间复杂度,仍然超时了
//[73, 74, 75, 71, 69, 72, 76, 73]
vector<int> dailyTemperatures2(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    //rightMax[i]代表temperatures[i]后面最大的元素下标
    //rightMax[n-1]=n,代表没有
    vector<int> rightMax(n, n);

    for (int i = n - 2; i >= 0; --i) {
        if (temperatures[i] < temperatures[i + 1]) {
            res[i] = 1;
            rightMax[i] = i + 1;
        }
        else if (temperatures[i] == temperatures[i + 1]) {
            if (res[i + 1] == 0)
                res[i] = 0;
            else
                res[i] = res[i + 1] + 1;
            rightMax[i] = rightMax[i + 1];
        }
        else { //大于的情况
            for (int j = rightMax[i + 1]; j < n; ++j) {
                if (temperatures[i] < temperatures[j]) {
                    res[i] = j - i;
                    rightMax[i] = j;
                    break;
                }
            }
        }
    }
    return res;

}
//去除相邻的时候相等的情况的判断,添加 j = rightMax[j];通过
vector<int> dailyTemperatures3(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    //rightMax[i]代表temperatures[i]后面最大的元素下标
    //rightMax[n-1]=n,代表没有
    vector<int> rightMax(n, n);

    for (int i = n - 2; i >= 0; --i) {
        if (temperatures[i] < temperatures[i + 1]) {
            res[i] = 1;
            rightMax[i] = i + 1;
        }
        else { 
            if (rightMax[i + 1] == n)
                continue;
            //大于的情况
            for (int j = rightMax[i + 1]; j < n;) {
                if (temperatures[i] < temperatures[j]) {
                    res[i] = j - i;
                    rightMax[i] = j;
                    break;
                }
                else {//temperatures[i] >= temperatures[j]
                    j = rightMax[j];
                    if (j == n)
                        break;
                }
            }
        }
    }
    return res;
}
/*
答案题解:单调栈
存储下标,下标对应的温度依次递减
如果一个下标在单调栈里,表示还没有找到下一次温度更高的下标

遍历,对于每个元素temp[i],栈为空,直接进栈
比较当前栈顶topIdx对应的温度值tempTop和temp[i]
1.
    temp[i]>tempTop


*/
vector<int> dailyTemperatures4(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> s;
    vector<int> res(n);

    for (int i = 0; i < n; ++i) {
        if (s.empty())
            s.push_back(i);
        else {
            while (!s.empty() && temperatures[s.back()] < temperatures[i]) {
                res[s.back()] = i - s.back();
                s.pop_back();
            }
            s.push_back(i);
        }
    }
    return res;
    
}
void test01()
{
	// [1, 1, 4, 2, 1, 1, 0, 0]。
	//1 1 0 4 1 1 0 0
	vector<int> temp{ 73, 74, 75, 71, 69, 72, 76, 73 };
	//[8,1,5,4,3,2,1,1,0,0]
	vector<int> temp1{ 89,62,70,58,47,47,46,76,100,70 };
	auto ret = dailyTemperatures2(temp1);
	printVector(ret);
}
int main()
{
	test01();
}


#endif