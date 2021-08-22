#if 0
#include "../headers/wjxHeaders.h"

vector<int> findDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1)
        return {};
    vector<int> vret;
    unordered_set<int> hashset;
    for (int i = 0; i < len; i++) {
        while (nums[i] != (i + 1)) {
            int m = nums[i] - 1;

            if (nums[m] == m + 1) {
                if (hashset.count(m + 1) == 0) {
                    vret.push_back((m + 1));
                    hashset.insert(m + 1);
                }
                   
                break;
            }
            nums[i] = nums[m];
            nums[m] = m + 1;
        }
    }
    return vret;
}
void test01()
{
    vector<int> v{ 4,3,2,7,8,2,3,1 };
    printVector(findDuplicates(v));


}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif