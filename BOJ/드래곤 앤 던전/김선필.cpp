#include <iostream>

using namespace std;

#define MONSTER 1
#define POTION 2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long H;
	cin >> N >> H;

	int t, a, h;
	long long hit = 0, answer = 0;
	while (N--) {
		cin >> t >> a >> h;

		if (t == MONSTER) {
			const long long damage = (long long)((h - 1) / H) * a;
			hit -= damage;
			answer = max(answer, -hit);
		}
		else if (t == POTION) {
			H += a;
			hit = min(0ll, hit + h);
		}
	}

	cout << answer + 1;

	return 0;
}