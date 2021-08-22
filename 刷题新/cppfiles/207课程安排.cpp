#if 0
#include "../headers/wjxHeaders.h"
/*

�ڵ����״̬������״̬
-1 û�з��ʹ���0�������ڷ��ʣ�1�����Ѿ���ɷ���

��������ж�ͼ�Ƿ��л���
*/


//leetcode �ٷ����
vector<vector<int>> edges;
vector<int> visited;
bool valid = true;

//false �л�  true �޻�
bool dfs_graph(GraphNode* node, vector<int>& visit)
{
	visit[node->val] = 0;//�������ڷ���
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->val] == -1) {//��δ����
			if (!dfs_graph(node->neighbors[i], visit))//�Ե�ǰ���� �ٽӽ��Ҳ�����������,�����Ƿ��л�
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

	//-1 û�з���,0 ���ڷ���, 1 �Ѿ����������
	vector<int> visit(numCourses, -1); //�ڵ�ķ���״̬,��ʼ����-1

	bool retflag = true;
	for (int i = 0; i < numCourses; i++)
	{
		//������� ��������, ��δ�˳�����ĵݹ������������,����������������,˵���л�
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
/// ����������� �����ˢ���Ĵ���,���Ĳ���̫���
/// </summary>
/// <param name="node"></param>
/// <param name="visit"></param>
/// <returns>�л� false,�޻� true</returns>
bool DFS_Graph(GraphNode* node, vector<int>& visit)
{
	visit[node->val] = 0;//�������ڷ���
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
	visit[node->val] = 1;//�Ѿ���ɷ���
	return true;

}
/// <summary>
/// ����1�������������
/// </summary>
/// <param name="numCourses">�γ������γ̱��0-numCourses-1</param>
/// <param name="prerequisites">�γ̵����޹�ϵ����һ�ſ������ڶ��ſ�</param>
/// <returns></returns>
bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
	//��һ�����ȹ���ͼ���ٽӱ�
	vector<GraphNode*> graph;//�ڽӱ�
	vector<int> visit;//������״̬

	//����ͼ�Ľ�㣬����ʼ������״̬
	for (int i = 0; i < numCourses; i++) {
		graph[i] = new GraphNode(i);
		visit[i] = -1;
	}

	//����ͼ
	for (int i = 0; i < prerequisites.size(); i++) {
		GraphNode* begin = graph[prerequisites[i].back()];
		GraphNode* end = graph[prerequisites[i].front()];

		begin->neighbors.push_back(end);//�γ�2ָ��γ�1
		//�γ�end �����γ� begin
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
/// ����2�������������
/// </summary>
/// <param name="numCourses">�γ������γ̱��0-numCourses-1</param>
/// <param name="prerequisites">�γ̵����޹�ϵ����һ�ſ������ڶ��ſ�</param>
/// <returns></returns>
bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
	//��һ�����ȹ���ͼ���ٽӱ�
	vector<GraphNode*> graph;//�ڽӱ�
	vector<int> visit;//������״̬
	vector<int> degree;//������� 

	//����ͼ�Ľ�㣬����ʼ������״̬
	for (int i = 0; i < numCourses; i++) {
		graph.push_back(new GraphNode(i));
		degree.push_back(0);
	}

	//����ͼ
	/*
	[0,1]��Ҫѧϰ�γ�0������ѧϰ�γ�1
	Ҳ����1-��0 ����1�Ļ�������ѧϰ0
	*/
	for (int i = 0; i < prerequisites.size(); i++) {
		GraphNode* begin = graph[prerequisites[i].back()];
		GraphNode* end = graph[prerequisites[i].front()];

		begin->neighbors.push_back(end);
		degree[prerequisites[i].front()]++;//�γ�1�����++
	}
	queue<GraphNode*> que;
	//�ѳ�ʼ��ʱ�� ���Ϊ0�Ľڵ�ŵ���������
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