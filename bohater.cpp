#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <pair<int, pair<int, int> > > wzrostHp;
    vector <pair<int,pair<int, int> > > wzrostDmg;

    long long n, z;
    cin >> n >> z;

    long long a, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        if (a - d < 0) {
            wzrostHp.push_back(make_pair(a, make_pair(d, i)));
        } else {
            wzrostDmg.push_back(make_pair(-d, make_pair(a, i)));
        }
    }

    sort(wzrostHp.begin(), wzrostHp.end());
    sort(wzrostDmg.begin(), wzrostDmg.end());

    for (int i = 0; i < wzrostHp.size(); i++) {
        if (z - wzrostHp[i].first <= 0) {
            cout << "NIE";
            return 0;
        }
        z -= wzrostHp[i].first;
        z += wzrostHp[i].second.first;
    }

    for (int i = 0; i < wzrostDmg.size(); i++) {
        if (z - wzrostDmg[i].second.first <= 0) {
            cout << "NIE";
            return 0;
        }
        z -= wzrostDmg[i].second.first;
        z -= wzrostDmg[i].first;
    }

    cout << "TAK" << '\n';

    for (int i = 0; i < wzrostHp.size(); i++) {
        cout << wzrostHp[i].second.second+1 << " ";
    }

    for (int i = 0; i < wzrostDmg.size(); i++) {
        cout << wzrostDmg[i].second.second+1 << " ";
    }

    return 0;
}