#if 0
#include "../headers/wjxHeaders.h"

int findContentChildren(vector<int>& g, vector<int>& s) {
    if (s.empty())
        return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int num = 0;
    for (int i = 0, j = 0; i < g.size()&& j < s.size();) {
        if (s[j] >= g[i]) {
            ++num;
            ++i;
            ++j;
        }
        else {
            ++j;
        }
    }
    return num;
}
void test01()
{
    vector<int> g{ 1,2 };
    vector<int> s{ 1,2,3 };
    int a = findContentChildren(g, s);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif