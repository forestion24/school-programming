#include <iostream>
using namespace std;

const int ileLisci = 524288;

int drzewo[ileLisci*2];

int sumaPrzedz(int nrWierz, int pSzuk, int kSzuk, int pWierz, int kWierz) {
    if (pSzuk <= pWierz && kSzuk >= kWierz) {
        return drzewo[nrWierz];
    } else if (kSzuk < pWierz || kWierz < pSzuk) {
        return 0;
    } else {
        return sumaPrzedz(nrWierz*2, pSzuk, kSzuk, pWierz, (pWierz + kWierz)/2) + sumaPrzedz(nrWierz*2+1, pSzuk, kSzuk, (pWierz + kWierz)/2+1, kWierz);
    }
}

int ilePLewo(int x) {
    return sumaPrzedz(1, 0, x-1, 0, ileLisci-1);
}

int ileKPrawo(int x, int n) {
    return (n-x-1) - sumaPrzedz(1, x+1, n-1, 0, ileLisci-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    long long wyn = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 'P') {
            drzewo[i+ileLisci] = 1;
        } else {
            drzewo[i+ileLisci] = 0;
        }
    }

    for (int i = ileLisci-1; i > 0; i--) { 
        drzewo[i] = drzewo[i*2] + drzewo[i*2+1];
    }

    int ileP = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'P') {
            ileP++;
        } else {
            wyn += ileP;
        }
    }

    cout << wyn << '\n';

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        x--;

        if (drzewo[x+ileLisci] == 1) { //P
            wyn -= ileKPrawo(x, n);
            wyn += ilePLewo(x);
        } else {
            wyn -= ilePLewo(x);
            wyn += ileKPrawo(x, n);
        }

        cout << wyn << '\n';

        drzewo[x+ileLisci] = 1-drzewo[x+ileLisci];
        x += ileLisci;
        x /= 2;

        while (x > 0) {
            drzewo[x] = drzewo[x*2] + drzewo[x*2+1];
            x /= 2;
        }
    }

    return 0;
}