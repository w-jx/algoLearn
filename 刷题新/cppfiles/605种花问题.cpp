#if 0
#include "../headers/wjxHeaders.h"


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n <= 0)
        return true;

    int len = flowerbed.size();
    flowerbed.push_back(0);
    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }

        }//i==0
        else {//i!=0
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }

        }//i!=0

    }

    return n <= 0;

}

void test01()
{
    vector<int> flower{ 1,0,0,0,0,1 };
    cout << canPlaceFlowers(flower, 2) << endl;
    printVector(flower);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif