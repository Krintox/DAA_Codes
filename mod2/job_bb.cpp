#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int level;
    int profit;
    int bound;
};

bool cmp(const Node& a, const Node& b) {
    return a.bound < b.bound;
}

int jobSelection(int n, vector<int> d, vector<int> p) {
    queue<Node> fifo;
    Node u, v;
    vector<int> include(n);
    int maxProfit = 0;

    v.level = -1;
    v.profit = 0;

    fifo.push(v);

    while (!fifo.empty()) {
        v = fifo.front();
        fifo.pop();

        if (v.level == -1) {
            u.level = 0;
        } else if (v.level == n-1) {
            continue;
        } else {
            u.level = v.level + 1;
        }

        u.profit = v.profit + p[u.level];

        if (u.profit > maxProfit) {
            maxProfit = u.profit;
        }

        u.bound = computeBound(u, n, d, p);

        if (u.bound > maxProfit) {
            fifo.push(u);
        }

        u.profit = v.profit;

        u.bound = computeBound(u, n, d, p);

        if (u.bound > maxProfit) {
            fifo.push(u);
        }
    }

    return maxProfit;
}

int computeBound(Node u, int n, vector<int> d, vector<int> p) {
    if (u.level >= n) {
        return 0;
    }

    int j = u.level + 1;
    int totalProfit = u.profit;

    while (j < n && d[j] <= d[u.level]) {
        totalProfit += p[j];
        j++;
    }

    if (j < n) {
        totalProfit += (d[u.level] - d[j]) * (float)p[j] / (d[j] - d[j-1]);
    }

    return totalProfit;
}

int main() {
    int n = 4;
    vector<int> d {2, 1, 2, 1};
    vector<int> p {100, 19, 27, 25};
    int maxProfit = jobSelection(n, d, p);
    cout << "Max profit: " << maxProfit << endl;
    return 0;
}