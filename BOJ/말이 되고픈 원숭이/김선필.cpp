#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int WALL = 1;
const int dr[] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dc[] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};

struct Node {

    int row;
    int col;
    int k;
    int cost;

    Node(int row, int col, int k, int cost) : row(row), col(col), k(k), cost(cost) {}

};

int bfs(const vector<vector<int>> &map, const int &K, const Node src) {
    const int &H = map.size();
    const int &W = map[0].size();

    vector<vector<vector<bool>>> visit(H, vector<vector<bool>>(W, vector<bool>(K + 1)));
    fill(visit[src.row][src.col].begin(), visit[src.row][src.col].end(), true);

    queue<Node> q;
    q.push(src);

    while (!q.empty()) {
        const Node cur = q.front();
        q.pop();

        if (cur.row == H - 1 && cur.col == W - 1) {
            return cur.cost;
        }

        for (int i = 0; (i < 4) || (cur.k && i < 12); i++) {
            const Node next(cur.row + dr[i], cur.col + dc[i], cur.k - (i < 4 ? 0 : 1), cur.cost + 1);

            if (next.row < 0 || next.col < 0 || next.row >= H || next.col >= W) {
                continue;
            }
            if (map[next.row][next.col] == WALL) {
                continue;
            }
            if (visit[next.row][next.col][next.k]) {
                continue;
            }

            visit[next.row][next.col][next.k] = true;
            q.push(next);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, W, H;
    cin >> K >> W >> H;

    vector<vector<int>> map(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }

    Node src(0, 0, K, 0);
    cout << bfs(map, K, src);

    return 0;
}
