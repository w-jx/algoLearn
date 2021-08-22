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
通过,
时间复杂度可能是o(n^2)

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
	reverse(num_vec.begin(), num_vec.end());//进行翻转

	cout << "num_vec:\n";
	printVector(num_vec);


	//rightMax[i]代表右边比num_vec[i]大的元素的下标
	vector<int> rightMax(n,n);//rightMax[n-1]=n,最后一个数右边没有比它大的
	bool hasGreater = false;//如果一个数,每个数字右边都比它小,说明已经最大了
	int maxnum = n-1;
	//下面生成rightMax数组
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
//如果这边break,1993这个测试用了会1和9交换,变成9193,应该是9913才对	
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
//这个才是正常的,可以大胆说,时间复杂度o(n)了
int maximumSwap2(int num) {
	vector<int> num_vec;
	num_vec.reserve(10);
	int retnum = num;
	while (num > 0) {
		num_vec.push_back(num % 10);
		num /= 10;
	}
	int n = num_vec.size();
	reverse(num_vec.begin(), num_vec.end());//进行翻转

	cout << "num_vec:\n";
	printVector(num_vec);


	//rightMax[i]代表右边比num_vec[i]大的元素的下标
	vector<int> rightMax(n, n);//rightMax[n-1]=n,最后一个数右边没有比它大的
	bool hasGreater = false;//如果一个数,每个数字右边都比它小,说明已经最大了
	int maxnum = n - 1;
	//下面生成rightMax数组
	for (int i = n - 2; i >= 0; --i) {
		if (num_vec[i] < num_vec[maxnum]) {
			rightMax[i] = maxnum;
			hasGreater = true;
		}
		else if(num_vec[i]>num_vec[maxnum]){
			maxnum = i;
		}
		//相等的情况不用处理,例如1993这个例子
	}
	cout << "rightMax:\n";
	printVector(rightMax);

	if (!hasGreater)
		return retnum;
	//如果这边break,1993这个测试用了会1和9交换,变成9193,应该是9913才对	
	for (int i = 0; i < n; ++i) {
		if (rightMax[i] != n) {
			swap(num_vec[i], num_vec[rightMax[i]]);
			retnum = getnum(num_vec);
			break;
		}
	}
	return retnum;
}

//num_vec利用to_string 来解决,这样不用翻转,同样通过
//标准答案了属于是
int maximumSwap3(int num) {
	int retnum = num;
	string numstr = to_string(num);
	int n = numstr.size();

	//rightMax[i]代表右边比num_vec[i]大的元素的下标
	vector<int> rightMax(n, n);//rightMax[n-1]=n,最后一个数右边没有比它大的
	bool hasGreater = false;//如果一个数,每个数字右边都比它小,说明已经最大了
	int maxnum = n - 1;
	//下面生成rightMax数组
	for (int i = n - 2; i >= 0; --i) {
		if (numstr[i] < numstr[maxnum]) {
			rightMax[i] = maxnum;
			hasGreater = true;
		}
		else if (numstr[i] > numstr[maxnum]) {
			maxnum = i;
		}
		//相等的情况不用处理,例如1993这个例子
	}
	if (!hasGreater)
		return retnum;
	//如果这边break,1993这个测试用了会1和9交换,变成9193,应该是9913才对	
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