#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

Ҫ���� ����һ��·��
	��������� vector �滻����
ҲҪ������α�������·��
	���������map����ÿ������ķ����±�
*/
struct Qitem
{
	string node;//�����Ķ���
	int pre_pos;//ǰ��������ڶ��е�λ��
	int step;//���ﵱǰ���Ĳ���
	Qitem(string _node, int _pre_pos, int _pos) :node(_node), pre_pos(_pre_pos), step(_pos) {}
};

/// <summary>
/// ������ȱ��� ͼ
/// </summary>
/// <param name="beginWord"></param>
/// <param name="endWord"></param>
/// <param name="graph"></param>
/// <param name="que">��vectorʵ�ֵĶ���,���Ա���������Ϣ</param>
/// <param name="end_word_pos">�յ�endWord���ڶ��е�λ���±�</param>
void bfs_graph(string& beginWord, string& endWord, map<string, vector<string>>& graph, vector<Qitem>& que, vector<int>& endWord_pos)
{
	map<string, int> visit;//<����,����>,֮ǰ��set ��¼�Ƿ��ڶ�����,������Ҫ��mapͬʱ��¼����
	int min_step = 0;//����endWord ����С����

	que.push_back(Qitem(beginWord, -1, 1));//��ʼ���ʵ�ǰ�������±���-1
	
	visit.insert({ beginWord,1 });//��� ��ʼ���ʵĲ���Ϊ1
	int front = 0;//���е�ͷָ��,ָ��vector�ı�ʾ�Ķ���ͷ

	while (front != que.size()) {//frontָ��que��β��,֮ǰ��!que.empty()һ����
		string const& node = que[front].node;
		int step = que[front].step;
		
		//step>min_step,�������е��յ��·�������������
		//��Ϊ�ǹ����������,��������ʱ���ƽ�,step��Խ��Խ���
		if (min_step != 0 && step>min_step) 
			break;
		if (node == endWord) {
			min_step = step;//��¼�����յ����С����
			endWord_pos.push_back(front);//��¼��������������������±�
		}

		const vector<string>& neighbour = graph[node];
		for (int i = 0; i < neighbour.size(); ++i) {
			//���û�б�����, ���ߵ���ö��� �Ĳ��� ����̲�������ͬ��,�Ͱ����λ����ӵ�������
			//�����洢�� �Ӳ�ͬǰ�� �����λ�õ����
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
/// wordList������beginWord,ֱ�ӽ�beginWord push_back wordList
/// ���ܻ�����ظ��Ľ��
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
		//����û��begin_word
		if (!has_begin_word && connect(beginword, wordList[i]))
			graph[beginword].push_back(wordList[i]);
 	}

}

/// <summary>
/// ��ʽ����Ŀ
/// </summary>
/// <param name="beginWord"></param>
/// <param name="endWord"></param>
/// <param name="wordList"></param>
/// <returns>����  ���ת������ </returns>
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	map<string, vector<string> > graph;
	make_graph(beginWord, wordList, graph);//����ͼ
	/*
	����vector ʵ�ֶ���  ֮ǰ�Ķ�����string-int,�����ǵ��ʺͲ�����Ϣ
	���������ǰ������Ϣ
	*/
	vector<Qitem> que;
	vector<int> endWord_pos;//end_word�����������е�λ��

	bfs_graph(beginWord, endWord, graph, que, endWord_pos);

	vector<vector<string> > res;//���ս��
	for (int i = 0; i < endWord_pos.size(); ++i) {
		int pos = endWord_pos[i];//ȡ��endWord�����������е��±�
		vector<string> path;
		while (pos!=-1) {//��endWord��beginWord��·���ϵĽڵ�ֵ���뵽path��
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