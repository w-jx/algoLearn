#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
/*
������������������������������
[-2,3,-4]
��������������˻� = (-2)*3*(-4)=24

��ǰλ�õ����Ž�,��һ����ǰһ��λ�õ����Ž�ת�Ƶõ���


�ҵ���ǰλ�õ����˻�fmax
�ҵ���ǰλ�õ���С�ɼ�fmin
��ǰλ�õ����Ž������
����������
����������
��ǰԪ��

֮ǰ�Ľⷨ�����˸��������������

*/
//û���Ż��ռ��
int maxProduct(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int n = nums.size();
    vector<int> dpmax(n);
    vector<int> dpmin(n);
    int maxpro = nums[0];
    dpmax[0] = dpmin[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dpmin[i] = std::min({ dpmax[i - 1] * nums[i], nums[i], dpmin[i - 1] * nums[i] });
        dpmax[i] = std::max({ dpmax[i - 1] * nums[i], nums[i], dpmin[i - 1] * nums[i] });
        

        maxpro = std::max(dpmax[i], maxpro);
    }
    return maxpro;
}
//�Ż��ռ��
int maxProduct2(vector<int>& nums) {

    int n = nums.size();
    int maxpro = nums[0];
    int fmax = nums[0], fmin = nums[0];
    for (int i = 1; i < n; ++i) {
        int premax = fmax;//���һ��Ҫ����premax,�����ظ�����
        fmax = std::max({ premax * nums[i],nums[i],fmin * nums[i] });
        fmin = std::min({ premax * nums[i],nums[i],fmin * nums[i] });
        maxpro = std::max(maxpro, fmax);
    }
    return maxpro;
}
void test01()
{
    vector<int> nums{ -4,-3,-2 };
    cout << maxProduct2(nums) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif