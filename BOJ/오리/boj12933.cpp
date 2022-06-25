#include <iostream>
#include<string>
using namespace std;
int duck;
int counter;
string s;
int q, u, a, c, k;
char cur='q';
bool flag[2500];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	if (s.length() % 5 != 0) {
		cout << -1;
		return 0;
	}
	if (s[s.length() - 1] != 'k') {
		cout << -1;
		return 0;
	}
	if (s[0] != 'q') {
		cout << -1;
		return 0;
	}
	while (counter < s.length()) {
		for (int i = 0; i < s.length(); i++) {
			if (flag[i])continue;
			if (cur == 'q'&&s[i]=='q') {
				flag[i] = true;
				counter++;
				cur = 'u';
			}
			if (cur == 'u' && s[i] == 'u') {
				flag[i] = true;
				counter++;
				cur = 'a';
			}
			if (cur == 'a' && s[i] == 'a') {
				flag[i] = true;
				counter++;
				cur = 'c';
			}
			if (cur == 'c' && s[i] == 'c') {
				flag[i] = true;
				counter++;
				cur = 'k';
			}
			if (cur == 'k' && s[i] == 'k') {
				flag[i] = true;
				counter++;
				cur = 'q';
			}
		}
		if (cur != 'q') { cout << -1;
		return 0;
		}
		duck++;
	}
	cout << duck;
}