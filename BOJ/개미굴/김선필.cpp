#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {

    map<string, Node *> children;

    void insert(const vector<string> &foods, int index) {
        if (foods.size() == index) {
            return;
        }

        const string &food = foods[index];
        if (children.find(food) == children.end()) {
            children[food] = new Node();
        }
        children[food]->insert(foods, index + 1);
    }

    void print(int depth) {
        for (auto &child: children) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << child.first << '\n';
            child.second->print(depth + 1);
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Node *root = new Node();
    while (N--) {
        int K;
        cin >> K;

        vector<string> foods(K);
        for (int i = 0; i < K; i++) {
            cin >> foods[i];
        }

        root->insert(foods, 0);
    }

    root->print(0);

    return 0;
}
