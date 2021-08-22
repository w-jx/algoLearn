#if 0
#include <iostream>
#include <set>
#include <ctype.h>

using namespace std;

int main() {

	srand((unsigned)time(nullptr));
	set<int> myset;
	int n;
	string str;
	int randnum;
	while (cin >> n) {

		while (n > 0) {
			cin >> randnum;

			if (myset.count(randnum) == 0) {
				myset.insert(randnum);
			}

			n--;
		}

	}
	for (auto iter : myset)
		cout << iter << endl;

	return 0;
}
#endif