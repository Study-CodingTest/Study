#include <iostream>
#include<string>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
long long  n, atk, curHp, curRoom, curAtk;
long long inf = 9000000000000000000;
vector<tuple<int, int, int>> v;
void battle(int cur) {
	long long enemyHp = get<2>(v[cur]);
	long long enemyAtk = get<1>(v[cur]);
	long long turn = enemyHp / curAtk;
	if (enemyHp % curAtk == 0)turn--;

	curHp -= (turn * enemyAtk);
}
void potion(int cur) {
	curAtk += get<1>(v[cur]);
	curHp += get<2>(v[cur]);
}
bool check(long long Hp) {
	curRoom = 0;
	curAtk = atk;
	curHp = Hp;
	while (curRoom != n) {	
		if (get<0>(v[curRoom]) == 1) {
			battle(curRoom);
		}
		else {
			potion(curRoom);
			if (curHp >= Hp)curHp = Hp;
		}
		if (curHp <= 0)
			return false;
		curRoom++;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> atk;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ x,y,z });
	}
	long long s = 0;
	long long e = inf;
	while (s <= e) {
		long long mid = (s + e) / 2;
		if (check(mid)) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << s;
}