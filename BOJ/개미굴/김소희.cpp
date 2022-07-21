//
// Created by Kim So Hee on 2022/07/14.
//

#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<string>> inputs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    inputs.resize(N);

    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string t;
            cin >> t;
            inputs[i].push_back(t);
        }
    }

    sort(inputs.begin(), inputs.end());

    /**
     * 출력 부분
     *  - 한 floor을 출력할 때 item의 index만큼 indent를 증가시킨다
     *  - 출력 완료된 floor는 변수에 저장한다
     *  - 새로운 floor을 출력할 때, 이전 변수에 저장된 floor의 item과 같으면 skip한다.
     *      - item이 다르다면 flag를 설정하고, 그 이후로 모두 출력한다.
     */
    vector<string> prev;
    for (const auto &floor: inputs) {
        bool prevCheck = true;
        for (int i = 0; i < floor.size(); ++i) {
            if (prevCheck && i < prev.size()) {
                if (prev[i] == floor[i]) continue;
                if (prev[i] != floor[i]) prevCheck = false;
            }

            cout << string(i * 2, '-') << floor[i] << '\n';
        }
        prev = floor;
    }
}
