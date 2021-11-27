#include "../headers/wjxHeaders.h"


/*
有100亿个数字，取其中最大的100个


*/


//这样有内存限制
vector<int> getTopHundredNums(vector<int> &numset) 
{
    priority_queue<int,vector<int>,greater<>> que;
    for(const auto num:numset) {
        if (que.size()<1000) {
            que.push(num);
        }
        else {
            if (que.top()<num) {
                que.pop();
                que.push(num);
            }
        }
    }
    vector<int> ret(1000);
    int i = 0;
    while (!que.empty()) {
        ret[i]=que.top();
        que.pop();
    }
    return ret;
}

//考虑分治的解法
//100'0000'0000 找100个
//100份，一份是1'0000'0000个
//在每份中再找到 每份的 10000个   10000*100份 = 100’00000
vector<int> getTopHundredNums(vector<int> &numset) 
{

}


void test01(){

}

int main()
{
    test01();
}