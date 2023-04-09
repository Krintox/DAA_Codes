#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

bool cmp(const Node& a, const Node& b) {
    return a.bound > b.bound;
}

int knapsack(int n, int W, vector<int> w, vector<int> p) {
    stack<Node> lifo;
    Node u, v;
    vector<int> include(n);
    int maxProfit = 0;

    v.level = -1;
    v.profit = 0;
    v.weight = 0;

    lifo.push(v);

    while (!lifo.empty()) {
        v = lifo.top();
        lifo.pop();

        if (v.level == -1) {
            u.level = 0;
        } else if (v.level == n-1) {
            continue;
        } else {
            u.level = v.level + 1;
        }

        u.weight = v.weight + w[u.level];
        u.profit = v.profit + p[u.level];

        if (u.weight <= W && u.profit > maxProfit) {
            maxProfit = u.profit;
        }

        u.bound = computeBound(u, n, W, w, p);

        if (u.bound > maxProfit) {
            lifo.push(u);
        }

        u.weight = v.weight;
        u.profit = v.profit;

        u.bound = computeBound(u, n, W, w, p);

        if (u.bound > maxProfit) {
            lifo.push(u);
        }
    }

    return maxProfit;
}

float computeBound(Node u, int n, int W, vector<int> w, vector<int> p) {
    if (u.weight >= W) {
        return 0;
    }

    float bound = u.profit;

    int j = u.level + 1;
    int totWeight = u.weight;

    while (j < n && totWeight + w[j] <= W) {
        totWeight += w[j];
        bound += p[j];
        j++;
    }

    if (j < n) {
        bound += (W - totWeight) * (float)p[j] / w[j];
    }

    return bound;
}

int main() {
    int n = 4;
    int W = 10;
    vector<int> w {5, 4, 6, 3};
    vector<int> p {10, 40, 30, 50};
    int maxProfit = knapsack(n, W, w, p);
    cout << "Max profit: " << maxProfit << endl;
    return 0;
}