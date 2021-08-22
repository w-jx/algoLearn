#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecodeÃ‚ƒøΩÈ…‹:


*/
int getbitNum(int a) {
	return to_string(a).size();
}
int getbitsum(int a) {
	auto str = to_string(a);
	return accumulate(str.begin(), str.end(), 0) - str.size() * '0';
}
int getSum(int a, int b) {
    auto stra = to_string(a);
    auto strb = to_string(b);
    return accumulate(stra.begin(), stra.end(), 0) - stra.size() * '0' +
        accumulate(strb.begin(), strb.end(), 0) - strb.size() * '0';
}

int movingCount(int m, int n, int k) {
    vector<vector<int>> visit(m, vector<int>(n));
    int res = 1;
    queue<std::pair<int, int> > que;
    que.push({ 0,0 });
    visit[0][0] = 1;
    static int dx[] = { -1,1,0,0 };
    static int dy[] = { 0,0,-1,1 };
    while (!que.empty()) {
        auto x = que.front().first;
        auto y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && visit[newx][newy] == 0 && getSum(newx, newy) <= k) {
                que.push({ newx,newy });
                ++res;
                visit[newx][newy] = 1;
            }
        }//for

    }//while 

    return res;
}
void test01()
{
	int a = 13;
	cout << getbitsum(a) << endl;


}
int main()
{
	test01();
	
	return 0;
}
#endif