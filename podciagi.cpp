#include <bits/stdc++.h>
using namespace std;

int liczby[1000002];
int pom[1000002];
long long dp[500002];   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 1000002; i++) {
        pom[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> liczby[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = 2*dp[i-1] + 1000000007;

        if (pom[liczby[i-1]] != -1) {
            dp[i]-=dp[pom[liczby[i-1]]];
        }

        dp[i] %= 1000000007;
        pom[liczby[i-1]] = i-1;
    }

    cout << dp[n]%1000000007;

}