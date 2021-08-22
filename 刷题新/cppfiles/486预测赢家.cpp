#if 0
#include "../headers/wjxHeaders.h"

/*
�ҵ��뷨�ܼ�,�������1ѡ����β���������
���2��ѡ��
ֱ��û��ѡ
������������������[1,5,233,7]
���1��ѡ7,���2ѡ233,���1����

ʵ�������1���ѡ��1,���2ѡ��7,���1��ѡ��233����Ӯ��
*/
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<int> used(n);
    int first = 0, last = n - 1;
    int s1 = 0, s2 = 0;
    bool isperson1 = true;
    while (first != last) {
        if (isperson1) {
            if (nums[first] >= nums[last]) {
                s1 += nums[first];
                ++first;
            }
            else {
                s1 += nums[last];
                --last;
            }
        }
        else {
            if (nums[first] >= nums[last]) {
                s2 += nums[first];
                ++first;
            }
            else {
                s2 += nums[last];
                --last;
            }
        }
        isperson1 = !isperson1;

    }//while 
    return s1 >= s2;
}
/*
����ż�������ֵ�����,���1һ����ʤ��
��Ϊ���1ʹ���÷� A,���2ʹ���÷�B,�����ʱ���1����
��Ϊ���1������,������ʹ���÷�B���ʤ��,�������1һ����ʤ��

�������������,��̬�滮
�����ӽṹ����:
[1,..n]��������[i,..j]���������ŵ�,���õķ��������2������


*/
//Ӣ�İ������(���ĵ�̫�������
bool PredictTheWinner2(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 0)
        return true;
    //dp[i][j]��ʾ������ʣ�µĲ���Ϊ�±�i��j
    //���ֵ��˱Ⱥ��ֵ��˶�ķ���,����ж�dp[0][n-1]>=0����
    vector<vector<int> > dp(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i)
        dp[i][i] = nums[i]; 
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            /*��ǰ��λ��i,jѡȡ����
            ������Aѡ��λ��i,���A���nums[i]����
            ���B����i+1,j��ѡ��,��ʱ���B��Ϊ"����"
            dp[i+1][j]��ʾ��i+1,j,���B�����A��ķ���
            ����Ҫ�����A�����B���,����nums[i] - dp[i + 1][j]

            ������Bѡ��λ��j,���̻��nums[j]����
            ���Bֻ�ܴ�i��j-1ѡ��,���B��õı����A��ķ���Ϊ
            dp[i][j-1],���Ҫ�����A�����B���,����nums[j]-dp[i][j-1]

            ���ֺܴ���,ѡ���������е����ֵ
             dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]); 

             dp[i][i]�����i��i���ֱȺ��ֶ��,��Ȼ��nums[i]
             �����ʱ��dp[i][j]����ȡ����dp[i+1][j]��dp[i][j-1]
             (i,j) �������(i,j-1)���²�(i+1,j)�Ŀ�,����5*5�ľ���
             �����len = 1�Ĺ���,�����len=2�Ĺ���,��������
             1 2 3 4 5
             # 1 2 3 4
             # # 1 2 3
             # # # 1 2
             # # # # 1
             �൱�ڴ����Խ��������Ͻǽ��б������
             len�ĺ����ʾ�����Խ��߶�Զ,��1-(n-1)
             ��ѭ����������Ч��iλ��
             
             dp[0][1]ȡ����dp[0][0]��dp[1][1],ǡ�ö��ڶԽ�����,�����Ѿ��õ��Ľ��
             ���:len=1
             �ڲ�:i=0;i<n-len  ,Ҳ����i<4,i=0,1,2,3
             j = i+len,j=1,2,3,4
             dp[0][1]->(dp[0][0],dp[1][1])
             dp[1][2]->(dp[1][1],dp[2][2])
             dp[2][3]->(dp[2][2],dp[3][3])
             dp[3][4]->(dp[3][3],dp[4][4])

             ���:len=2
             �ڲ�:i=0;i<n-len  ,Ҳ����i<3,i=0,1,2
             j = i+len,j=2,3,4
             dp[0][2]->(dp[0][1],dp[1][2])
             dp[1][3]->(dp[1][2],dp[2][3])
             dp[2][4]->(dp[2][3],dp[3][4])

             ���:len=3
             �ڲ�:i=0;i<n-len  ,Ҳ����i<2,i=0,1
             j = i+len,j=3,4
             dp[0][3]->(dp[0][2],dp[1][3])
             dp[1][4]->(dp[1][3],dp[2][4])
             
             ���:len=4
             �ڲ�:i=0;i<n-len  ,Ҳ����i<1,i=0
             j = i+len,j=4
             dp[0][4]->(dp[0][3],dp[1][4])
       
            */
            dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
    /*
        for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            ..
            dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        ���Լ������,����ͨ��������ǿ��Է������˳����
        �����Խ���->���������ϽǱƽ��ĶԽ���
        ��һ������Ǿ������Խ���Ϊ1,���ε�������ϽǾ���Ϊ4
        i��0��ʼ,��Ϊ�����Ͻ�,�Խ��߳���Խ��Խ��,ֱ��Ϊ1
        ���Խ������Ȼ��5,�ζԽ��ߴ�4-1,������n-len�õ�

        Ҳ����len=1��ʱ��,�������Խ���Ϊ1��ʱ��,��ĴζԽ��߳���Ϊ4
        �ֱ������(0,1),(1,2),(2,3),j=i+len

        ��len=2��ʱ��,�������Խ���Ϊ2��ʱ��,��ĴζԽ��߳���Ϊ3,
        �ֱ������(0,2),(1,3),(2,4),j=i+len
    */

}
//Ӣ�İ������,�Ż��ռ临�Ӷ�ΪO(n)
bool PredictTheWinner2(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 0)
        return true;
    //dp[i]����[i]���ֱȺ��ֶ��,����ж�dp[n-1]>=0����
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            /*dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
             1 2 3 4 5
             # 1 2 3 4
             # # 1 2 3
             # # # 1 2
             # # # # 1
             �Ӹ������ж�
            ��i��j
            i=4,j=4->dp[4]=nums[4],���ֶ���
            Ȼ��i=3,
            j=3,dp[3]=nums[3],���ֶ���num[3]
            j=4,��ʱ����Ҫ�����ж���
            �����������nums[3],��ô���̻��nums[3],��ô�Ⱥ��ֶ����
            num[i]-dp[j],(dp[j],dp[4]����һ����Ҵ���nums[4],���ֶ��õ�)
            �����������nums[4],��ô���̻��nums[4],��ô�Ⱥ��ֶ����
            nums[j]-dp[j-1](dp[j-1],��һ��������ֵ�ʱ����õ�)

            */
            if (i == j)
                dp[i] = nums[i];
            else
                dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }

    return dp[n - 1] >= 0;


  

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