#if 0
#include "../headers/wjxHeaders.h"

//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

auto sortstr = [=](const string& str)->string {
	
	string newstr = str;;
	//cout << "str=" << str << endl;
	//cout << "newstr=" << newstr << endl;
	int len = str.size();
	//cout << "len=" << len << endl;
	int step = len / 2;
	
	char temp;
	int j;
	while (step >= 1) {
		for (int i = step; i < len; i++) {
			temp = newstr[i];
			j = i - step;

			while (j >= 0 && str[j] > temp) {
				newstr[j + step] = newstr[j];
				j -= step;
			}
			newstr[j + step] = temp;
		}
		step--;
	}
	return newstr;
};

string sort(const string& str)
{
	string newstr(str);
	char temp;
	int j;
	for (int i = 1; i < str.size(); i++) {
		temp = newstr[i];
		j = i - 1;
		while (j >= 0 && newstr[j] > temp) {
			newstr[j + 1] = newstr[j];
			j--;
		}
		newstr[j + 1] = temp;
	}
	return newstr;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	if (strs.size() == 0)
		return {};

	auto sortstr = [=](const string& str)->string {
		string newstr(str);
		char temp;
		int j;
		for (int i = 1; i < str.size(); i++) {
			temp = newstr[i];
			j = i - 1;
			while (j >= 0 && newstr[j] > temp) {
				newstr[j + 1] = newstr[j];
				j--;
			}
			newstr[j + 1] = temp;
		}
		return newstr;
	};
	unordered_map<string, vector<string>> hashtable;
	for (auto iter : strs) {
		auto newstring = sortstr(iter);
		hashtable[newstring].emplace_back(iter);
	}
	vector<vector<string>> vret;
	vector<string> vclass;
	for (auto iter : hashtable) {
		for (auto it : iter.second) {
			vclass.emplace_back(it);
		}
		vret.emplace_back(vclass);
		vclass.clear();
	}
	return vret;

}
//方法2,不用排序过后的字符串做key,而是统计每个字符串中各个字母出现的位置做key
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
	map<vector<int>, vector<string> > strmap;
	for (auto str : strs) {
		vector<int> key(26);
		for (int i = 0; i < str.size(); ++i) {
			key[str[i] - 'a']++;
		}
		strmap[key].push_back(str);
	}
	vector<vector<string> > res;
	for (auto iter : strmap)
		res.push_back(iter.second);
	return res;
}
vector<vector<string>> groupAnagrams3(vector<string>& strs) {
	map<array<int,26>, vector<string> > strmap;
	array<int, 26> myarr{ 0 };
	for (auto str : strs) {
		myarr.fill(0);
		for (int i = 0; i < str.size(); ++i) {
			myarr[str[i] - 'a']++;
		}
		strmap[myarr].push_back(str);
	}
	vector<vector<string> > res;
	for (auto iter : strmap)
		res.push_back(iter.second);
	return res;
}
void test01()
{
	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat" };
	auto getvstring=groupAnagrams3(v);
	printvectorvector(getvstring);
}
int main()
{
	
	test01();

	
	system("pause");
	return 0;
}


#endif