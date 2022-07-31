//
// Created by Kim So Hee on 2022/07/31.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, h;
    cin >> n >> h;

    vector<int> bottom, upper;


    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (i % 2 == 0) {
            bottom.push_back(c);
        } else {
            upper.push_back(c);
        }

    }
    std::sort(bottom.begin(), bottom.end());
    std::sort(upper.begin(), upper.end());
    map<int, int> answer;


    /**
     * 1. 이분 탐색 : O(H logN)
     * 2. 횟수 누적 합 : O(H)
     *   - https://www.acmicpc.net/source/46861045
     */
    for (int H = 1; H <= h; H++) {

        int upperCount = upper.end() - std::upper_bound(upper.begin(), upper.end(), h - H );
        int bottomCount = bottom.end() - std::lower_bound(bottom.begin(), bottom.end(), H);
        int insertMap = upperCount + bottomCount;

        if (answer.find(insertMap) != answer.end()) answer[insertMap]++;
        else answer[insertMap] = 1;
    }

    auto iter = answer.begin();
    cout << iter->first << ' ' << iter->second;

}