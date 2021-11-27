#if true
#include "../headers/wjxHeaders.h"

//2 3 6    如果一个数的平方  可以整除所有数字的乘积   那么就是魔法数，找到最小的魔法数
//2*3*6 = 36,36/(2*2)=9,所以2 是魔法数
int get_min_magic(vector<int>&nums){
    int n = nums.size();

    sort(nums.begin(),nums.end());
    long long product =1;
    for(const auto &num:nums) {
        product*=num;
    }
    unordered_set<int> hash;
    for(const auto&num:nums) {
        if (hash.find(num)!=hash.end()) {
            hash.insert(num);
            if (product%num==0) {
                return num;
            }
        }
    }
}


void test01()
{

}

int main() {

	test01();
	return 0;
}

#endif