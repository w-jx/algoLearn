#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

//问题可以转化成图的宽度优先搜索,在解决问题之前,先解决如何构造图
//用map(string,vector<string>> 构造

bool connect(const string& word1, const string& word2) {
	int cnt = 0;//记录两个单词中不相等字符的个数
	//题目里的所有单词是一样长度的
	for (int i = 0; i < word1.size(); ++i) {
		if (word1[i] != word2[i])
			++cnt;
	}
	return cnt == 1;
}
void make_graph(string beginWord, string endWord, vector<string>& wordList,map<string,vector<string>> &graph) {
	wordList.push_back(beginWord);//把beginWord放进去

	for (int i = 0; i < wordList.size(); ++i) {
		graph[wordList[i]] = vector<string>();
	}

	for (int i = 0; i < wordList.size(); i++) {
		for (int j = i+1; j < wordList.size(); j++) {
			if (connect(wordList[i], wordList[j])) {
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		}
	}
}

//正式解决问题
int bfs_graph(string& beginword, string& endword, map < string, vector<string>>& graph)
{
	queue<std::pair<string, int> > word_que;//顶点-步数  搜索队列
	set<string> visit;//记录已经添加到 搜索队列的结点

	word_que.push({ beginword,1 });//把起始点添加到队列,起始步数是1;
	visit.insert(beginword);//标记这个单词已经添加到队列
	while (!word_que.empty()) {
		string cur_word = word_que.front().first;//取出队列头部结点和步数
		int step = word_que.front().second;
		word_que.pop();

		if (cur_word == endword)
			return step;
		vector<string> neighbours = graph[cur_word];
		//取 cur_word 的邻接点
		for (int i = 0; i < neighbours.size(); i++) {
			if (visit.find(neighbours[i]) == visit.end()) {//还没有被添加到队列中
				//word_que.push({ neighbours[i],++step });++step结果就不对
				word_que.push({ neighbours[i],step+1 });//step+1结果正确
				visit.insert(neighbours[i]);
			}
		}
	}//while (!word_que.empty())

	return 0;//无法转换

}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	map<string, vector<string>> graph;
	make_graph(beginWord, endWord, wordList, graph);
	return bfs_graph(beginWord, endWord, graph);
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