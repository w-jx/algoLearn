#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

我的答案是错的  
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。(要同时完成,而不是完成任意一个)
并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

*/


bool dfs_Graph(GraphNode* node, vector<int>& visit, vector<int>& path)
{
	visit[node->val] = 0;
	

	for (int i = 0; i < node->neighbors.size(); ++i) {
		if (visit[node->neighbors[i]->val] == -1) {
			if (!dfs_Graph(node->neighbors[i], visit, path))
				return false;
		}
		else if (visit[node->neighbors[i]->val] == 0)
			return false;
	}
	visit[node->val] = 1;
	path.push_back(node->val);//确保这个顶点被访问了,再加入路径
	return true;
	
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	//1.构造图的数据结构
	vector<GraphNode*> vec_node(numCourses);
	for (int i = 0; i < numCourses; ++i) {
		vec_node[i] = new GraphNode(i);
	}
	for (int i = 0; i < prerequisites.size(); ++i) {
		vec_node[prerequisites[i].back()]->neighbors.push_back(vec_node[prerequisites[i].front()]);
	}

	vector<int> visit(numCourses, -1);
	vector<int> path;//存储最后的学习顺序

	bool retflag = true;
	for (int i = 0; i < numCourses; ++i) {
		if (visit[vec_node[i]->val] == -1) {
			if (!dfs_Graph(vec_node[i], visit, path)) {//无法学完所有课程
				retflag = false;
				break;
			}
		}
	}//for

	for (int i = 0; i < numCourses; ++i)
		delete vec_node[i];

	if (retflag) {
		reverse(path.begin(), path.end());//最先经过的顶点最后才出现在数组中,所以要逆序下
		return path;
	}
	return {};

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