#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

ǰ׺��
*/

bool checkSubarraySum(vector<int>& nums, int k) {
    long long sum = 0;
    int n = nums.size();
    unordered_map<int, int> hashmap;
    /*
    �����������,���ǳ��ֵĴ�����,����Ϊ0���ֵĴ�����ʼ��Ϊ-1
    [2,3,4],k=1
     ��ʼ��   2              3
    [(0,-1),(0,0)(����ʧ��),(0,1)
    1-(-1) =2>1 ,����[2,3]����һ������Ҫ�������
    */
    hashmap[0] = -1;

    int pre = 0, remain = 0;
    for (int i = 0; i < n; ++i) {
        pre += nums[i];
        if (k != 0)//����Ҫ�ж��Ǹ��������,��Ŀ�Ѿ�˵�ǷǸ�����
            remain = remain % k;
        if (hashmap.count(remain) > 0) {
            if (i - hashmap[remain] > 1)
                return true;
        }
        //�洢��������-�±�
        //[7,3,6],k=6
       //7(7)  3(10) (16)6
      //[(1,0),(4,1),(4,2)(����ʧ��)
    /*
    Ϊʲô[0,1]��[1,2]����������6,�����±��������±�1�������±�2
    ������һ����22
    [7,3,6,22]
    ��Ȼ22-6=18 ��6�ı���,����
    3-2=1������Ҫ��,ʵ�����Ƿ���Ҫ���,Ӧ�ô洢�±�Ϊ1
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
    cout << mymap.at(1) << endl;//��Ȼ��1
    cout << mymap[1]<< endl;//��Ȼ��1

    mymap[1] = 3;//���Բ����ʱ��,Ҫ��insert��ֹ�ı��˽��
    cout << mymap.at(1) << endl;//���Ϊ3

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif