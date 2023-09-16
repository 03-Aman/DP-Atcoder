#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> happiness;
vector<vector<int>> memo;

int solve(int day, int activity) {
    if (day == n) {
        return 0;
    }

    if (memo[day][activity] != -1) {
        return memo[day][activity];
    }

    int max_happiness = 0;

    for (int i = 0; i < 3; i++) {
        if (i != activity) {
            max_happiness = max(max_happiness, happiness[day][i] + solve(day + 1, i));
        }
    }

    memo[day][activity] = max_happiness;
    return max_happiness;
}

int main() {
    cin >> n;
    happiness.resize(n, vector<int>(3));
    memo.resize(n, vector<int>(3, -1));

    for (int i = 0; i < n; i++) {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }

    int max_happiness = 0;

    for (int i = 0; i < 3; i++) {
        max_happiness = max(max_happiness, happiness[0][i] + solve(1, i));
    }

    cout << max_happiness << endl;
    return 0;
}
