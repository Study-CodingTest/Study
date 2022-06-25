#include <iostream>
#include<string>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
bool flag[101][101];
int counter[101][101];
char arr[101][101];
int n, m;
int mir;
int start[2];
int dest[2];
bool findStart;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				if (!findStart) {
					start[0] = i;
					start[1] = j;
					findStart = true;
				}
				else {
					dest[0] = i;
					dest[1] = j;
				}
			}
		}
	}
	priority_queue<tuple<int, int, int,int>, vector<tuple<int, int, int,int>>, greater<tuple<int, int, int,int>>> pq;
	pq.push({ 0,start[0],start[1],-1 });
	while (!pq.empty()) {
		int a = get<0>(pq.top());
		int b = get<1>(pq.top());
		int c = get<2>(pq.top());
		int d = get<3>(pq.top());
		pq.pop();
		if (flag[b][c]&&counter[b][c]<a) {
			continue; 
		}
		flag[b][c] = true;
		counter[b][c] = a;
		for (int i = 0; i < 4; i++) {
			int x = b+dx[i];
			int y = c + dy[i];
			if (x<1 || y<1 || x>n || y>m||arr[x][y]=='*')continue;
			if (d == -1) {
				pq.push({ a,x,y,i });
			}
			else {
				if (d == i) {
					pq.push({ a,x,y,i });
				}
				else {
					pq.push({ a+1,x,y,i });
				}
			}
		}
	}
	cout << counter[dest[0]][dest[1]];
}