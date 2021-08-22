#if 0
#include "../headers/wjxHeaders.h"


struct GraphNode {
	int val;
	vector<GraphNode*> neighbour;
	GraphNode(int _val) :val(_val) {}
};
/*
* 方法1
转化成图的邻接矩阵,问题就和岛屿数量一模一样了!


//广度优先搜索


方法2:用并查集 ,合并有联系的城市,返回并查集的个数
*/
void dfs_graph(int u, vector<vector<int>>& graph, vector<int>& visit)
{
	visit[u] = 1;//第u个省份被访问了

	//第U个省份,和其他的几个省会进行检查 是否联通
	for (int i = 0; i < graph[u].size(); ++i) {
		if (visit[i]==0 && graph[u][i] == 1)//如果第i个省份没访问,而且u和i还连通
			dfs_graph(i, graph, visit);
	}
}
//1.深搜
int findCircleNum(vector<vector<int>>& isConnected) {
	vector<int> visit(isConnected.size(), 0);//代表该省份的访问情况
	int count = 0;//最终的城市数

	for (int i = 0; i < isConnected.size(); ++i) {
		if (visit[i] == 0  ) {
			dfs_graph(i, isConnected, visit);
			++count;
		}
	}
	return count;
}
//2.广搜
int findCircleNum(vector<vector<int>>& isConnected) {

	int n = isConnected.size();
	
	int res = 0;
	vector<int> visit(n);
	queue<int> que;
	for (int i = 0; i < n; ++i) {
		if (visit[i] == 0) {
			que.push(i);
			while (!que.empty()) {
				auto idx = que.front();
				que.pop();
				visit[idx] = 1;
				for (int j = 0; j < n; ++j) {
					if (isConnected[idx][j] == 1 && visit[j] == 0) {
						que.push(j);
					}//if
				}//for j
			}//while
			++res;
		}//if visit[i]
	}
	return res;
}
//方法2 并查集来实现
//并查集 森林实现
class DisJointSet {
public:
	DisJointSet(int n) {
		for (int i = 0; i < n; ++i) {
			_id.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int p) {
		while (p != _id[p]) {
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return p;
	}
	void union_(int p, int q) {
		int proot = find(p);
		int qroot = find(q);
		if (proot == qroot)
			return;
		//proot子树的规模比 qroot的子树规模小
		if (_size[proot] < _size[qroot]) {
			_id[proot] = qroot;
			_size[qroot] += _size[proot];
		}
		else {//proot子树的规模 大于等于  qroot子树的规模
			_id[qroot] = proot;
			_size[proot] += _size[qroot];
		}
		_count--;
	}
	int count()const {
		return this->_count;
	}

private:
	vector<int> _id;
	vector<int> _size;//子树的规模
	int _count;//几个集合
};
int findCircleNum(vector<vector<int>>& isConnected) {
	DisJointSet disjoint_set(isConnected.size());
	for (int i = 0; i < isConnected.size(); ++i) {
		for (int j = i + 1; j < isConnected.size(); ++j) {
			if (isConnected[i][j])
				disjoint_set.union_(i, j);
		}
	}
	return disjoint_set.count();

}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif