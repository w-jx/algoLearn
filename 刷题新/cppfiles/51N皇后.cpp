#if 0
#include "../headers/wjxHeaders.h"
//dfs
//��ָoffer 38 �ַ���������

// �ʺ�˴˲����໥������Ҳ����˵���κ������ʺ󶼲��ܴ���ͬһ�����С����л�б���ϡ�

/* �Ƿ������ board[row][col] ���ûʺ� */
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // ������Ƿ��лʺ����ͻ
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // ������Ϸ��Ƿ��лʺ����ͻ
    for (int i = row - 1, j = col + 1;
        i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // ������Ϸ��Ƿ��лʺ����ͻ
    for (int i = row - 1, j = col - 1;
        i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void dfs(vector<string>& board, int row);
vector<vector<string> > res;//��Ϊ����ֵ
/// <summary>
/// �������̱߳������غϷ��ķ���
/// </summary>
/// <param name="n">���̱߳�</param>
/// <returns>�Ϸ��ķ�������</returns>
vector<vector<string>> solveNQueens(int n) {

    vector<string> board(n, string(n, '.'));
	dfs(board, 0);
	return res;
}
/// <summary>
/// ·����board��С��row����Щ�ж��ɹ������˻ʺ�
/// ѡ���б���row�е������ж��Ƿ��ûʺ��ѡ��
/// ����������row����board���һ��
/// </summary>
/// <param name="board"></param>
/// <param name="row"></param>
void dfs(vector<string> & board, int row) {

	if (row == board.size()) {//������������
		res.push_back(board);
		return;
	}
	int n = board[row].size();
	for (int col = 0; col < n; col++) {
        //�ų����Ϸ�ѡ��
        if (!isValid(board, row, col))
            continue;
        //��ѡ��
        board[row][col] = 'Q';
        //������һ�о���
        dfs(board, row + 1);
        //����ѡ��
        board[row][col] = '.';
        
	}

}

//����Ĵ��붼����ǰ���ģ���������ѧϰһ���̳�
//1.Ϊ�˽�����⣬�����Ƚ���������ʺ�ŵ����̵Ĺ���
void put_down_queens(int x,int y,vector<vector<int> >&mark)
{
    static const  int dx[] = { -1,1,0,0,-1,-1,1,1};
    static const  int dy[] = { 0,0,-1,1,-1,1,-1,1 };//��������
    //�� �� �� �� ���� ���� ���� ����
    mark[x][y] = 1;//���˻ʺ󣬿϶���1

    for (int i = 1; i < mark.size(); ++i) {
        for (int j = 0; j < 8; ++j) {
            int nex_x = x+dx[j]*i;//�µ�λ�� ����������
            int new_y =y+dy[j]*i ;//ÿ����������N-1
            if (nex_x>=0 && nex_x<mark.size() && new_y>=0 && new_y<mark.size()) {//�ж��Ƿ���������
                mark[nex_x][new_y] = 1;
            }
        }
    }

}
//���Խ�ĳ���ʺ�ŵ����̺����̲��ֵı仯
void test01()
{
    //vector<vector<int> > mark{
    //    {0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0},
    //      {0,0,0,0,0,0,0,0},
    //       {0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0},
    //         {0,0,0,0,0,0,0,0},
    //          {0,0,0,0,0,0,0,0},
    //           {0,0,0,0,0,0,0,0}
    //};
    //for (int i = 0; i < mark.size(); ++i) {
    //    for (int j = 0; j < mark[i].size(); ++j) {
    //        cout << mark[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "after put queens:\n";
    //put_down_queens(3, 4, mark);//������3��4λ�÷��ûʺ�
    //for (int i = 0; i < mark.size(); ++i) {
    //    for (int j = 0; j < mark[i].size(); ++j) {
    //        cout << mark[i][j] << " ";
    //    }
    //    cout << endl;
    //}


}
/// <summary>
/// 
/// </summary>
/// <param name="k">k��������˼����ʺ����ڷ��õ�K�еĻʺ�</param>
/// <param name="n">N�ʺ�</param>
/// <param name="location">ĳһ�εİڷŽ��</param>
/// <param name="mark">���̵ı������</param>
void dfs2(int k,int n, vector<string>&location,vector<vector<int>> mark)
{
    if (k == n) {
        res.push_back(location);
        return;
    }
    for (int i = 0; i < n; i++) {//���Ե�0-n-1��
        if (mark[k][i]==0) {//����  �ʺ������
            auto temp_mark = mark;//��¼����ǰ��mark����
            
            location[k][i] = 'Q';//��¼��ǰ�ʺ��λ��
            put_down_queens(k, i, mark);//���ûʺ�
            dfs2(k + 1, n, location, mark);//������һ�еĻʺ����
            mark = temp_mark;//�����Ժ� �ָ�mark �� �ڷŽ��location
            location[k][i] = '.';
        }
    }
}
//������ 
vector<vector<string>> solveNQueens2(int n) {
    vector<vector<int>> mark(n, vector<int>(n, 0));
    vector<string>location (n, string(n, '.'));//�洢ĳ���ڷŵĽ��
    dfs2(0, n, location, mark);
    
    return res;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif