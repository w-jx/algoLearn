#if 0
#include "../headers/wjxHeaders.h"


struct GraphNode {
	int val;
	vector<GraphNode*> neighbour;
	GraphNode(int _val) :val(_val) {}
};
/*
* ����1
ת����ͼ���ڽӾ���,����ͺ͵�������һģһ����!


//�����������


����2:�ò��鼯 ,�ϲ�����ϵ�ĳ���,���ز��鼯�ĸ���
*/
void dfs_graph(int u, vector<vector<int>>& graph, vector<int>& visit)
{
	visit[u] = 1;//��u��ʡ�ݱ�������

	//��U��ʡ��,�������ļ���ʡ����м�� �Ƿ���ͨ
	for (int i = 0; i < graph[u].size(); ++i) {
		if (visit[i]==0 && graph[u][i] == 1)//�����i��ʡ��û����,����u��i����ͨ
			dfs_graph(i, graph, visit);
	}
}
//1.����
int findCircleNum(vector<vector<int>>& isConnected) {
	vector<int> visit(isConnected.size(), 0);//�����ʡ�ݵķ������
	int count = 0;//���յĳ�����

	for (int i = 0; i < isConnected.size(); ++i) {
		if (visit[i] == 0  ) {
			dfs_graph(i, isConnected, visit);
			++count;
		}
	}
	return count;
}
//2.����
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
//����2 ���鼯��ʵ��
//���鼯 ɭ��ʵ��
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
		//proot�����Ĺ�ģ�� qroot��������ģС
		if (_size[proot] < _size[qroot]) {
			_id[proot] = qroot;
			_size[qroot] += _size[proot];
		}
		else {//proot�����Ĺ�ģ ���ڵ���  qroot�����Ĺ�ģ
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
	vector<int> _size;//�����Ĺ�ģ
	int _count;//��������
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