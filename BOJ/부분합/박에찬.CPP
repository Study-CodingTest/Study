#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
int n,s;
int arr[100001];
int minLength;
int minValue;
int sum, counter;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	int leftIdx=1;
	int rightIdx = 1;
	sum =arr[1];
	minLength = n + 1;
	while (rightIdx<=n&&rightIdx>=leftIdx) {	
		//cout << sum << endl;
		if (sum >= s) {
			minLength = min(minLength, rightIdx - leftIdx+1);
			sum -= arr[leftIdx];
			leftIdx++;
		}
		else {
			rightIdx++;
			sum += arr[rightIdx];
			
		}
	}
	if (minLength == n + 1)minLength = 0;
	cout << minLength;
}