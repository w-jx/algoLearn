#if 0
#include "../headers/wjxHeaders.h"

/*
我的想法很简单,首先玩家1选择首尾两个更大的
玩家2再选择
直到没得选
但是针对这个测试用例[1,5,233,7]
玩家1先选7,玩家2选233,玩家1必输

实际上玩家1如果选择1,玩家2选择7,玩家1再选择233就能赢了
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
对于偶数个数字的数组,玩家1一定能胜利
因为玩家1使用拿法 A,玩家2使用拿法B,假如此时玩家1输了
因为玩家1是先手,他可以使用拿法B获得胜利,所以玩家1一定能胜利

如果奇数个数字,动态规划
最优子结构性质:
[1,..n]的子数组[i,..j]假如是最优的,即拿的分数比玩家2多出最多


*/
//英文版题解解答(中文的太难理解了
bool PredictTheWinner2(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 0)
        return true;
    //dp[i][j]表示当数组剩下的部分为下标i到j
    //先手的人比后手的人多的分数,最后判断dp[0][n-1]>=0即可
    vector<vector<int> > dp(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i)
        dp[i][i] = nums[i]; 
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            /*当前从位置i,j选取数组
            如果玩家A选择位置i,玩家A获得nums[i]分数
            玩家B将从i+1,j中选择,此时玩家B成为"先手"
            dp[i+1][j]表示从i+1,j,玩家B比玩家A多的分数
            所以要求玩家A比玩家B多的,就用nums[i] - dp[i + 1][j]

            如果玩家B选择位置j,立刻获得nums[j]分数
            玩家B只能从i到j-1选择,玩家B获得的比玩家A多的分数为
            dp[i][j-1],因此要求玩家A比玩家B多的,就用nums[j]-dp[i][j-1]

            先手很聪明,选择这两个中的最大值
             dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]); 

             dp[i][i]代表从i到i先手比后手多的,显然是nums[i]
             其余的时候dp[i][j]仅仅取决于dp[i+1][j]和dp[i][j-1]
             (i,j) 依赖左侧(i,j-1)和下侧(i+1,j)的块,例如5*5的矩阵
             先完成len = 1的过程,再完成len=2的过程,依此类推
             1 2 3 4 5
             # 1 2 3 4
             # # 1 2 3
             # # # 1 2
             # # # # 1
             相当于从主对角线往右上角进行遍历检查
             len的含义表示块距离对角线多远,从1-(n-1)
             内循环是所有有效的i位置
             
             dp[0][1]取决于dp[0][0]和dp[1][1],恰好都在对角线上,都是已经得到的结果
             外层:len=1
             内层:i=0;i<n-len  ,也就是i<4,i=0,1,2,3
             j = i+len,j=1,2,3,4
             dp[0][1]->(dp[0][0],dp[1][1])
             dp[1][2]->(dp[1][1],dp[2][2])
             dp[2][3]->(dp[2][2],dp[3][3])
             dp[3][4]->(dp[3][3],dp[4][4])

             外层:len=2
             内层:i=0;i<n-len  ,也就是i<3,i=0,1,2
             j = i+len,j=2,3,4
             dp[0][2]->(dp[0][1],dp[1][2])
             dp[1][3]->(dp[1][2],dp[2][3])
             dp[2][4]->(dp[2][3],dp[3][4])

             外层:len=3
             内层:i=0;i<n-len  ,也就是i<2,i=0,1
             j = i+len,j=3,4
             dp[0][3]->(dp[0][2],dp[1][3])
             dp[1][4]->(dp[1][3],dp[2][4])
             
             外层:len=4
             内层:i=0;i<n-len  ,也就是i<1,i=0
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
        我自己的理解,首先通过结果我们可以发现求的顺序是
        从主对角线->依次往右上角逼近的对角线
        第一次求的是距离主对角线为1,依次到最后右上角距离为4
        i从0开始,因为往右上角,对角线长度越来越短,直到为1
        主对角线最长当然是5,次对角线从4-1,所以用n-len得到

        也就是len=1的时候,距离主对角线为1的时候,求的次对角线长度为4
        分别求的是(0,1),(1,2),(2,3),j=i+len

        在len=2的时候,距离主对角线为2的时候,求的次对角线长度为3,
        分别求的是(0,2),(1,3),(2,4),j=i+len
    */

}
//英文版题解解答,优化空间复杂度为O(n)
bool PredictTheWinner2(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 0)
        return true;
    //dp[i]代表到[i]先手比后手多的,最后判断dp[n-1]>=0即可
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            /*dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
             1 2 3 4 5
             # 1 2 3 4
             # # 1 2 3
             # # # 1 2
             # # # # 1
             从高往低判断
            从i到j
            i=4,j=4->dp[4]=nums[4],先手多拿
            然后i=3,
            j=3,dp[3]=nums[3],先手多拿num[3]
            j=4,这时候需要进行判断了
            如果先手拿了nums[3],那么立刻获得nums[3],那么比后手多的是
            num[i]-dp[j],(dp[j],dp[4]另外一个玩家代表到nums[4],先手多拿的)
            如果先手拿了nums[4],那么立刻获得nums[4],那么比后手多的是
            nums[j]-dp[j-1](dp[j-1],另一个玩家先手的时候多拿的)

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