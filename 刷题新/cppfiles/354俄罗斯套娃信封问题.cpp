#if 0
#include "../headers/wjxHeaders.h"

class Cmp {
public:
    bool operator()(vector<int>& v1, vector<int>& v2) {
        if (v1.front() == v2.front())
            return v1.back() > v2.back();
        return v1.front() < v2.front();
    }
};
//方法1,动态规划,通过,执行用时1588ms,超过百分之5
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    vector<int> dp(n, 1);
    sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2)->bool {
        return v1.front() < v2.front();
        });
    int maxlen = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
        maxlen = std::max(dp[i], maxlen);
    }
    return maxlen;
}
//方法2,失败了
int maxEnvelopes2(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    if (n <= 0)
        return n;
    vector<vector<int>> stk;
    sort(envelopes.begin(), envelopes.end(),Cmp());
    stk.push_back(envelopes[0]);

    for (int i = 1; i < n; ++i) {
        if (envelopes[i][0] > stk.back()[0] )
            stk.push_back(envelopes[i]);
        else {
            for (int j = 0; j < stk.size(); ++j) {
                if (stk[j][0] >= envelopes[i][0]) {
                    stk[j] = envelopes[i];
                    break;
                }
              
               
            }
        }//else

    }
    return stk.size();
}
//leetcode 题解
/*
按照w值升序,按照h值降序排
*/
int maxEnvelopes3(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    if (n <= 0)
        return n;
    vector<vector<int>> stk;
    sort(envelopes.begin(), envelopes.end(), Cmp());
    stk.push_back(envelopes[0]);

    for (int i = 1; i < n; ++i) {
        if (envelopes[i][1] > stk.back()[1])
            stk.push_back(envelopes[i]);
        else {
            for (int j = 0; j < stk.size(); ++j) {
                if (stk[j][1] >= envelopes[i][1]) {
                    stk[j] = envelopes[i];
                    break;
                }


            }
        }//else

    }
    return stk.size();
}
int search_right(vector<int> stk, int target) {
    int left = 0, right = stk.size(), mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (stk[mid] == target)
            left = mid + 1;
        else if (stk[mid] < target)
            left = mid + 1;
        else if (stk[mid] > target)
            right = mid;
    }
    if (left > 0 && stk[left - 1] == target)
        return left - 1;
    return left;
}
//stk仍然可以像300题那样,一维即可,只保存信封的高度(第二个值),当时在排序的情况下
int maxEnvelopes4(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    if (n <= 0)
        return n;
    vector<int> stk;
    sort(envelopes.begin(), envelopes.end(), Cmp());
    stk.push_back(envelopes[0][1]);

    for (int i = 1; i < n; ++i) {
        if (envelopes[i][1] > stk.back())
            stk.push_back(envelopes[i][1]);
        else {
            int pos = search_right(stk, envelopes[i][1]);
            stk[pos] = envelopes[i][1];

            }
        }//else

    return stk.size();
}
//在4的基础上,利用lower_bound,不用自己写函数了
int maxEnvelopes5(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    if (n <= 0)
        return n;
    vector<int> stk;
    sort(envelopes.begin(), envelopes.end(), Cmp());
    stk.push_back(envelopes[0][1]);

    for (int i = 1; i < n; ++i) {
        if (envelopes[i][1] > stk.back())
            stk.push_back(envelopes[i][1]);
        else {
            auto cur = lower_bound(stk.begin(), stk.end(), envelopes[i][1]);
            *cur = envelopes[i][1];

        }
    }//else

    return stk.size();
}
//在5的基础上,把lower_bound改成顺序遍历数组,找到大于等于目标元素的数组
int maxEnvelopes5(vector<vector<int>>& envelopes) {
    int n = envelopes.size();//一共有n个信封
    if (n <= 0)
        return n;
    vector<int> stk;
    sort(envelopes.begin(), envelopes.end(), Cmp());
    stk.push_back(envelopes[0][1]);

    for (int i = 1; i < n; ++i) {
        if (envelopes[i][1] > stk.back())
            stk.push_back(envelopes[i][1]);
        else {
            for (int j = 0; j < stk.size(); ++j) {
                if (stk[j] >= envelopes[i][1]) {
                    stk[j] = envelopes[i][1];
                    break;
                }
            }

        }
    }//else

    return stk.size();
}
void test01()
{
    vector<vector<int>>nums{ {2, 100}, {3, 200},
        {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370},
        {6, 360}, {7, 380} };
    //sort(nums.begin(), nums.end(), [](vector<int>& v1, vector<int>& v2)->bool {
    //    return v1.front() < v2.front();
    //    });
    //printvectorvector(nums);
    cout << maxEnvelopes2(nums) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif