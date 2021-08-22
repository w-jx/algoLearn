#if 0
#include <iostream>
#include <vector>
using namespace std;
/*
leecodeÌâÄ¿½éÉÜ:


*/
vector<int> decompressRLElist(vector<int>& nums)
{
    vector<int> v;
    int size = nums.size();

    auto iter = v.begin();
    for (int i = 0; i < size; i += 2) {
        int time = nums[i];
        int value = nums[i + 1];

        // for(int j=0;j<time;j++) {
        //     v.push_back(value);
        // }
        iter = v.insert(iter, time, value);
        iter += time;
    }
    return v;


}
void printVector(vector<int>& v) {
    for (auto iter : v) {
        cout << iter << " ";
    }
    cout << endl;
}
void test01()
{
   /* vector<int> nums = { 1,2,3,4 };
    auto p = decompressRLElist(nums);
    printVector(p);*/

    vector<int> v;
    auto iter = v.begin();
    iter = v.insert(iter, 3, 5);
    printVector(v);
    iter += 3;
    v.insert(iter, 7);
    printVector(v);

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif