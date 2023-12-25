#include <bits/stdc++.h>
using namespace std;

struct mal{
    int v;
    int moc;
    int kolor;
};

vector <int> wierz[100002];
stack <mal> stos;
int kolory[100002];
int moce[100002];


void dfs (int v, int moc, int kolor) {
    if (kolory[v] == 0) {
        kolory[v] = kolor;
    }
    
    moce[v] = moc;

    for (int i = 0; i < wierz[v].size(); i++) {
        if (moce[wierz[v][i]] < moc-1) {
            dfs(wierz[v][i], moc-1, kolor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 100002; i++) {
        moce[i] = -1;
    }

    int n, m;
    cin >> n >> m;
    int q;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        wierz[a].push_back(b);
        wierz[b].push_back(a);
    }

    cin >> q;

    mal c;
    for (int i = 0; i < q; i++) {
        cin >> c.v >> c.moc >> c.kolor;
        stos.push(c);
    }

    for (int i = 0; i < q; i++) {
        c = stos.top();
        stos.pop();

        if (moce[c.v] < c.moc) {
            dfs(c.v, c.moc, c.kolor);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << kolory[i] << '\n';
    }

    return 0;
}