#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

//�������ת����ͼ�Ŀ����������,�ڽ������֮ǰ,�Ƚ����ι���ͼ
//��map(string,vector<string>> ����

bool connect(const string& word1, const string& word2) {
	int cnt = 0;//��¼���������в�����ַ��ĸ���
	//��Ŀ������е�����һ�����ȵ�
	for (int i = 0; i < word1.size(); ++i) {
		if (word1[i] != word2[i])
			++cnt;
	}
	return cnt == 1;
}
void make_graph(string beginWord, string endWord, vector<string>& wordList,map<string,vector<string>> &graph) {
	wordList.push_back(beginWord);//��beginWord�Ž�ȥ

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

//��ʽ�������
int bfs_graph(string& beginword, string& endword, map < string, vector<string>>& graph)
{
	queue<std::pair<string, int> > word_que;//����-����  ��������
	set<string> visit;//��¼�Ѿ���ӵ� �������еĽ��

	word_que.push({ beginword,1 });//����ʼ����ӵ�����,��ʼ������1;
	visit.insert(beginword);//�����������Ѿ���ӵ�����
	while (!word_que.empty()) {
		string cur_word = word_que.front().first;//ȡ������ͷ�����Ͳ���
		int step = word_que.front().second;
		word_que.pop();

		if (cur_word == endword)
			return step;
		vector<string> neighbours = graph[cur_word];
		//ȡ cur_word ���ڽӵ�
		for (int i = 0; i < neighbours.size(); i++) {
			if (visit.find(neighbours[i]) == visit.end()) {//��û�б���ӵ�������
				//word_que.push({ neighbours[i],++step });++step����Ͳ���
				word_que.push({ neighbours[i],step+1 });//step+1�����ȷ
				visit.insert(neighbours[i]);
			}
		}
	}//while (!word_que.empty())

	return 0;//�޷�ת��

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