#include<bits/stdc++.h>
using namespace std;

int maxOdl = 0;
int wierz;

vector <int> miasta[1000002];
bool fabryki[1000002];

void dfs(int x, int skad, int odl) {
    if (odl > maxOdl && fabryki[x]) {
        maxOdl = odl;
        wierz = x;
    }

    for (int i = 0; i < miasta[x].size(); i++) {
        if (miasta[x][i] != skad) {
            dfs(miasta[x][i], x, odl+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        miasta[a].push_back(b);
        miasta[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        cin >> a;
        fabryki[a] = 1;
    }

    dfs(1, 0, 0);

    maxOdl = 0;

    dfs(wierz, 0, 0);

    cout << maxOdl;

    return 0;
}