#if 0
#include "../headers/wjxHeaders.h"


int compareVersion(string version1, string version2) {

    int i = 0, j = 0;

    stringstream s1(version1);
    stringstream s2(version2);

    vector<int> vec1, vec2;
    string str;
    while (getline(s1, str, '.')) {
        vec1.push_back(stoi(str));
    }
    while (getline(s2, str, '.')) {
        vec2.push_back(stoi(str));
    }
    int n1 = vec1.size();
    int n2 = vec2.size();
    while (true) {
        if (i == n1 && j == n2)
            break;
        if (i == n1) {
            if (vec2[j] == 0)
                ++j;
            else
                return -1;
        }
        else if (j == n2) {
            if (vec1[i] == 0)
                ++i;
            else
                return 1;
        }
        else {
            if (vec1[i] > vec2[j])
                return 1;
            else if (vec1[i] < vec2[j])
                return -1;
            else {
                ++i;
                ++j;
            }
        }
    }
    return 0;
}
void test01()
{
	string str = "0001";
	int num = stoi(str);
	cout << num << endl;
}
int main()
{
	test01();
}
#endif