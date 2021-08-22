#if 0
#include "../headers/wjxHeaders.h"

//我这个没看清楚题意,我只是返回了新数组的大小,没有修改数组
int compress(vector<char>& chars) {
    if (chars.empty())
        return 0;
    int ret = 0;
    int times = 1;
    int n = chars.size();
    for (int i = 1; i < n; ++i) {
        if (chars[i] == chars[i - 1]) {
            ++times;
        }
        else {
            ++ret;
            if (times>1)
                ret += to_string(times).size();
            times = 1;
        }
    }
    ret++;
    if (times > 1)
        ret += to_string(times).size();
   

    return ret;
}
//通过
int compress2(vector<char>& chars) {
    if (chars.empty())
        return 0;
    int ret = 0;
    int times = 1;
    int n = chars.size();
    int newidx = 0;//新数组的赋值下标
    char cur = chars[0];//当前正处理的字符
    for (int i = 1; i < n; ++i) {
        if (chars[i] == chars[i - 1]) {
            ++times;
        }
        else {
            chars[newidx++] = cur;
            cur = chars[i];//修改当前处理的字符
            ++ret;
            if (times > 1) {
                string lenstr = to_string(times);
                for (auto ch : lenstr) {
                    chars[newidx++] = ch;
                    ++ret;
                }
            }
            times = 1;
        }
    }
    ret++;
    chars[newidx++] = cur;
    if (times > 1) {
        string lenstr = to_string(times);
        for (auto ch : lenstr) {
            chars[newidx++] = ch;
            ++ret;
        }
    }

    return ret;
}
void test01()
{
    vector<char> a { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
    vector<char> b{ 'a'};
    vector<char> c{ 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    cout << compress2(c) << endl;
}
int main()
{
	test01();
}
#endif