#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

要考虑 保存一条路径
	解决方法用 vector 替换队列
也要考虑如何保存所有路径
	解决方法用map保存每个顶点的访问下标
*/
struct Qitem
{
	string node;//搜索的顶点
	int pre_pos;//前驱顶点的在队列的位置
	int step;//到达当前结点的步数
	Qitem(string _node, int _pre_pos, int _pos) :node(_node), pre_pos(_pre_pos), step(_pos) {}
};

/// <summary>
/// 宽度优先遍历 图
/// </summary>
/// <param name="beginWord"></param>
/// <param name="endWord"></param>
/// <param name="graph"></param>
/// <param name="que">用vector实现的队列,可以保存所有信息</param>
/// <param name="end_word_pos">终点endWord所在队列的位置下标</param>
void bfs_graph(string& beginWord, string& endWord, map<string, vector<string>>& graph, vector<Qitem>& que, vector<int>& endWord_pos)
{
	map<string, int> visit;//<单词,步数>,之前用set 记录是否在队列里,现在需要用map同时记录步数
	int min_step = 0;//到达endWord 的最小步数

	que.push_back(Qitem(beginWord, -1, 1));//起始单词的前驱顶点下标是-1
	
	visit.insert({ beginWord,1 });//标记 起始单词的步数为1
	int front = 0;//队列的头指针,指向vector的表示的队列头

	while (front != que.size()) {//front指向que的尾部,之前是!que.empty()一样的
		string const& node = que[front].node;
		int step = que[front].step;
		
		//step>min_step,代表所有到终点的路径都搜索完成了
		//因为是广度优先搜索,所以随着时间推进,step会越来越大的
		if (min_step != 0 && step>min_step) 
			break;
		if (node == endWord) {
			min_step = step;//记录到达终点的最小步数
			endWord_pos.push_back(front);//记录的是在搜索队列里面的下标
		}

		const vector<string>& neighbour = graph[node];
		for (int i = 0; i < neighbour.size(); ++i) {
			//结点没有被访问, 或者到达该顶点 的步数 和最短步数是相同的,就把这个位置添加到队列里
			//这样存储了 从不同前驱 到达该位置的情况
			if (visit.find(neighbour[i]) == visit.end() || visit[neighbour[i]] == step + 1)
			{
				que.push_back(Qitem(neighbour[i], front, step + 1));
				visit[neighbour[i]] = step + 1;
			}
		}//for
		++front;
	}//while 
}

bool connect(string const& word1, string const& word2)
{
	int cnt = 0;
	for (int i = 0; i < word1.size(); i++) {
		if (word1[i] != word2[i])
			++cnt;
	}
	return cnt == 1;
	
}
/// <summary>
/// wordList可能有beginWord,直接将beginWord push_back wordList
/// 可能会出现重复的结果
/// </summary>
/// <param name="beginword"></param>
/// <param name="wordList"></param>
/// <param name="graph"></param>
void make_graph(string & beginword,vector<string> &wordList,map<string,vector<string>>&graph)
{
	bool has_begin_word = false;
	for (int i = 0; i < wordList.size(); ++i) {
		if (wordList[i] == beginword) {
			has_begin_word = true;
			break;
		}
			
	}
	for (int i = 0; i < wordList.size(); ++i) {
		for (int j = i + 1; j < wordList.size(); ++j) {
			if (connect(wordList[i], wordList[j])) {
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		}
		//里面没有begin_word
		if (!has_begin_word && connect(beginword, wordList[i]))
			graph[beginword].push_back(wordList[i]);
 	}

}

/// <summary>
/// 正式做题目
/// </summary>
/// <param name="beginWord"></param>
/// <param name="endWord"></param>
/// <param name="wordList"></param>
/// <returns>所有  最短转换序列 </returns>
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	map<string, vector<string> > graph;
	make_graph(beginWord, wordList, graph);//建立图
	/*
	利用vector 实现队列  之前的队列是string-int,保存是单词和步数信息
	现在添加了前序结点信息
	*/
	vector<Qitem> que;
	vector<int> endWord_pos;//end_word在搜索队列中的位置

	bfs_graph(beginWord, endWord, graph, que, endWord_pos);

	vector<vector<string> > res;//最终结果
	for (int i = 0; i < endWord_pos.size(); ++i) {
		int pos = endWord_pos[i];//取出endWord在搜索队列中的下标
		vector<string> path;
		while (pos!=-1) {//从endWord到beginWord将路径上的节点值加入到path中
			path.push_back(que[pos].node);
			pos = que[pos].pre_pos;
		}
		res.push_back(vector<string>());
		for (int j = path.size() - 1; j >= 0; --j) {
			res[i].push_back(path[j]);
		}
	}
	return res;
}
void test01()
{
	map<string, vector<string>> graph;
	vector<string> a{ "111","222","333" };
	vector<string> b{ "444","555","666" };

	graph["a"] = a;
	graph["b"] = b;

	vector<string> &c = graph["a"];
	for (auto iter : c)
		cout << iter << " ";
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif