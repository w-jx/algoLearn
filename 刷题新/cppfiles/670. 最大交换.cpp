#if 0
#include "../headers/wjxHeaders.h"

int getnum(vector<int>& num_vec) {
	int retnum = 0;
	for (auto numiter = num_vec.begin(); numiter != num_vec.end(); ++numiter) {
		retnum = retnum * 10 + (*numiter);
	}
	return retnum;
}
/*
ͨ��,
ʱ�临�Ӷȿ�����o(n^2)

*/
int maximumSwap(int num) {
	vector<int> num_vec;
	num_vec.reserve(10);
	int retnum = num;
	while (num > 0) {
		num_vec.push_back(num % 10);
		num /= 10;
	}
	int n = num_vec.size();
	reverse(num_vec.begin(), num_vec.end());//���з�ת

	cout << "num_vec:\n";
	printVector(num_vec);


	//rightMax[i]�����ұ߱�num_vec[i]���Ԫ�ص��±�
	vector<int> rightMax(n,n);//rightMax[n-1]=n,���һ�����ұ�û�б������
	bool hasGreater = false;//���һ����,ÿ�������ұ߶�����С,˵���Ѿ������
	int maxnum = n-1;
	//��������rightMax����
	for (int i = n - 2; i >= 0; --i) {
		if (num_vec[i] < num_vec[maxnum]) {
			rightMax[i] = maxnum;
			hasGreater = true;
		}
		else if (num_vec[i] == num_vec[maxnum]) {
			rightMax[i] = maxnum;
		}
		else {
			maxnum = i;
		}
	}
	cout << "rightMax:\n";
	printVector(rightMax);

	if (!hasGreater)
		return retnum;
//������break,1993����������˻�1��9����,���9193,Ӧ����9913�Ŷ�	
	for (int i = 0; i < n; ++i) {
		if (rightMax[i] != n) {
			auto tempvec = num_vec;
			swap(tempvec[i], tempvec[rightMax[i]]);
			int temp = getnum(tempvec);
			retnum = std::max(retnum, temp);
		}
	}
	return retnum;
}
//�������������,���Դ�˵,ʱ�临�Ӷ�o(n)��
int maximumSwap2(int num) {
	vector<int> num_vec;
	num_vec.reserve(10);
	int retnum = num;
	while (num > 0) {
		num_vec.push_back(num % 10);
		num /= 10;
	}
	int n = num_vec.size();
	reverse(num_vec.begin(), num_vec.end());//���з�ת

	cout << "num_vec:\n";
	printVector(num_vec);


	//rightMax[i]�����ұ߱�num_vec[i]���Ԫ�ص��±�
	vector<int> rightMax(n, n);//rightMax[n-1]=n,���һ�����ұ�û�б������
	bool hasGreater = false;//���һ����,ÿ�������ұ߶�����С,˵���Ѿ������
	int maxnum = n - 1;
	//��������rightMax����
	for (int i = n - 2; i >= 0; --i) {
		if (num_vec[i] < num_vec[maxnum]) {
			rightMax[i] = maxnum;
			hasGreater = true;
		}
		else if(num_vec[i]>num_vec[maxnum]){
			maxnum = i;
		}
		//��ȵ�������ô���,����1993�������
	}
	cout << "rightMax:\n";
	printVector(rightMax);

	if (!hasGreater)
		return retnum;
	//������break,1993����������˻�1��9����,���9193,Ӧ����9913�Ŷ�	
	for (int i = 0; i < n; ++i) {
		if (rightMax[i] != n) {
			swap(num_vec[i], num_vec[rightMax[i]]);
			retnum = getnum(num_vec);
			break;
		}
	}
	return retnum;
}

//num_vec����to_string �����,�������÷�ת,ͬ��ͨ��
//��׼����������
int maximumSwap3(int num) {
	int retnum = num;
	string numstr = to_string(num);
	int n = numstr.size();

	//rightMax[i]�����ұ߱�num_vec[i]���Ԫ�ص��±�
	vector<int> rightMax(n, n);//rightMax[n-1]=n,���һ�����ұ�û�б������
	bool hasGreater = false;//���һ����,ÿ�������ұ߶�����С,˵���Ѿ������
	int maxnum = n - 1;
	//��������rightMax����
	for (int i = n - 2; i >= 0; --i) {
		if (numstr[i] < numstr[maxnum]) {
			rightMax[i] = maxnum;
			hasGreater = true;
		}
		else if (numstr[i] > numstr[maxnum]) {
			maxnum = i;
		}
		//��ȵ�������ô���,����1993�������
	}
	if (!hasGreater)
		return retnum;
	//������break,1993����������˻�1��9����,���9193,Ӧ����9913�Ŷ�	
	for (int i = 0; i < n; ++i) {
		if (rightMax[i] != n) {
			swap(numstr[i], numstr[rightMax[i]]);
			retnum = stoi(numstr);
			break;
		}
	}
	return retnum;
}
void test01()
{
	cout << maximumSwap2(1993) << endl;
}
int main()
{
	test01();
}
#endif