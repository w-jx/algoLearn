#if 0
#include "../headers/wjxHeaders.h"
/*

�����ǩ:�����������
*/

//1.��һ��,���ȼ����з����Զ������ݽṹ,���Զ���ȽϺ���
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

//�ڶ���:ʵ�ֽ��������ܵĵ���ӵ����ȼ����еĴ���

int trapRainWater(vector<vector<int>>& heightMap) {
	if (heightMap.size() < 3 || heightMap[0].size() < 3)
		return 0;
	priority_queue<Qitem, vector<Qitem>, Cmp> que;//��С��

	int row = heightMap.size();//��
	int col = heightMap[0].size();//��
	vector<vector<int>> mark(row, vector<int>(col, 0));//�������
	//�ȱ�ǵ�һ�к����һ�е�
	for (int i = 0; i < row; ++i) {
		que.push(Qitem(i, 0, heightMap[i][0]));
		mark[i][0] = 1;
		que.push(Qitem(i, col - 1, heightMap[i][col - 1]));
		mark[i][col - 1] = 1;
	}
	//Ȼ���� ��һ�� �����һ��   ���˵�һ�к����һ�е�
	for (int i = 1; i < col - 1; i++) {
		que.push(Qitem(0, i, heightMap[0][i]));
		mark[0][i] = 1;
		que.push(Qitem(row - 1, i, heightMap[row - 1][i]));
		mark[row - 1][i] = 1;
	}


	//�����������
	static const int dx[] = { -1,1,0,0 };//��������
	static const int dy[] = { 0,0,-1,1 };

	int res = 0;//���ս�� ��ˮ��

	while (!que.empty()) {
		int x = que.top().x;
		int y = que.top().y;
		int h = que.top().h;
		que.pop();
		//��������4������  ��չ
		for (int i = 0; i < 4; ++i) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			//��չ��Խ���˻����Ѿ���������
			if (newx < 0 || newx >= row || newy < 0 || newy >= col || mark[newx][newy]==1)
				continue;

			if (h > heightMap[newx][newy]) {//��ǰ��߶ȸ�����չ��
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