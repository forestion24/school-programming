#include <bits/stdc++.h>
using namespace std;

long long dp[5010][5010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string slowo;
    cin >> slowo;

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i+2; j++) {
            if (slowo[j] == slowo[j+i+1]) {
                dp[j][j+i+1] = dp[j+1][j+i+1] + dp[j][j+i] + 1;
                dp[j][j+i+1] %= 1100000017LL;
            } else {
                dp[j][j+i+1] = dp[j+1][j+i+1] + dp[j][j+i] - dp[j+1][j+i] + 1100000017LL;
                dp[j][j+i+1] %= 1100000017LL;
            }
        }
    }

    cout << dp[0][n-1] % 1100000017LL;

    return 0;
}