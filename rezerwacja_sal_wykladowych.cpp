#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[30001];
    vector <int> wyklady[30001];

    int n;
    cin >> n;

    int p, k;
    for (int i = 0; i < n; i++) {
        cin >> p >> k;
        wyklady[k].push_back(p);
    }

    dp[0] = 0;

    for (int i = 1; i <= 30000; i++) {
        dp[i] = dp[i-1];
        for (int j = 0; j < wyklady[i].size(); j++) {
            dp[i] = max(dp[i], i-wyklady[i][j]+dp[wyklady[i][j]]);
        }
    }

    cout << dp[30000];

    return 0;
}