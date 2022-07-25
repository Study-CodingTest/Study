//
// Created by Kim So Hee on 2022/07/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> inputs(n + 1);
    for (int i = 1; i <= n; ++i) {
        int number;
        cin >> number;
        inputs[i] = inputs[i - 1] + number;
    }
    int start = 0, end = 1, answer;
    answer = 987654321;
    while (start <= n && end <= n) {
        int sub = inputs[end] - inputs[start] - s;
        if (sub >= 0) {
            answer = min(answer, end - start);
            if (end - start == 1) end++;
            else start++;
        } else if (sub < 0) {
            end++;
        }
    }
    cout << (answer == 987654321 ? 0 : answer);
}