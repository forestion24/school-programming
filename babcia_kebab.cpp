#include<iostream>
using namespace std;

int dp[5001][5001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    string b;
    string odp="";

    cin >> a >> b;

    for(int i = 1; i <= b.size(); i++) {
        for(int j = 1; j <= a.size(); j++) {
            if(a[j-1] == b[i-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ile = 0;
    int dlua = a.size();
    int dlub = b.size();
    cout << dp[dlub][dlua] << endl;

    while(dlub > 0) {
        while(dlua > 0) {
            if(dp[dlub][dlua] > dp[dlub][dlua-1]) {
                break;
            }
            dlua--;
        }

        if(dp[dlub][dlua] > dp[dlub][dlua-1] && dp[dlub][dlua] > dp[dlub-1][dlua]) {
            odp += a[dlua-1];
            dlua--;
            dlub--;
            continue;
        }
        dlub--;
    }

    for (int i = odp.size()-1; i >= 0; i--) {
        cout << odp[i];
    }

    return 0;
}