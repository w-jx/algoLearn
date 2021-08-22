#if 0
#include "../headers/wjxHeaders.h"


//用单调栈的想法没有错,但是最后处理总是越界,或者错误
int nextGreaterElement(int n) {
    string nstr = to_string(n);
    int len = nstr.size();//有多少个数字
    vector<int> ret(len, -1);
    vector<int> stk;
    stk.reserve(len);

    for (int i = 0; i < len; ++i) {
        while (!stk.empty() && nstr[stk.back()] < nstr[i]) {
            ret[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    auto iter = find_if(ret.rbegin(), ret.rend(), [=](int x)->bool {return x != -1; });
    if (iter == ret.rend())
        return n;
    int idx = ret.rend() - iter - 1;
    swap(nstr[idx], nstr[ret[idx]]);//进行交换,肯定比原来大了
    //但是我们需要保证后面idx,代表的数尽可能小
    ++idx;
    while (idx < len - 1) {
        if (nstr[idx] > nstr[idx + 1]) {
            swap(nstr[idx], nstr[idx + 1]);
        }
        ++idx;
    }
    long long nretll = stoll(nstr);
    if (nretll > INT_MAX)
        return -1;
    return nretll;
}
//答案题解思路
int nextGreaterElement2(int n) {
    string nstr = to_string(n);
    int len = nstr.size();//有多少个数字
    if (len < 2)//1个或者0个,找不到,字节返回-1
        return -1;
    //先找到最小的数字
    int i = len - 2;
    for (; i >= 0; --i) {
        if (nstr[i] < nstr[i + 1])
            break;
    }
    if (i < 0)//找不到左边比右边小的,数组递减,已经是最大了
        return -1;
    //找比nstr[i]略大的数字
    int j = len - 1;
    for (; j >= 0; --j) {
        if (nstr[j] > nstr[i]) {
            swap(nstr[j], nstr[i]);
            break;
        }
    }
    //反转从i+1开始的数组
    reverse(nstr.begin() + i + 1, nstr.end());
    long res = stol(nstr);
    return res > INT_MAX ? -1 : res;
}
void test01()
{
    //vector<int> ret{ 1,2,3,4,-1 ,-1};
    //auto iter = find_if(ret.rbegin(), ret.rend(), [=](int x)->bool {return x != -1; });
    //int idx =  ret.rend()- iter-1;
    //cout << idx << endl;
    //
    cout << nextGreaterElement2(2147483476) << endl;
}
int main()
{
	test01();
}
#endif