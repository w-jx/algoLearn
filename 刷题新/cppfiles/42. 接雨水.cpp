#if 0
#include "../headers/wjxHeaders.h"

//�Լ���,û������
int trap(vector<int>& height) {
    if (height.empty())
        return 0;
    int n = height.size();
    deque<int> s;
    int cnt = 0;
    s.push_back(height[0]);
    bool last_is_bigger = false;
    for (int i = 1; i < n;++i ) {
        if (height[i] > s.back()) {
            s.push_back(height[i]);
            last_is_bigger = true;
        }
        else if (height[i] <= s.back()) {
            s.push_back(height[i]);
            //��ʼ������ˮ����
            if (last_is_bigger) {
                int base = s[0];
                while (s.size() > 1) {
                }              
            }
            last_is_bigger = false;
        }         
    }

    return cnt;
}
/*
�����1:��̬�滮
�±�i
�������ˮ�ﵽ�����߶ȵ����±�i���ߵ����߶ȵĽ�С���Ǹ�
�ܽӵ���ˮ�� �����±�i����ˮ�ܴﵽ�����߶� ��ȥ height[i]

���ص�����,����ÿ��Ԫ��,�ֱ�����,����ɨ�貢��¼��ߺ��ұߵ����߶�
Ȼ�����ÿ���±�λ���ܽӵ���ˮ��

ͨ��!

*/
//ʱ�临�Ӷ�o(n^2),�ռ临�Ӷ�o(1)
int trap1(vector<int>& height) {
    if (height.empty())
        return 0;

    int cnt = 0;
    int n = height.size();
    int leftMax = INT_MIN, rightMax = INT_MIN;
    for (int i = 1; i < n - 1; ++i) {
        leftMax = INT_MIN, rightMax = INT_MIN;
        for (int j = 0; j < i; ++j) {
            leftMax = std::max(leftMax, height[j]);
        }
        for (int j = i + 1; j < n; ++j)
            rightMax = std::max(rightMax, height[j]);

        cnt += std::max(0, std::min(leftMax, rightMax) - height[i]);
    }
    return cnt;
}
//O(n^2)��Դ�������������ֵ,���ö�̬�滮
//��ǰ����Ԥ����,������o(1)��ʱ��õ����,����ʱ�临�Ӷ�o(n),�ռ临�Ӷ�o(n)
int trap1_upgrade(vector<int>& height) {
    if (height.empty())
        return 0;
    int cnt = 0;
    int n = height.size();
    //leftMax[i]����height[i]�������ֵ
    //rightMax[i]����height[i]�Ҳ�����ֵ
    vector<int> leftMax(n),rightMax(n);
    leftMax[0] = leftMax[n - 1] = INT_MIN;
    rightMax[0] = rightMax[n - 1] = INT_MIN;

    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i - 1]);
    }
    for (int i = n-2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i + 1]);
    }
    for (int i = 1; i < n - 1; ++i) {
        cnt += std::max(0, std::min(leftMax[i], rightMax[i]) - height[i]);
    }
    return cnt;
}/*
 ����ⷽ��2:����ջ
 ����ջ�洢�±�,�����ջ�׵�ջ�����±��Ӧ������Ԫ�صݼ�
 
 �������±�i��ʱ��
 ���ջ��Ԫ����2��,ջ��top,ջ����left

 height[left]>=height[top]

 ���height[i]>height[top],��õ�һ�����Խ���ˮ������
 ���:i-left-1
 �߶�:

 �������,��ʱ�ȷ�һ��
 */
int trap2(vector<int>& height) {
    if (height.empty())
        return 0;


 
}
/*
�����3:˫ָ�뷽��
leftMax�������Ҽ���,rightMax��������߼������ʹ��˫ָ���������

����ָ��:left,right
��������:leftMax,rightMax
left = 0,right=n-1
leftMax = 0,rightMax = 0
leftֻ����,rightMaxֻ����,�ƶ�ָ��Ĺ���ά��������ֵ

����ָ��û������:
����height[left],height[right]��ֵ
����leftMax,rightMax

1.height[left]<height[right]
��Ȼ��leftMax<rightMax
�±�left�ܽӵ�ˮ��ˮ��Ϊ:leftMax-height[left]
left+1
2.height[left]>=height[right],leftMax>=rightMax
�±�right�ܽӵ�ˮ��:rightMax - height[right],right-1

����ָ��������ʱ��,���ܵõ����ս��

*/
int trap3(vector<int>& height) {
    if (height.empty())
        return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    while (left < right) {
        leftMax = std::max(leftMax, height[left]);
        rightMax = std::max(rightMax, height[right]);
        if (leftMax < rightMax) {
            ans += leftMax - height[left++];
        }
        else {
            ans += rightMax - height[right--];
        }
    }
    return ans;
}
void test01()
{
    vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << trap1(height) << endl;

}
int main()
{
	test01();
}
#endif