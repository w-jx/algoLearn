#if 0
#include <iostream>
#include <unordered_set>
using namespace std;

//使用了 额外的空间
int singleNumber(vector<int>& nums) {
    unordered_set<int> hashset;
    for (int num : nums) {
        if (hashset.count(num) == 0) {
            hashset.insert(num);
        }
        else {
            hashset.erase(num);
        }
    }
    return *hashset.begin();
}
void test01()
{
	vector<int> nums{ 4,1,2,1,4 };
	cout << singleNumber(nums) << endl;
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif