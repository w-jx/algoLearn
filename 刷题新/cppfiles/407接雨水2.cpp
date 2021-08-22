#if 0
#include "../headers/wjxHeaders.h"
/*

问题标签:广度优先搜索
*/

//1.第一步,优先级队列放置自定义数据结构,并自定义比较函数
struct Qitem {
	int x;
	int y;
	int h;
	Qitem(int _x, int _y, int _h) :x(_x), y(_y), h(_h) {}
};
class Cmp {
public:
	bool operator()(const Qitem& a, const Qitem& b) {
		return a.h > b.h;
	}
};

//第二步:实现将数组四周的点添加到优先级队列的代码

int trapRainWater(vector<vector<int>>& heightMap) {
	if (heightMap.size() < 3 || heightMap[0].size() < 3)
		return 0;
	priority_queue<Qitem, vector<Qitem>, Cmp> que;//最小堆

	int row = heightMap.size();//行
	int col = heightMap[0].size();//列
	vector<vector<int>> mark(row, vector<int>(col, 0));//标记数组
	//先标记第一列和最后一列的
	for (int i = 0; i < row; ++i) {
		que.push(Qitem(i, 0, heightMap[i][0]));
		mark[i][0] = 1;
		que.push(Qitem(i, col - 1, heightMap[i][col - 1]));
		mark[i][col - 1] = 1;
	}
	//然后标记 第一行 和最后一行   除了第一列和最后一列的
	for (int i = 1; i < col - 1; i++) {
		que.push(Qitem(0, i, heightMap[0][i]));
		mark[0][i] = 1;
		que.push(Qitem(row - 1, i, heightMap[row - 1][i]));
		mark[row - 1][i] = 1;
	}


	//下面进行搜索
	static const int dx[] = { -1,1,0,0 };//方向数组
	static const int dy[] = { 0,0,-1,1 };

	int res = 0;//最终结果 接水量

	while (!que.empty()) {
		int x = que.top().x;
		int y = que.top().y;
		int h = que.top().h;
		que.pop();
		//上下左右4个方向  扩展
		for (int i = 0; i < 4; ++i) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			//扩展点越界了或者已经遍历过了
			if (newx < 0 || newx >= row || newy < 0 || newy >= col || mark[newx][newy]==1)
				continue;

			if (h > heightMap[newx][newy]) {//当前点高度高于扩展点
				res += h - heightMap[newx][newy];
				heightMap[newx][newy] = h;

			}
			que.push(Qitem(newx, newy, heightMap[newx][newy]));
			mark[newx][newy] = 1;
		}
	}

	return res;
}
void test01()
{
#if true
	priority_queue<Qitem, vector<Qitem>, Cmp> que;
	que.push(Qitem(1, 2, 3));
	que.push(Qitem(0, 2, 2));
	que.push(Qitem(3, 6, 10));

	while (!que.empty()) {
		cout << que.top().h << endl;
		que.pop();
	}
#endif



}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif