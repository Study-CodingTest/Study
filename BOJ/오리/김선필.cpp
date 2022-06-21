#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;

	list<char> records;
	for (char i : input) {
		records.push_back(i);
	}

	const string ORDER = "quack";
	const int LAST = 5;

	int idx = 0;
	int ducks = 0;
	bool flag = true;
	int last_size = records.size();

	while (!records.empty()) {
		auto iter = records.begin();

		while (iter != records.end()) {
			if (*iter != ORDER[idx]) {
				++iter;
				continue;
			}

			iter = records.erase(iter);
			idx++;

			if (idx == LAST) {
				idx = 0;
			}
		}

		// exception handling
		if (idx != 0 || last_size == records.size()) {
			flag = false;
			break;
		}

		ducks++;
		last_size = records.size();
	}

	cout << (flag ? ducks : -1);

	return 0;
}