#if 0
#include "../headers/wjxHeaders.h"

/*
��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�

����һ����������?nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£����� �κ�һ����ֵ ����λ�ü��ɡ�

����Լ���?nums[-1] = nums[n] = -�� ��

�����ñ����ķ��������������Ҫ�ö��ֲ��ҵķ���



****lambda���治Ҫ�׵ݹ飬

*/
//std::function<int(vector<int>&, int, int)> search;
int search(vector<int>& num, int left, int right) {
    if (left == right)
        return left;
    int mid = (left + right) / 2;
    if (num[mid] > num[mid + 1])
        return search(num, left, mid); //C++ ʹ�� auto ����˵���������ı������ܳ�����������ĳ�ʼֵ�趨����
    else
        return search(num, mid + 1, right);
}

int findPeakElement(vector<int>& nums) {

    return search(nums, 0,nums.size() - 1);
}
void test01()
{
    vector<int> v{ 1,3,5,2,7,9,11,6,8 };
    cout << findPeakElement(v);
}
//void test02()
//{
//    std::function<void(int, int)> myfunction;
//    myfunction = [=](int a, int b) {
//        cout << "a=" << a << ",b=" << b << endl;
//        return;
//    };
//    myfunction(3,5);
//}
int main()
{
    test01();
    //test02();
	system("pause");
	return 0;
}


#endif