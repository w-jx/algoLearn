#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

哈希表的方法等待学习哈希表在写

*/
string replaceSpace(string s) { //STL 自带接口解决

    int i = 0;
    string sRet = "";
    auto len = s.size();
    int index = 0;
    while (i < len) {
        if (s[i] == ' ') {
            sRet.append(s.begin() + index, s.begin() + i);
            sRet.append("%20");
            index = i + 1;
        }
           
        i++;
    }
    
    sRet.append(s.begin() + index, s.end());
    return sRet;
   
}
string replaceSpace2(string s) { //其他方法解决

    auto len = s.size();
    auto len1 = s.size();
    for (auto c : s) { //统计空格数量
        if (c == ' ') len1 += 2;
    }
    s.resize(len1);
    auto j = 0;
    auto i = 0;
    for (j = s.size() - 1, i = len - 1; i >= 0; i--, j--) {
        if (s[i] != ' ') 
            s[j] = s[i];
        else {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
       
    }
    return s;


}
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> a;//建立hash表存放数组元素
    vector<int> b(2, -1);//存放结果
    for (int i = 0; i < nums.size(); i++)
        a.insert(map<int, int>::value_type(nums[i], i));
    for (int i = 0; i < nums.size(); i++)
    {
        if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
            //判断是否找到目标元素且目标元素不能是本身
        {
            b[0] = i;
            b[1] = a[target - nums[i]];
            break;
        }

        
    }
    return b;
};

void test01()
{
    //string s = "We are happy.";
    //cout << replaceSpace2(s);

    vector<int> s = { 2,7,11,15 };
    printVector(twoSum(s, 9));

   
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif