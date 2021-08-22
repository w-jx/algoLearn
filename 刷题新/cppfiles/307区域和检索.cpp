#if 0
#include "../headers/wjxHeaders.h"

/// <summary>
/// ����һ������,����һ���߶���(����)
/// </summary>
/// <param name="value">�߶�������</param>
/// <param name="nums">ԭ����</param>
/// <param name="pos">�߶���ָ��,��ʼ��0��ʼ</param>
/// <param name="left">ԭ������˵�,��ʼΪ0</param>
/// <param name="right">ԭ�����Ҷ˵�,��ʼΪ�����С��1</param>
void build_segment_tree(vector<int>& value, vector<int>& nums,int pos,int left,int right)
{
    if (left == right) {//˵����Ҷ�ӽ����,���Ը��߶�����ֵ��
        value[pos] = nums[left];
        return;
    }
    int mid = left + (right - left) / 2;//������ֳ�2��
    build_segment_tree(value, nums, 2 * pos + 1, left, mid);//��������ĺ�
    build_segment_tree(value, nums, 2 * pos + 2, mid + 1, right);//��������ĺ�

    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];//�ܺ������������ܺ�
}

/// <summary>
/// ������nums������[pleft,pright]�������
/// </summary>
/// <param name="value">�߶�������</param>
/// <param name="pos">�߶����±�ָ��,��ʼ��0</param>
/// <param name="left">ԭ������˵�,��ʼ0</param>
/// <param name="right">ԭ�����Ҷ˵�,��ʼ�����С����1</param>
/// <param name="pleft">�����������</param>
/// <param name="pright">�����������</param>
/// <returns>[pleft,pright]�����</returns>
int sum_range_segment_tree(vector<int>& value, int pos, int left, int right, int pleft, int pright) {
    if (pright<left || pleft>right)//��������䲻��ԭ���鷶Χ��,����0
        return 0;
    //ԭ���鷶Χ ��ȫ�����������Χ��
    if (pleft <= left && pright >= right)
        return value[pos];

    int mid = left + (right - left) / 2;
    return sum_range_segment_tree(value, 2 * pos + 1, left, mid, pleft, pright) +
        sum_range_segment_tree(value, 2 * pos + 2, mid, right, pleft, pright);

}
/// <summary>
/// ԭ��������䶯,�����߶����еĺ�
/// </summary>
/// <param name="value">�߶���</param>
/// <param name="pos">�߶���ָ��,��ʼΪ0</param>
/// <param name="left">ԭ������˵�,��ʼΪ0</param>
/// <param name="right">ԭ�����Ҷ˵�,��ʼΪ�����С��1</param>
/// <param name="idx">ԭ�������޸ĵ������±�</param>
/// <param name="new_val">ԭ�����޸ĵ�ֵ</param>
void update_range_segmet_tree(vector<int>& value, int pos, int left, int right, int idx, int new_val)
{
    if (left == right && left == idx) {
        value[pos] = new_val;
        return;
    }
    int mid = left + (right - left) / 2;
    if (idx < mid) {
        update_range_segmet_tree(value, 2 * pos + 1, left, mid, idx, new_val);
    }
    else {
        update_range_segmet_tree(value, 2 * pos + 2, mid + 1, right, idx, new_val);
    }

    //��������������������������,��ǰ����ֵҲҪ����
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty())
            return;
        numslen = nums.size();
        //�߶��� ����Ĵ�С��ԭ�����С��4��
        int n = numslen * 4;
        for (int i = 0; i < n; ++i)
            _value.push_back(0);
        build_segment_tree(_value, nums, 0, 0, numslen - 1);
        _right_end = numslen - 1;//�߶������Ҷ˵�,Ϊ�����С����1
    }

    void update(int index, int val) {

    }

    int sumRange(int left, int right) {
        return sum_range_segment_tree(_value, 0, 0, numslen - 1, left, right);
    }
private:
    vector<int> _value;
    int _right_end;
    int numslen;
};

void test01()
{

}
int main()
{
	system("pause");
	return 0;
}


#endif