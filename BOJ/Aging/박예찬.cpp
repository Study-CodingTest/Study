#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int main() {
	int n;
	cin >> n;

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;//시점,초기우선,실행시간
		pq.push({ x,-(-x + y),z,i });
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2;
	int counter = 0;
	int curTime = get<0>(pq.top());
	while (counter < n)
	{
		while (!pq.empty() && get<0>(pq.top()) <= curTime) {
			pq2.push({ get<1>(pq.top()),get<2>(pq.top()),get<3>(pq.top()) });
			pq.pop();
		}
		if (!pq2.empty()) {
			cout << get<2>(pq2.top()) << ' ';
			curTime += get<1>(pq2.top());
			pq2.pop();
			counter++;
		}
	}


}