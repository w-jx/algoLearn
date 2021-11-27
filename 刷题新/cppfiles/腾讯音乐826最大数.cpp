#if true
#include "../headers/wjxHeaders.h"

//这个方法是完全是错误的，因为改变了数字的顺序

string max_num(string in, int k)
{

    int n = in.size();
    priority_queue<int, vector<int>, std::greater<>> que;
    for (int i = 0; i < n; ++i)
    {
        if (que.size() < k)
        {
            que.push(in[i] - '0');
        }
        else
        {
            if (in[i] - '0' > que.top())
            {
                que.pop();
                que.push(in[i] - '0');
            }
        }
    }
    string ret;
    ret.resize(k);
    int i = k - 1;
    while (!que.empty())
    {
        ret[i--] = que.top() + '0';
        que.pop();
    }
    return ret;
}
int max_num2(string in, int k)
{
    int n = in.size();//得到长度
    int left = 0,right = k-1;//滑动窗口的起点和终点下标，初始从0开始
    int start = 0;//保存最后结果

    for (int i = k; i < n; ++i)
    {
        //如果起点比原来的起点大，可以保证新的数要大。或者 起点和原来的起点相同，但是终点比原来的终点大，也可以保证新的数大
        if (in[left + 1] > in[left] || (in[left + 1] >= in[left] && in[k] > in[right]))
        {
            start = left + 1;//更新最后结果的起点下标
            left = left + 1;//分别更新滑动串口下标
            right = left+k-1;
        }
    }
    return stoi(in.substr(start,k));//最后根据起点和字符长度k截取子串
}

void test01()
{
    cout << max_num2("1234", 1) << endl; //输出4321，改变了数字的顺序
}
int main()
{
    test01();
    return 0;
}

#endif