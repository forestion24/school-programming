#include <bits/stdc++.h>
using namespace std;

long long dlu1[100002];
long long dlu2[100002];
vector <pair<long long, long long>> graf1[100002];
vector <pair<long long, long long>> graf2[100002];
priority_queue <pair<long long, long long>> q;

void dij(int wierz, long long dlu[], vector<pair<long long, long long>> graf[]) {
    dlu[wierz] = 0;
    q.push({-dlu[wierz], wierz});

    while (!q.empty()) {
        int dlugosc = -q.top().first;
        int wierzcholek = q.top().second;

        q.pop();

        if (dlu[wierzcholek] <= dlugosc) {
            continue;
        }

        for (int i = 0; i < graf[wierzcholek].size(); i++) {
            int sasiad = graf[wierzcholek][i].second;
            int odl = graf[wierzcholek][i].first;

            if (dlu[sasiad] > dlu[wierzcholek]+odl) {
                q.push({-dlu[sasiad], sasiad});
            }            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        graf1[a].push_back({c, b});
        graf2[b].push_back({c, a});
    }

    for (int i = 0; i <= n; i++) {
        dlu1[i] = 2000000000000000000;
        dlu2[i] = 2000000000000000000;
    }

    dij(1, dlu1, graf1);
    dij(n, dlu2, graf2);

    if (dlu1[n] == 2000000000000000000) {
        cout << -1;
        return 0;
    }

    

    return 0;
}