#if 0
#include "../headers/wjxHeaders.h"

string addStrings(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    int i = n1 - 1, j = n2 - 1;
    int extra = 0, sum = 0, val = 0;
    string str;
    while (true) {
        if (i < 0 && j < 0) {
            if (extra != 0)
                str += extra + '0';
            reverse(str.begin(), str.end());
            break;
        }
        if (i < 0) {
            sum = num2[j--] - '0' + extra;
            extra = sum / 10;
            val = sum % 10;
            str += val + '0';

        }
        else if (j < 0) {
            sum = num1[i--] - '0' + extra;
            extra = sum / 10;
            val = sum % 10;
            str += val + '0';
        }
        else {
            sum = num1[i--] - '0' + num2[j--] - '0' + extra;
            extra = sum / 10;
            val = sum % 10;
            str += val + '0';
        }
    }
    return str;
}
void test01()
{
    string num1 = "258";
    string num2 = "1120";
   cout << addStrings(num1, num2) << endl;

}
int main()
{
	test01();
}
#endif