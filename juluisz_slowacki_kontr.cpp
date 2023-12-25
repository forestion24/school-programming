#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int t = 1;
int preor[1000001];
int postor[1000001];
int jump[1000001][21];
vector<int> graf[1000001];

bool czyaPrzodb(int a, int b) {
    if (preor[a] <= preor[b] && postor[a] >= postor[b]) {
        return true;
    }
    return false;
}

int up(int a, int x) {
    int i = 0;
    while (x > 0) {
        if (x % 2) {
            a = jump[a][i];
        }
        i++;
        x/=2;
    }
    return a;
}

void dfs(int x) {
    preor[x] = t;
    t++;
    for (int i = 0; i < graf[x].size(); i++) {
        if (preor[graf[x][i]] == 0) {
            dfs(graf[x][i]);
            jump[graf[x][i]][0] = x;
        }
    }
    postor[x] = t;
    t++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, z;
    cin >> n >> k >> z;

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    jump[k][0] = k;
    dfs(k);

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            jump[j][i] = jump[jump[j][i-1]][i-1];
        }
    }

    int poc, kon, s;
    for (int i = 0; i < z; i++) {
        cin >> a >> b;
        poc = 0;
        kon = 1000000;

        while (poc < kon) {
            s = (poc+kon)/2;
            if (czyaPrzodb(up(a, s), b)) {
                kon = s;
            } else {
                poc = s+1;
            }
        }
        cout << up(a,poc) << '\n';
    }

    return 0;
}