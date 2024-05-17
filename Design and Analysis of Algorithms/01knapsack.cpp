#include <iostream>
#include <vector>
using namespace std;

int knapsack01DP(vector<int>& weight, vector<int>& value, int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, maxCap;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> maxCap;

    cout << "Maximum value (DP approach): " << knapsack01DP(weight, value, n, maxCap) << endl;

    return 0;
}
