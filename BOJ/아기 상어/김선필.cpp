#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int NONE = -1;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct Node {

    int cost;
    int row;
    int col;

    Node(int cost, int row, int col) : cost(cost), row(row), col(col) {}

};

bool compare(const Node &a, const Node &b) {
    if (a.cost == b.cost) {
        if (a.row == b.row) {
            return a.col < b.col;
        }
        return a.row < b.row;
    }
    return a.cost < b.cost;
}

Node bfs(const vector<vector<int>> &fishes, const Node &shark, const int &sharkSize) {
    Node prey(INF, NONE, NONE);

    int minCost = INF;
    const int &N = fishes.size();
    vector<vector<bool>> visit(N, vector<bool>(N));
    visit[shark.row][shark.col] = true;

    queue<Node> q;
    q.push(shark);
    while (!q.empty()) {
        const Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            const Node next = Node(cur.cost + 1, cur.row + dr[i], cur.col + dc[i]);

            if (next.row < 0 || next.col < 0 || next.row >= N || next.col >= N) {
                continue;
            }
            if (visit[next.row][next.col] || next.cost > minCost) {
                continue;
            }

            const int &fishSize = fishes[next.row][next.col];
            if (fishSize > sharkSize) {
                continue;
            }
            visit[next.row][next.col] = true;

            if (fishSize == 0 || fishSize == sharkSize) {
                q.push(next);
            } else if (fishes[next.row][next.col] < sharkSize && compare(next, prey)) {
                prey = next;
                minCost = min(minCost, next.cost);
            }
        }
    }

    return prey;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Node shark(0, NONE, NONE);
    vector<vector<int>> fishes(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> fishes[i][j];
            if (fishes[i][j] == 9) {
                fishes[i][j] = 0;
                shark.row = i;
                shark.col = j;
            }
        }
    }

    int sharkSize = 2;
    int move = 0;
    int eaten = 0;
    while (true) {
        const Node prey = bfs(fishes, shark, sharkSize);
        if (prey.row == NONE) {
            break;
        }

        move += prey.cost;
        fishes[prey.row][prey.col] = 0;
        shark.row = prey.row;
        shark.col = prey.col;

        if (++eaten == sharkSize) {
            sharkSize++;
            eaten = 0;
        }
    }

    cout << move;

    return 0;
}
