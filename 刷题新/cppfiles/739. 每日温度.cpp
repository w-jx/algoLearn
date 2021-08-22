#if 0
#include "../headers/wjxHeaders.h"
//�����ⷨ,��ʱ
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (temperatures[j] > temperatures[i]) {
				res[i] = j - i;
				break;
			}
		}
	}
	return res;

}
//����ô�Ż�ʱ�临�Ӷ�,��Ȼ��ʱ��
//[73, 74, 75, 71, 69, 72, 76, 73]
vector<int> dailyTemperatures2(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    //rightMax[i]����temperatures[i]��������Ԫ���±�
    //rightMax[n-1]=n,����û��
    vector<int> rightMax(n, n);

    for (int i = n - 2; i >= 0; --i) {
        if (temperatures[i] < temperatures[i + 1]) {
            res[i] = 1;
            rightMax[i] = i + 1;
        }
        else if (temperatures[i] == temperatures[i + 1]) {
            if (res[i + 1] == 0)
                res[i] = 0;
            else
                res[i] = res[i + 1] + 1;
            rightMax[i] = rightMax[i + 1];
        }
        else { //���ڵ����
            for (int j = rightMax[i + 1]; j < n; ++j) {
                if (temperatures[i] < temperatures[j]) {
                    res[i] = j - i;
                    rightMax[i] = j;
                    break;
                }
            }
        }
    }
    return res;

}
//ȥ�����ڵ�ʱ����ȵ�������ж�,��� j = rightMax[j];ͨ��
vector<int> dailyTemperatures3(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    //rightMax[i]����temperatures[i]��������Ԫ���±�
    //rightMax[n-1]=n,����û��
    vector<int> rightMax(n, n);

    for (int i = n - 2; i >= 0; --i) {
        if (temperatures[i] < temperatures[i + 1]) {
            res[i] = 1;
            rightMax[i] = i + 1;
        }
        else { 
            if (rightMax[i + 1] == n)
                continue;
            //���ڵ����
            for (int j = rightMax[i + 1]; j < n;) {
                if (temperatures[i] < temperatures[j]) {
                    res[i] = j - i;
                    rightMax[i] = j;
                    break;
                }
                else {//temperatures[i] >= temperatures[j]
                    j = rightMax[j];
                    if (j == n)
                        break;
                }
            }
        }
    }
    return res;
}
/*
�����:����ջ
�洢�±�,�±��Ӧ���¶����εݼ�
���һ���±��ڵ���ջ��,��ʾ��û���ҵ���һ���¶ȸ��ߵ��±�

����,����ÿ��Ԫ��temp[i],ջΪ��,ֱ�ӽ�ջ
�Ƚϵ�ǰջ��topIdx��Ӧ���¶�ֵtempTop��temp[i]
1.
    temp[i]>tempTop


*/
vector<int> dailyTemperatures4(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> s;
    vector<int> res(n);

    for (int i = 0; i < n; ++i) {
        if (s.empty())
            s.push_back(i);
        else {
            while (!s.empty() && temperatures[s.back()] < temperatures[i]) {
                res[s.back()] = i - s.back();
                s.pop_back();
            }
            s.push_back(i);
        }
    }
    return res;
    
}
void test01()
{
	// [1, 1, 4, 2, 1, 1, 0, 0]��
	//1 1 0 4 1 1 0 0
	vector<int> temp{ 73, 74, 75, 71, 69, 72, 76, 73 };
	//[8,1,5,4,3,2,1,1,0,0]
	vector<int> temp1{ 89,62,70,58,47,47,46,76,100,70 };
	auto ret = dailyTemperatures2(temp1);
	printVector(ret);
}
int main()
{
	test01();
}


#endif