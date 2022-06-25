#include <iostream>
#include <vector>

using namespace std;

int getIndex(const char& letter) {
	switch (letter) {
		case 'q': 
			return 0;
		case 'u':
			return 1;
		case 'a':
			return 2;
		case 'c':
			return 3;
		case 'k':
			return 4;
		default:
			return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;
	
	bool flag = true;
	vector<int> count(5);
	for (auto letter : input) {
		const int idx = getIndex(letter);

		if (idx != 0 && count[idx - 1] == 0) {
			flag = false;
			break;
		}

		if (idx == 0 && count[4] != 0) {
			count[4]--;
		}

		if (idx != 0) {
			count[idx - 1]--;
		}
		count[idx]++;
	}
	
	for (int i = 0; i < 4; i++) {
		if (count[i] != 0) {
			flag = false;
			break;
		}
	}
	cout << (flag ? count[4] : -1);

	return 0;
}
