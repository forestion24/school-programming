#include<bits/stdc++.h>
using namespace std;

long long gielda[200002];
int dp[200002];
priority_queue <pair<long long, int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> gielda[i];
    }

    q.push({-gielda[1], 1});
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        long long wart = q.top().first * -1;
        int aktI = q.top().second;
        q.push({-gielda[i], i});
        if (wart < gielda[i]){
            dp[aktI] += 1;
            dp[i] = -1;
            if (dp[aktI] == 1){
                q.pop();
            }
        }
    }

    long long wyn = 0;

    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) {
            wyn -= gielda[i];
        } else if(dp[i] == -1) {
            wyn += gielda[i];
        }
    }

    cout << wyn << '\n';
    for (int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }


}