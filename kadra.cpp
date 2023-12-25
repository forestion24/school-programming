#include <bits/stdc++.h>
using namespace std;

int lid[500001];
int t2[500001];

int find(int x) {
    if (lid[x] == x) {
        return x;
    } else {
        return lid[x] = find(lid[x]);
    }
}

void unia(int x, int y) {
    x = find(x);
    y = find(y);

    t2[x] = t2[x] || t2[y];
    lid[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long suma = 0;
    long long wyn = 0;

    vector <pair<int, pair<int, int>>> t;

    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        
        suma += a;
        t.push_back({a,{b,c}});

        lid[b] = b;
        lid[c] = c;
    }

    sort(t.begin(), t.end(), greater<pair<int,pair<int,int>>>());

    for (int i = 0; i < t.size(); i++) {
        int a = find(t[i].second.first);
        int b = find(t[i].second.second);

        if (!t2[a] || !t2[b]) {
            wyn += t[i].first;
            if (a == b) {
                t2[a] = true;
            } else {
                unia(a, b);
            }
        }
    }

    cout << suma-wyn;

    return 0;
}