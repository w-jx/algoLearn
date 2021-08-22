#if false
#include "./headers/wjxHeaders.h"


int longestValidParentheses(string s) {
    int n = s.size();
    if (n < 2)
        return  0;
    char last = s[0];
    int cur = 0;
    int maxlen = 0;
    for (int i = 0; i < n; ) {
     
    }
    if (maxlen % 2 != 0)
        --maxlen;
    return maxlen;

}
void test01()
{

}
void main()
{
	test01();
}



#endif 