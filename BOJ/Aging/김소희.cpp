//
// Created by Kim So Hee on 2022/07/08.
//

#include <bits/stdc++.h>

using namespace std;

int N;

struct Process {
    int time; // 요청 시점
    int priority; // 우선 순위
    int execution; // 실행 시간
    int number; // 번호
};

struct comp {
    bool operator()(const Process p1, const Process p2) {
        if (p1.time != p2.time) return p1.time > p2.time;
        if (p1.priority != p2.priority) return p1.priority < p2.priority;
        if (p1.execution != p2.execution) return p1.execution > p2.execution;
        return p1.number > p2.number;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<Process, vector<Process>, comp> pq, ready;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t, p, b;
        cin >> t >> p >> b;
        pq.push({t, p, b, i});
    }

    int time = pq.top().time;
    ready.push(pq.top());
    pq.pop();

    /**
     * 1. ready에 있는 프로세스를 하나 실행하고(출력), time에 execution을 더한다
     * 2. time 까지, pq에 있는 프로세스들을 ready에 집어 넣는다
     *  - pq가 비워지면, ready를 모두 출력하고 main 문을 종료한다
     * 3. 프로세스가 실행 완료 되면, ready에 있는 프로세스를 하나 뽑는다
     */
    while (!ready.empty()) {
        auto execute = ready.top();
        ready.pop();
        time += execute.execution;
        cout << execute.number << ' ';

        while (!pq.empty() && pq.top().time <= time) {
            auto here = pq.top();
            pq.pop();
            here.priority -= here.time;
            here.time = 0;
            ready.push(here);
        }
    }
}