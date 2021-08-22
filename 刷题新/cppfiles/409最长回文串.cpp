#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���

ע�⣺û��Ҫ��˳��

*/
//����1��leetcode �ύ��
int longestPalindrome(string s) {
    if (s.size() <= 1)
        return s.size();
    unordered_set<char> hashset;
    int nums = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (hashset.count(s[i]) > 0) {
            nums += 2;
            hashset.erase(s[i]);
        }
        else
            hashset.insert(s[i]);
    }
    if (hashset.size() >= 1)
        nums += 1;
    return nums;

}
//ˢ���̳� ����
int longestPalindrome2(string s) {
    int char_map[128] = { 0 };//�ַ���ϣ
    int max_length = 0;//���Ĵ�ż�����ֵ���󳤶�
    int flag = 0;//�Ƿ������ĵ�

    for (int i = 0; i < s.size(); i++) {
        char_map[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (char_map[i] % 2 == 0) {
            max_length += char_map[i];//�����ַ�������ż�����ģ�ȫ��ʹ��
        }
        else {//�����ַ���������ż���ģ��Ǽ�ȥһ�����ż��
            max_length += char_map[i] - 1;
            flag = 1;
        }
    }
    return max_length + flag;

}
void test01()
{
    string str("abccccdd");
    cout << longestPalindrome2(str) << endl;

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif