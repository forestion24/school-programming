#include <bits/stdc++.h>
using namespace std;

int wysokosci[500001];
int przod[500001];
int tyl[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> wysokosci[i];
    }

    przod[0] = 1;

    for (int i = 1; i < n; i++) {
        if (wysokosci[i] > przod[i-1]) {
            przod[i] = przod[i-1]+1;
        } else {
            przod[i] = wysokosci[i];
        }
    }

    tyl[n-1] = 1;

    for (int i = n-2; i >= 0; i--) {
        if (wysokosci[i] > tyl[i+1]) {
            tyl[i] = tyl[i+1]+1;
        } else {
            tyl[i] = wysokosci[i];
        }
    }

    int wyn = 0;
    for (int i = 0; i < n; i++) {
        wyn = max(wyn, min(przod[i], tyl[i]));
    }

    cout << wyn;

    return 0;
}