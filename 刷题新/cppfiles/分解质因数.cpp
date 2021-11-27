#if true
#include "../headers/wjxHeaders.h"


#include <iostream>
#include <vector>
using namespace std;
//兴业数金笔试题
vector<int> get(int num) 
{
    if (num<3)
        return {num};
    vector<int> ret;
    ret.reserve(5);
    for(int i=2;i<num;++i) {
        if (num%i==0) {
            num/=i;
            ret.push_back(i);
            i=1;
        }
    }
    ret.push_back(num);
    return ret;
}

void test01()
{
    printVector(get(4));
    
}

int main() {

	test01();
	return 0;
}

#endif