#include <iostream>
#include<string>
#include<queue>
using namespace std;
int price[10];
int n, m;
int r[51];
int minPrice=50;
int minIndex;
int minPrice2 = 50;
int minIndex2;
int idx;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
		if (i > 0&& price[i] <= minPrice) {
			minPrice = price[i];
			minIndex = i;
		}
		if(price[i] <= minPrice2) {
			minPrice2 = price[i];
			minIndex2 = i;
		}
	}
	cin >> m;
	if (m < minPrice) {
		cout << '0';
		return 0;
	}
	r[0] = minIndex;
	m -= minPrice;
	idx++;
	while (m >= minPrice2) {
		m -= minPrice2;
		r[idx] = minIndex2;
		idx++;
	}
	for (int i = 0; i < idx;i++) {
		for (int j = n-1; j >r[i]; j--) {				
			if (m + price[r[i]]-price[j]>=0) {		
				m += price[r[i]];
				m -= price[j];
				r[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < idx; i++) { cout << r[i]; }
}