#if 0
#include "../headers/wjxHeaders.h"
/*

归并排序解决

二叉查找树 解决

目前二叉搜索树是超时的,数据量超级大,想办法利用红黑树解决
修改下set

*/
void crossAndGet(vector<int>& nums, vector<int>& temp, vector<int>& vret, int left, int mid, int right)
{
    copy(nums.begin() + left, nums.begin() + right + 1, temp.begin() + left);
    int i = left, j = mid + 1, count = 0;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) {
            nums[k] = temp[j++];
        }
        else if (j == right + 1) {
            nums[k] = temp[i++];
        }
        else if (temp[i] <= temp[j]) {
            nums[k] = temp[i++];
        }
        else {//temp[i]>temp[j]
            count += (right - j + 1);
            nums[k] = temp[j++];
        }
    }
    vret.push_back(count);

}
vector<int> mergeSort(vector<int>& nums, vector<int>& vtemp, vector<int>& vret, int left, int right) {
    if (left >= right) return { 0 };
    int mid = left + (right - left) / 2;
    mergeSort(nums, vtemp, vret, left, mid);
    mergeSort(nums, vtemp, vret, mid + 1, right);
    crossAndGet(nums, vtemp, vret, left, mid, right);

    return vret;
}
vector<int> countSmaller(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return { 0 };
    vector<int> vtemp(len);
    vector<int> vret(len);
    return mergeSort(nums, vtemp, vret, 0, len - 1);
}
void test01()
{
    vector<int> vret{ 5,2,6,1 };
    printVector(countSmaller(vret));
}
//void mergeArray2(vector<int>& nums, int left, int mid, int right)
//{
//    int idx2 = mid + 1, idx1 = left;
//    vector<int> temp;
//    while (idx1 <= mid && idx2 <= right) {
//        if (nums[idx1] < nums[idx2]) {
//            temp.push_back(nums[idx1++]);
//        }
//        else {
//            temp.push_back(nums[idx2++]);
//        }
//    }
//    while (idx1 <= mid)
//        temp.push_back(nums[idx1++]);
//    while (idx2 <= right)
//        temp.push_back(nums[idx2++]);
//
//    for (int i = 0; left<=right; i++) {
//        nums[left++] = temp[i];
//    }
//}
//void mergeSort2(vector<int>& nums, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        mergeSort2(nums, left, mid);
//        mergeSort2(nums, mid + 1, right);
//        mergeArray2(nums, left, mid, right);
//    }
//}
//vector<int> sortArray2(vector<int>& nums) {
//    mergeSort2(nums, 0, nums.size() - 1);
//    return nums;
//}
//
//
//void test02()
//{
//    vector<int> v{ 1,5,2,3,7 };
//    sortArray2(v);
//    for_each(v.begin(), v.end(), [=](int x) {cout << x << " "; });
//}

//思路2：将数组逆序，插入到二叉搜索树中,新创造一种数据结构，能够记录左子树结点
struct BSTNode {
    int val;
    int count;//二叉树左子树中结点的个数
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x ):val(x),left(nullptr),right(nullptr),count(0){}
};
//记录左子树结点的二叉搜索树的插入操作 count_small是二叉搜索树中比insert_node值小的节点个数
void BST_insert(BSTNode* node, BSTNode* insert_node, int& count_small) {
    if (!node)
        return;
    if (insert_node->val <= node->val) {//注意是 小于等于，小于的时候个数不正确
        node->count++;
        
        if (node->left) {
            BST_insert(node->left, insert_node, count_small);
        }
        else
            node->left = insert_node;
    }
    else {
        count_small += node->count + 1;
        if (node->right) {
            BST_insert(node->right, insert_node, count_small);
        }
        else
            node->right = insert_node;
    }
}
//用思路2 解决问题
vector<int> countSmaller2(vector<int>& nums) {
                    
    vector<BSTNode*> node_vec;//二叉查找树节点池

    vector<int> count;//从后向前插入过程，比当前节点小的

    for (int i = nums.size() - 1; i >= 0; i--) {//按照从后往前的顺序创建二叉查找树节点
        
        node_vec.push_back(new BSTNode(nums[i]));
    }
    count.push_back(0);//第一个节点左侧为空，所以比它小的个数为0

    for (int i = 1; i < node_vec.size(); i++) {
        int count_small = 0;//从第二个节点插入，同时计算每个节点左侧比其小的节点个数
        BST_insert(node_vec[0], node_vec[i], count_small);
        count.push_back(count_small);
    }
    for (int i = 0; i < node_vec.size(); i++) {//自定义数据结构，使用完毕释放内存
        delete node_vec[i];
    }
    reverse(count.begin(), count.end());
    return count;
}
void test02()
{
    //vector<int> nums{ 5,2,6,1 };
    vector<int> nums{ 26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41 };
    auto res = countSmaller2(nums);
    for (auto iter : res)
        cout << iter << " ";
    cout << endl;
    
}
vector<int> ans;//存储结果的
void mergeArray(vector<int>& nums, vector<int>& index, vector<int>& tempidx, vector<int>& temp, int left, int mid, int right)
{
    std::copy(nums.begin() + left, nums.begin() + right + 1, temp.begin() + left);
    std::copy(index.begin() + left, index.begin() + right + 1, tempidx.begin() + left);
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) {//左边数组已经到尽头了
            nums[k] = temp[j];
            tempidx[k] = index[j];
            ++j;
        }
        else if (j == right + 1) {//右边数组到尽头了
            nums[k] = temp[i];
            tempidx[k] = index[i];
            /*
            如果右边数组到尽头，那么说明右边的所有都比
            左边当前元素小
            */
            ans[index[i]] += (j - mid - 1);
            ++i;
        }
        /*
            左边 8 .... 右边 7 7 7 26
            当8<26的时候，我们应该把8加入数组
            可以发现26左边有三个数字
            也就是有3个数字比8小，所以
            8的结果数组加3

            例如26为j,右边从mid+1开始结算
            所以应该是j-(mid+1)=j-mid-1，不包括26所以不用在
            +1
        */
        else if (temp[i] <= temp[j]) {
            nums[k] = temp[i];
            tempidx[k] = index[i];
            ans[index[i]] += (j - mid - 1);
            ++i;
        }
        else if (temp[i] > temp[j]) {
            nums[k] = temp[j];
            tempidx[k] = index[j];
            ++j;
        }
    }//for循环逻辑 
    for (int k = left; k <= right; k++) {
        index[k] = tempidx[k];
    }


}
void mergeSort2(vector<int>& nums, vector<int>& index, vector<int>& tempidx, vector<int>& temp, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    mergeSort2(nums, index, tempidx, temp, left, mid);
    mergeSort2(nums, index, tempidx, temp, mid + 1, right);
    mergeArray(nums, index, tempidx, temp, left, mid, right);
}
vector<int> countSmaller3(vector<int>& nums) {
    if (nums.size() < 2)
        return { 0 };
    int len = nums.size();
    vector<int> index(len, 0);
    vector<int> tempidx(len, 0);
    vector<int> temp(len, 0);//分配空间
    ans.resize(len, 0);//返回最终结果
    for (int i = 0; i < len; i++)
        index[i] = i;//下标数组
    mergeSort2(nums, index, tempidx, temp, 0, len - 1);
    return ans;
}
//测试leetcode 官方题解
void test03()
{
    vector<int> nums{ 5,2,6,1 };
    auto ret = countSmaller3(nums);
    for (auto iter:ret)
        cout << iter << " ";
    cout << endl;
}
class MyRBTree
{
public:
    int count;

private:
    set<int> myset;

};
void test04()
{
    set<int> myset;
    //myset.insert(5);
    //myset.insert(2);
    //upper_bound >  lower_bound >=
    
   //auto iter = myset.lower_bound(1);
   //if (iter == myset.end())
   //    cout << "not find:" << 1 << endl;
   //else
   //    cout << "find:" << 1 << endl;
   //cout << std::distance(myset.begin(), iter) << endl;
   //myset.insert(1);
  

   // iter = myset.lower_bound(6);
   // cout << std::distance(myset.begin(), iter)  << endl;
   // myset.insert(6);
   // 

   // iter = myset.lower_bound(2);
   // cout << std::distance(myset.begin(), iter) << endl;
   // myset.insert(2);
   //

   // iter = myset.lower_bound(5);
   // cout << std::distance(myset.begin(), iter) << endl;
   // myset.insert(5);


    auto iter = myset.lower_bound(-1);
    cout << std::distance(myset.begin(), iter) << endl;
    myset.insert(-1);

    iter = myset.lower_bound(-1);
    cout << std::distance(myset.begin(), iter) << endl;
    myset.insert(-1);
    
}
int main()
{
    //test01();
    test02();
    //test03();
    //test04();
	system("pause");
	return 0;
}
#endif