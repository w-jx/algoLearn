#if 0
#include "../headers/wjxHeaders.h"
/*

节点访问状态，三种状态
-1 没有访问过，0代表正在访问，1代表已经完成访问

这个就是判断图是否有环的
*/


//leetcode 官方题解
vector<vector<int>> edges;
vector<int> visited;
bool valid = true;

//false 有环  true 无环
bool dfs_graph(GraphNode* node, vector<int>& visit)
{
	visit[node->val] = 0;//代表正在访问
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->val] == -1) {//尚未访问
			if (!dfs_graph(node->neighbors[i], visit))//对当前结点的 临接结点也进行深度搜索,看看是否有环
				return false;
		}
		else if (visit[node->neighbors[i]->val] == 0)
			return false;
	}
	visit[node->val] = 1;
	return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<GraphNode*> vec_node(numCourses);
	for (int i = 0; i < numCourses; ++i)
		vec_node[i] = new GraphNode(i);
	for (int i = 0; i < prerequisites.size(); ++i)
	{
		vec_node[prerequisites[i].back()]->neighbors.push_back(vec_node[prerequisites[i].front()]);
	}

	//-1 没有访问,0 正在访问, 1 已经访问完毕了
	vector<int> visit(numCourses, -1); //节点的访问状态,初始都是-1

	bool retflag = true;
	for (int i = 0; i < numCourses; i++)
	{
		//进行深度 优先搜索, 还未退出顶点的递归深度优先搜索,结果又遇到这个顶点,说明有环
		if (visit[i] == -1)
		{
			if (!dfs_graph(vec_node[i], visit)) {
				retflag = false;
				break;
			}
		}
	}
	for (int i = 0; i < numCourses; ++i)
		delete vec_node[i];

	return retflag;

}



/// <summary>
/// 深度搜索代码 这个是刷题班的代码,讲的不是太清楚
/// </summary>
/// <param name="node"></param>
/// <param name="visit"></param>
/// <returns>有环 false,无环 true</returns>
bool DFS_Graph(GraphNode* node, vector<int>& visit)
{
	visit[node->val] = 0;//代表正在访问
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->val] == -1) {
			if (DFS_Graph(node->neighbors[i], visit) == 0) {
				return false;
			}
		}
		else if (visit[node->neighbors[i]->val] == 0) {
			return false;
		}
	}
	visit[node->val] = 1;//已经完成访问
	return true;

}
/// <summary>
/// 方法1：深度优先搜索
/// </summary>
/// <param name="numCourses">课程数，课程编号0-numCourses-1</param>
/// <param name="prerequisites">课程的先修关系，第一门课依赖第二门客</param>
/// <returns></returns>
bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
	//第一步，先构造图的临接表
	vector<GraphNode*> graph;//邻接表
	vector<int> visit;//结点访问状态

	//创建图的结点，并初始化访问状态
	for (int i = 0; i < numCourses; i++) {
		graph[i] = new GraphNode(i);
		visit[i] = -1;
	}

	//创建图
	for (int i = 0; i < prerequisites.size(); i++) {
		GraphNode* begin = graph[prerequisites[i].back()];
		GraphNode* end = graph[prerequisites[i].front()];

		begin->neighbors.push_back(end);//课程2指向课程1
		//课程end 依赖课程 begin
	}
	bool retflag = true;
	for (int i = 0; i < graph.size(); i++) {
		if (visit[i] == -1 && DFS_Graph(graph[i], visit)) {
			retflag = false;
			break;
		}
	}
	for (int i = 0; i < numCourses; i++)
		delete graph[i];
	return retflag;
}
/// <summary>
/// 方法2：广度优先搜索
/// </summary>
/// <param name="numCourses">课程数，课程编号0-numCourses-1</param>
/// <param name="prerequisites">课程的先修关系，第一门课依赖第二门客</param>
/// <returns></returns>
bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
	//第一步，先构造图的临接表
	vector<GraphNode*> graph;//邻接表
	vector<int> visit;//结点访问状态
	vector<int> degree;//入度数组 

	//创建图的结点，并初始化访问状态
	for (int i = 0; i < numCourses; i++) {
		graph.push_back(new GraphNode(i));
		degree.push_back(0);
	}

	//创建图
	/*
	[0,1]想要学习课程0，必须学习课程1
	也就是1-》0 在有1的基础才能学习0
	*/
	for (int i = 0; i < prerequisites.size(); i++) {
		GraphNode* begin = graph[prerequisites[i].back()];
		GraphNode* end = graph[prerequisites[i].front()];

		begin->neighbors.push_back(end);
		degree[prerequisites[i].front()]++;//课程1的入度++
	}
	queue<GraphNode*> que;
	//把初始的时候 入度为0的节点放到队列里面
	for (int i = 0; i < numCourses; i++) {
		if (degree[i] == 0)
			que.push(graph[i]);
	}
	while (!que.empty()) {
		GraphNode* node = que.front();
		que.pop();
		for (int i = 0; i < node->neighbors.size(); i++) {
			degree[node->neighbors[i]->val]--;
			if (degree[node->neighbors[i]->val] == 0)
				que.push(node->neighbors[i]);
		}
	}
	for (int i = 0; i < numCourses; i++)
		delete graph[i];
	for (int i = 0; i < degree.size(); i++) {
		if (degree[i] != 0)
			return false;
	}
	return true;
	
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