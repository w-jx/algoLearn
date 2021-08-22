#if 0
#include "../headers/wjxHeaders.h"

/// <summary>
/// 传入一个数组,构造一个线段树(数组)
/// </summary>
/// <param name="value">线段树数组</param>
/// <param name="nums">原数组</param>
/// <param name="pos">线段树指针,初始从0开始</param>
/// <param name="left">原数组左端点,初始为0</param>
/// <param name="right">原数组右端点,初始为数组大小减1</param>
void build_segment_tree(vector<int>& value, vector<int>& nums,int pos,int left,int right)
{
    if (left == right) {//说明到叶子结点了,可以给线段树赋值了
        value[pos] = nums[left];
        return;
    }
    int mid = left + (right - left) / 2;//把区间分成2段
    build_segment_tree(value, nums, 2 * pos + 1, left, mid);//求左区间的和
    build_segment_tree(value, nums, 2 * pos + 2, mid + 1, right);//求右区间的和

    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];//总和是左右区间总和
}

/// <summary>
/// 求数组nums在区间[pleft,pright]的区间和
/// </summary>
/// <param name="value">线段树数组</param>
/// <param name="pos">线段树下标指针,初始是0</param>
/// <param name="left">原数组左端点,初始0</param>
/// <param name="right">原数组右端点,初始数组大小减少1</param>
/// <param name="pleft">待求的左区间</param>
/// <param name="pright">待求的右区间</param>
/// <returns>[pleft,pright]区间和</returns>
int sum_range_segment_tree(vector<int>& value, int pos, int left, int right, int pleft, int pright) {
    if (pright<left || pleft>right)//待求的区间不在原数组范围内,返回0
        return 0;
    //原数组范围 完全被待求区间包围了
    if (pleft <= left && pright >= right)
        return value[pos];

    int mid = left + (right - left) / 2;
    return sum_range_segment_tree(value, 2 * pos + 1, left, mid, pleft, pright) +
        sum_range_segment_tree(value, 2 * pos + 2, mid, right, pleft, pright);

}
/// <summary>
/// 原数组数组变动,更新线段树中的和
/// </summary>
/// <param name="value">线段树</param>
/// <param name="pos">线段树指针,初始为0</param>
/// <param name="left">原数组左端点,初始为0</param>
/// <param name="right">原数组右端点,初始为数组大小减1</param>
/// <param name="idx">原数组中修改的数组下标</param>
/// <param name="new_val">原数组修改的值</param>
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

    //不管左子树还是右子树更新了,当前结点的值也要更新
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty())
            return;
        numslen = nums.size();
        //线段树 数组的大小是原数组大小的4倍
        int n = numslen * 4;
        for (int i = 0; i < n; ++i)
            _value.push_back(0);
        build_segment_tree(_value, nums, 0, 0, numslen - 1);
        _right_end = numslen - 1;//线段树的右端点,为数组大小减少1
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