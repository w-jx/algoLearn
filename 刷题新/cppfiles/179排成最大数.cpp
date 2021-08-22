#if 0
#include "../headers/wjxHeaders.h"
#include <string> //Ϊ��ʹ��c++11 �ṩ��to_string

//30 3 ���303����330 Ӧ����3����30ǰ��
bool comp(int const& num1, int const& num2) //�ڶ��ֺ�����ȫ�ֺ���
{
	string str1 = to_string(num1) + to_string(num2);
	string str2 = to_string(num2) + to_string(num1);
	return str1 > str2;
}
class Solution {
   
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string res = "";
        if (!nums.empty() && nums[0] == 0) return "0";
        for (int const& iter : nums) {
            res += to_string(iter);
        }
        return res;
    }

private:
    //static bool comp(int num1, int num2) { //��һ�ַ����þ�̬��Ա����
    //    string str1 = to_string(num1) + to_string(num2);
    //    string str2 = to_string(num2) + to_string(num1);
    //    return str1 > str2;
    //}

};
void test01()
{
    vector<int> v{ 1,6,2,5,7,10 };
    sort(v.begin(), v.end());//Ĭ����less<int>()   [](int left,int right){return left<right};
    printVector(v);

    vector<int > v2{ 1,9,2,7,20,17 };
    sort(v2.begin(), v2.end(), [](int const& v1, int const& v2)->bool {return v1 < v2; });
    printVector(v2);
}
void test02()
{
    vector<int> v{ 3,30,34,5,9 };
    Solution s;
    cout << s.largestNumber(v) << endl;;
   
}
//�ֵ���ıȽ�
void test03()
{
    string a = "98";
    string b = "89";
    cout << (a > b) << endl;

    string c = "98";
    string d = "100";
    cout << (c >d) << endl;//9>1���궿����


    string e = "30";
    string f = "3";
    cout << (e > f) << endl;//1
}
int main()
{
    //test01();
    //test02();
    test03();
	system("pause");
	return 0;
}


#endif