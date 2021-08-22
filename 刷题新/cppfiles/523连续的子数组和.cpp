#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

前缀和
*/

bool checkSubarraySum(vector<int>& nums, int k) {
    long long sum = 0;
    int n = nums.size();
    unordered_map<int, int> hashmap;
    /*
    保存的是索引,不是出现的次数了,余数为0出现的次数初始化为-1
    [2,3,4],k=1
     初始化   2              3
    [(0,-1),(0,0)(插入失败),(0,1)
    1-(-1) =2>1 ,所以[2,3]就是一个符合要求的区间
    */
    hashmap[0] = -1;

    int pre = 0, remain = 0;
    for (int i = 0; i < n; ++i) {
        pre += nums[i];
        if (k != 0)//不需要判断是负数的情况,题目已经说是非负数了
            remain = remain % k;
        if (hashmap.count(remain) > 0) {
            if (i - hashmap[remain] > 1)
                return true;
        }
        //存储的是余数-下标
        //[7,3,6],k=6
       //7(7)  3(10) (16)6
      //[(1,0),(4,1),(4,2)(插入失败)
    /*
    为什么[0,1]和[1,2]的余数都是6,但是下标插入的是下标1而不是下标2
    例如下一个是22
    [7,3,6,22]
    显然22-6=18 是6的倍数,但是
    3-2=1不符合要求,实际上是符合要求的,应该存储下标为1
    */
        hashmap.insert({ remain,i });

    }
    return false;
}
void test01()
{
 
    map<int, int> mymap;
    mymap.insert(make_pair(1, 1));
    mymap.insert({ 1,2 });
    cout << mymap.at(1) << endl;//仍然是1
    cout << mymap[1]<< endl;//仍然是1

    mymap[1] = 3;//所以插入的时候,要用insert防止改变了结果
    cout << mymap.at(1) << endl;//结果为3

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif