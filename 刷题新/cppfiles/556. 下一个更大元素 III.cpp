#if 0
#include "../headers/wjxHeaders.h"


//�õ���ջ���뷨û�д�,�������������Խ��,���ߴ���
int nextGreaterElement(int n) {
    string nstr = to_string(n);
    int len = nstr.size();//�ж��ٸ�����
    vector<int> ret(len, -1);
    vector<int> stk;
    stk.reserve(len);

    for (int i = 0; i < len; ++i) {
        while (!stk.empty() && nstr[stk.back()] < nstr[i]) {
            ret[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    auto iter = find_if(ret.rbegin(), ret.rend(), [=](int x)->bool {return x != -1; });
    if (iter == ret.rend())
        return n;
    int idx = ret.rend() - iter - 1;
    swap(nstr[idx], nstr[ret[idx]]);//���н���,�϶���ԭ������
    //����������Ҫ��֤����idx,�������������С
    ++idx;
    while (idx < len - 1) {
        if (nstr[idx] > nstr[idx + 1]) {
            swap(nstr[idx], nstr[idx + 1]);
        }
        ++idx;
    }
    long long nretll = stoll(nstr);
    if (nretll > INT_MAX)
        return -1;
    return nretll;
}
//�����˼·
int nextGreaterElement2(int n) {
    string nstr = to_string(n);
    int len = nstr.size();//�ж��ٸ�����
    if (len < 2)//1������0��,�Ҳ���,�ֽڷ���-1
        return -1;
    //���ҵ���С������
    int i = len - 2;
    for (; i >= 0; --i) {
        if (nstr[i] < nstr[i + 1])
            break;
    }
    if (i < 0)//�Ҳ�����߱��ұ�С��,����ݼ�,�Ѿ��������
        return -1;
    //�ұ�nstr[i]�Դ������
    int j = len - 1;
    for (; j >= 0; --j) {
        if (nstr[j] > nstr[i]) {
            swap(nstr[j], nstr[i]);
            break;
        }
    }
    //��ת��i+1��ʼ������
    reverse(nstr.begin() + i + 1, nstr.end());
    long res = stol(nstr);
    return res > INT_MAX ? -1 : res;
}
void test01()
{
    //vector<int> ret{ 1,2,3,4,-1 ,-1};
    //auto iter = find_if(ret.rbegin(), ret.rend(), [=](int x)->bool {return x != -1; });
    //int idx =  ret.rend()- iter-1;
    //cout << idx << endl;
    //
    cout << nextGreaterElement2(2147483476) << endl;
}
int main()
{
	test01();
}
#endif