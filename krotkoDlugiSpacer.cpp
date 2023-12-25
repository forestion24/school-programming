#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

vector <pair<int,int>> graf[1000001];
long long odl[1000001];
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c % 2) {
            graf[a].push_back({b+n, c});
            graf[b+n].push_back({a, c});
            graf[a+n].push_back({b, c});
            graf[b].push_back({a+n, c});
        } else {
            graf[a].push_back({b, c});
            graf[b].push_back({a, c});
            graf[a+n].push_back({b+n, c});
            graf[b+n].push_back({a+n, c});
        }
        
    }

    for (int i = 0; i < 1000001; i++) {
        odl[i] = inf;
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;

    q.push({0, 1});

    while (!q.empty()) {
        int x = q.top().second;
        long long dl = q.top().first;
        q.pop();

        if (odl[x] != inf) {
            continue;
        }

        odl[x] = dl;

        for (int i = 0; i < graf[x].size(); i++) {
            if (odl[graf[x][i].first] == inf) {
                q.push({dl+graf[x][i].second, graf[x][i].first});
            }
        }
    }
    
    long long wyn = 0;
    vector <int> cele;
    for (int i = 1; i <= n; i++) {
        if (odl[i] + odl[i+n] >= inf) {
            continue;
        } else if (wyn < odl[i] + odl[i+n]) {
            wyn = odl[i] + odl[i+n];
            cele.clear();
            cele.push_back(i);
        } else if (wyn == odl[i] + odl[i+n]) {
            cele.push_back(i);
        }
    }

    if (wyn == 0) {
        cout << "BRAK";
    } else {
        for (int i = 0; i < cele.size(); i++) {
            cout << cele[i] << " ";
        }
        cout << '\n';
        cout << wyn << '\n';
    }

    return 0;
}